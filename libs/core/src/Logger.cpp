#include "aether/core/Logger.h"

#include <QDir>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace aether::core {

bool Logger::s_initialized = false;
std::shared_ptr<spdlog::logger> Logger::s_loggers[6];

const char* Logger::categoryName(LogCategory cat) {
    switch (cat) {
        case LogCategory::General:   return "General";
        case LogCategory::Rendering: return "Rendering";
        case LogCategory::Audio:     return "Audio";
        case LogCategory::Network:   return "Network";
        case LogCategory::UI:        return "UI";
        case LogCategory::Scripting: return "Scripting";
    }
    return "Unknown";
}

void Logger::initialize(const QString& logDir) {
    if (s_initialized) {
        return;
    }

    std::vector<spdlog::sink_ptr> sinks;

    auto stdoutSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    stdoutSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] %v");
    sinks.push_back(stdoutSink);

    QString dirPath = logDir;
    if (dirPath.isEmpty()) {
        dirPath = QDir::currentPath();
    }
    QDir dir(dirPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QString filePath = dir.filePath("aether.log");

    auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        filePath.toStdString(), 5 * 1024 * 1024, 3);
    fileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%n] %v");
    sinks.push_back(fileSink);

    for (int i = 0; i < 6; ++i) {
        LogCategory cat = static_cast<LogCategory>(i);
        auto logger = std::make_shared<spdlog::logger>(categoryName(cat), sinks.begin(), sinks.end());
        logger->set_level(spdlog::level::debug);
        s_loggers[i] = std::move(logger);
    }

    s_initialized = true;
}

std::shared_ptr<spdlog::logger> Logger::category(LogCategory cat) {
    int idx = static_cast<int>(cat);
    if (idx < 0 || idx >= 6 || !s_initialized) {
        return nullptr;
    }
    return s_loggers[idx];
}

QmlLogger::QmlLogger(QObject* parent) : QObject(parent) {}

void QmlLogger::info(const QString& msg) {
    auto logger = Logger::category(LogCategory::General);
    if (logger) {
        logger->info(msg.toStdString());
    }
}

void QmlLogger::warn(const QString& msg) {
    auto logger = Logger::category(LogCategory::General);
    if (logger) {
        logger->warn(msg.toStdString());
    }
}

void QmlLogger::error(const QString& msg) {
    auto logger = Logger::category(LogCategory::General);
    if (logger) {
        logger->error(msg.toStdString());
    }
}

} // namespace aether::core
