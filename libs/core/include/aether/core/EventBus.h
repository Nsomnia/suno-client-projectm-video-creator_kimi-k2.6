#pragma once
#include <QObject>
#include <functional>
#include <memory>
#include <vector>
#include <typeindex>
#include <QMutex>
#include <QVariantMap>

namespace aether::core {

struct IEvent {
    virtual ~IEvent() = default;
    virtual QString typeName() const = 0;
};

using EventHandler = std::function<void(std::shared_ptr<IEvent>)>;

class EventBus : public QObject {
    Q_OBJECT
public:
    explicit EventBus(QObject* parent = nullptr);
    uint64_t subscribe(const QString& eventType, EventHandler handler);
    template <typename EventT>
    uint64_t subscribe(std::function<void(const EventT&)> handler) {
        QString typeName = EventT::staticTypeName();
        return subscribe(typeName, [handler](std::shared_ptr<IEvent> evt) {
            auto casted = std::dynamic_pointer_cast<EventT>(evt);
            if (casted) handler(*casted);
        });
    }
    void publish(std::shared_ptr<IEvent> event);
    void unsubscribe(uint64_t id);
private:
    struct Subscription {
        uint64_t id;
        QString eventType;
        EventHandler handler;
    };
    mutable QMutex m_mutex;
    std::vector<Subscription> m_subscriptions;
    uint64_t m_nextId{1};
};

} // namespace aether::core
