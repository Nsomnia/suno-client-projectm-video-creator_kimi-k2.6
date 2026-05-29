#pragma once
#include <QObject>
#include <QString>
#include <memory>
#include <spdlog/spdlog.h>

namespace aether::core {

enum class LogCategory {
    General,
    Rendering,
    Audio,
    Network,
    UI,
    Scripting
};

class Logger {
public:
    static void initialize(const QString& logDir = QString());
    static std::shared_ptr<spdlog::logger> category(LogCategory cat);
    static const char* categoryName(LogCategory cat);
private:
    static bool s_initialized;
    static std::shared_ptr<spdlog::logger> s_loggers[6];
};

#define AE_LOG_INFO(cat, ...)  aether::core::Logger::category(cat)->info(__VA_ARGS__)
#define AE_LOG_WARN(cat, ...)  aether::core::Logger::category(cat)->warn(__VA_ARGS__)
#define AE_LOG_ERROR(cat, ...) aether::core::Logger::category(cat)->error(__VA_ARGS__)
#define AE_LOG_DEBUG(cat, ...) aether::core::Logger::category(cat)->debug(__VA_ARGS__)

// QObject wrapper for QML
class QmlLogger : public QObject {
    Q_OBJECT
public:
    explicit QmlLogger(QObject* parent = nullptr);
    Q_INVOKABLE void info(const QString& msg);
    Q_INVOKABLE void warn(const QString& msg);
    Q_INVOKABLE void error(const QString& msg);
};

} // namespace aether::core
