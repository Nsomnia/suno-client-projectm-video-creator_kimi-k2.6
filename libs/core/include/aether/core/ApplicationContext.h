#pragma once
#include <memory>
#include <QObject>
#include "ServiceRegistry.h"

namespace aether::core {

class Logger;
class ConfigManager;
class EventBus;

class ApplicationContext : public QObject {
    Q_OBJECT
public:
    static ApplicationContext* instance();
    void initialize();
    void shutdown();
    ServiceRegistry* registry() const { return m_registry.get(); }
    Logger* logger() const { return m_logger; }
    ConfigManager* config() const { return m_config; }
    EventBus* eventBus() const { return m_eventBus; }
private:
    explicit ApplicationContext(QObject* parent = nullptr);
    ~ApplicationContext() override;
    std::unique_ptr<ServiceRegistry> m_registry;
    Logger* m_logger{nullptr};
    ConfigManager* m_config{nullptr};
    EventBus* m_eventBus{nullptr};
    static ApplicationContext* s_instance;
};

} // namespace aether::core
