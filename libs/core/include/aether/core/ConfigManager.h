#pragma once
#include <QObject>
#include <QVariant>
#include <QString>
#include <nlohmann/json.hpp>

namespace aether::core {

class ConfigManager : public QObject {
    Q_OBJECT
public:
    explicit ConfigManager(QObject* parent = nullptr);
    bool loadFromFile(const QString& path);
    bool saveToFile(const QString& path) const;
    template <typename T>
    T get(const QString& key, const T& defaultValue) const {
        auto it = m_data.find(key.toStdString());
        if (it == m_data.end()) return defaultValue;
        try { return it->get<T>(); } catch (...) { return defaultValue; }
    }
    template <typename T>
    void set(const QString& key, const T& value) {
        m_data[key.toStdString()] = value;
        emit configChanged(key);
    }
    Q_INVOKABLE QVariant getValue(const QString& key, const QVariant& defaultValue) const;
    Q_INVOKABLE void setValue(const QString& key, const QVariant& value);
    Q_INVOKABLE bool hasKey(const QString& key) const;
    Q_INVOKABLE void clear();
signals:
    void configChanged(const QString& key);
private:
    nlohmann::json m_data;
};

} // namespace aether::core
