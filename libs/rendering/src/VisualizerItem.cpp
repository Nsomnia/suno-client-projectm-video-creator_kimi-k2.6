#include "aether/rendering/VisualizerItem.h"
#include "aether/rendering/RenderEngine.h"
#include "aether/rendering/PlaceholderRenderer.h"
#include <QPainter>
#include <QTimer>

namespace aether::ui {

VisualizerItem::VisualizerItem(QQuickItem* parent)
    : QQuickPaintedItem(parent)
    , m_engine(std::make_unique<aether::rendering::RenderEngine>())
{
    setRenderTarget(QQuickPaintedItem::FramebufferObject);
    setAntialiasing(true);
    setFlag(QQuickItem::ItemHasContents, true);

    auto renderer = std::make_unique<aether::rendering::PlaceholderRenderer>();
    renderer->setIntensity(m_intensity);
    m_engine->setRenderer(std::move(renderer));

    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() { update(); });
    timer->start(16);
}

VisualizerItem::~VisualizerItem() = default;

void VisualizerItem::paint(QPainter* painter)
{
    if (!m_engine)
        return;

    m_engine->renderFrame(painter, QSize(static_cast<int>(width()), static_cast<int>(height())));
}

qreal VisualizerItem::intensity() const
{
    return m_intensity;
}

void VisualizerItem::setIntensity(qreal value)
{
    if (!qFuzzyCompare(m_intensity, value)) {
        m_intensity = value;
        if (m_engine) {
            m_engine->setIntensity(value);
        }
        emit intensityChanged();
    }
}

} // namespace aether::ui
