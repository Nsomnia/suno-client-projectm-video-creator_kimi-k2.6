#include "aether/core/ApplicationContext.h"
#include "aether/core/Logger.h"
#include "aether/core/ConfigManager.h"
#include "aether/core/EventBus.h"

namespace aether::core {

ApplicationContext* ApplicationContext::s_instance = nullptr;

ApplicationContext* ApplicationContext::instance() {
    if (!s_instance) {
        s_instance = new ApplicationContext();
    }
    return s_instance;
}

ApplicationContext::ApplicationContext(QObject* parent)
    : QObject(parent)
    , m_registry(std::make_unique<ServiceRegistry>())
{
}

ApplicationContext::~ApplicationContext() = default;

void ApplicationContext::initialize() {
    Logger::initialize();

    m_config = new ConfigManager(this);
    m_eventBus = new EventBus(this);

    // ConfigManager and EventBus are owned directly by ApplicationContext
}

void ApplicationContext::shutdown() {
    if (m_registry) {
        m_registry->shutdownAll();
    }
    m_registry.reset();

    delete m_eventBus;
    m_eventBus = nullptr;

    delete m_config;
    m_config = nullptr;

    m_logger = nullptr;
}

} // namespace aether::core
