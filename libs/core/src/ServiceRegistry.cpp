#include "aether/core/ServiceRegistry.h"

namespace aether::core {

void ServiceRegistry::registerService(QString name, std::shared_ptr<IService> service) {
    QMutexLocker locker(&m_mutex);
    m_services.insert(std::move(name), std::move(service));
}

bool ServiceRegistry::hasService(const QString& name) const {
    QMutexLocker locker(&m_mutex);
    return m_services.contains(name);
}

std::shared_ptr<IService> ServiceRegistry::service(const QString& name) const {
    QMutexLocker locker(&m_mutex);
    auto it = m_services.find(name);
    if (it != m_services.end()) {
        return it.value();
    }
    return nullptr;
}

void ServiceRegistry::initializeAll() {
    QMutexLocker locker(&m_mutex);
    for (auto it = m_services.begin(); it != m_services.end(); ++it) {
        it.value()->initialize();
    }
}

void ServiceRegistry::shutdownAll() {
    QMutexLocker locker(&m_mutex);
    for (auto it = m_services.begin(); it != m_services.end(); ++it) {
        it.value()->shutdown();
    }
}

QList<QString> ServiceRegistry::serviceNames() const {
    QMutexLocker locker(&m_mutex);
    QList<QString> names;
    for (auto it = m_services.begin(); it != m_services.end(); ++it) {
        names.append(it.key());
    }
    return names;
}

} // namespace aether::core
