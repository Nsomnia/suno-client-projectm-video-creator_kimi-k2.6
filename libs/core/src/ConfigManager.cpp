#include "aether/core/ConfigManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <string>

namespace aether::core {

namespace {

nlohmann::json variantToJson(const QVariant& value)
{
    if (!value.isValid() || value.isNull()) {
        return nullptr;
    }
    switch (static_cast<int>(value.typeId())) {
    case QMetaType::Bool:
        return value.toBool();
    case QMetaType::Int:
    case QMetaType::Short:
    case QMetaType::Long:
        return value.toInt();
    case QMetaType::UInt:
    case QMetaType::UShort:
    case QMetaType::ULong:
        return value.toUInt();
    case QMetaType::LongLong:
        return value.toLongLong();
    case QMetaType::ULongLong:
        return value.toULongLong();
    case QMetaType::Double:
    case QMetaType::Float:
        return value.toDouble();
    case QMetaType::QString:
        return value.toString().toStdString();
    case QMetaType::QByteArray:
        return value.toByteArray().toStdString();
    case QMetaType::QVariantList: {
        const auto list = value.toList();
        nlohmann::json arr = nlohmann::json::array();
        for (const auto& v : list) {
            arr.push_back(variantToJson(v));
        }
        return arr;
    }
    case QMetaType::QVariantMap: {
        const auto map = value.toMap();
        nlohmann::json obj = nlohmann::json::object();
        for (auto it = map.begin(); it != map.end(); ++it) {
            obj[it.key().toStdString()] = variantToJson(it.value());
        }
        return obj;
    }
    case QMetaType::QVariantHash: {
        const auto hash = value.toHash();
        nlohmann::json obj = nlohmann::json::object();
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            obj[it.key().toStdString()] = variantToJson(it.value());
        }
        return obj;
    }
    default:
        // Attempt string conversion as fallback
        if (value.canConvert<QString>()) {
            return value.toString().toStdString();
        }
        return nullptr;
    }
}

QVariant jsonToVariant(const nlohmann::json& j)
{
    if (j.is_null()) {
        return QVariant();
    }
    if (j.is_boolean()) {
        return QVariant(j.get<bool>());
    }
    if (j.is_number_integer()) {
        return QVariant(static_cast<qlonglong>(j.get<long long>()));
    }
    if (j.is_number_unsigned()) {
        return QVariant(static_cast<qulonglong>(j.get<unsigned long long>()));
    }
    if (j.is_number_float()) {
        return QVariant(j.get<double>());
    }
    if (j.is_string()) {
        return QVariant(QString::fromStdString(j.get<std::string>()));
    }
    if (j.is_array()) {
        QVariantList list;
        for (const auto& item : j) {
            list.append(jsonToVariant(item));
        }
        return QVariant(list);
    }
    if (j.is_object()) {
        QVariantMap map;
        for (auto it = j.begin(); it != j.end(); ++it) {
            map.insert(QString::fromStdString(it.key()), jsonToVariant(it.value()));
        }
        return QVariant(map);
    }
    return QVariant();
}

} // anonymous namespace

ConfigManager::ConfigManager(QObject* parent)
    : QObject(parent)
{
}

bool ConfigManager::loadFromFile(const QString& path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "ConfigManager: failed to open file for reading:" << path;
        return false;
    }
    QByteArray data = file.readAll();
    file.close();

    try {
        m_data = nlohmann::json::parse(data.toStdString());
    } catch (const std::exception& e) {
        qWarning() << "ConfigManager: JSON parse error:" << e.what();
        return false;
    }
    return true;
}

bool ConfigManager::saveToFile(const QString& path) const
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "ConfigManager: failed to open file for writing:" << path;
        return false;
    }
    try {
        std::string dump = m_data.dump(4);
        file.write(QByteArray::fromStdString(dump));
    } catch (const std::exception& e) {
        qWarning() << "ConfigManager: JSON dump error:" << e.what();
        file.close();
        return false;
    }
    file.close();
    return true;
}

QVariant ConfigManager::getValue(const QString& key, const QVariant& defaultValue) const
{
    auto it = m_data.find(key.toStdString());
    if (it == m_data.end()) return defaultValue;
    try {
        return jsonToVariant(*it);
    } catch (...) {
        return defaultValue;
    }
}

void ConfigManager::setValue(const QString& key, const QVariant& value)
{
    m_data[key.toStdString()] = variantToJson(value);
    emit configChanged(key);
}

bool ConfigManager::hasKey(const QString& key) const
{
    return m_data.contains(key.toStdString());
}

void ConfigManager::clear()
{
    m_data.clear();
    emit configChanged(QString());
}

} // namespace aether::core
