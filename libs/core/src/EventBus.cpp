#include "aether/core/EventBus.h"
#include <QMutexLocker>

namespace aether::core {

EventBus::EventBus(QObject* parent)
    : QObject(parent)
{
}

uint64_t EventBus::subscribe(const QString& eventType, EventHandler handler)
{
    QMutexLocker locker(&m_mutex);
    uint64_t id = m_nextId++;
    m_subscriptions.push_back({id, eventType, std::move(handler)});
    return id;
}

void EventBus::publish(std::shared_ptr<IEvent> event)
{
    if (!event) return;
    QString typeName = event->typeName();
    QMutexLocker locker(&m_mutex);
    auto subs = m_subscriptions; // copy under lock
    locker.unlock();
    for (const auto& sub : subs) {
        if (sub.eventType == typeName) {
            sub.handler(event);
        }
    }
}

void EventBus::unsubscribe(uint64_t id)
{
    QMutexLocker locker(&m_mutex);
    auto it = std::remove_if(m_subscriptions.begin(), m_subscriptions.end(),
        [id](const Subscription& sub) { return sub.id == id; });
    m_subscriptions.erase(it, m_subscriptions.end());
}

} // namespace aether::core
