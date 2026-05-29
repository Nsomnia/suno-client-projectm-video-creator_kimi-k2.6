#pragma once
#include <memory>
#include <typeindex>
#include <QMutex>
#include <QMutexLocker>
#include <QHash>
#include <QList>
#include <QString>
#include "IService.h"

namespace aether::core {

class ServiceRegistry {
public:
    void registerService(QString name, std::shared_ptr<IService> service);
    bool hasService(const QString& name) const;
    std::shared_ptr<IService> service(const QString& name) const;
    template <typename T>
    std::shared_ptr<T> service(const QString& name) const {
        auto s = service(name);
        return std::dynamic_pointer_cast<T>(s);
    }
    void initializeAll();
    void shutdownAll();
    QList<QString> serviceNames() const;
private:
    mutable QMutex m_mutex;
    QHash<QString, std::shared_ptr<IService>> m_services;
};

} // namespace aether::core
