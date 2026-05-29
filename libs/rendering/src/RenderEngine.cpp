#include "aether/rendering/RenderEngine.h"

namespace aether::rendering {

RenderEngine::RenderEngine(QObject* parent)
    : QObject(parent)
{
    m_timer.start();
}

void RenderEngine::setRenderer(std::unique_ptr<IRenderer> renderer)
{
    if (m_renderer) {
        m_renderer->shutdown();
    }
    m_renderer = std::move(renderer);
    if (m_renderer) {
        m_renderer->initialize();
    }
}

IRenderer* RenderEngine::renderer() const
{
    return m_renderer.get();
}

void RenderEngine::renderFrame(QPainter* painter, const QSize& size)
{
    if (!m_renderer)
        return;

    const qreal elapsed = static_cast<qreal>(m_timer.restart());
    m_renderer->render(painter, size, elapsed);
}

void RenderEngine::setIntensity(qreal intensity)
{
    if (m_renderer) {
        m_renderer->setIntensity(intensity);
    }
}

qreal RenderEngine::intensity() const
{
    if (m_renderer) {
        return m_renderer->intensity();
    }
    return 1.0;
}

} // namespace aether::rendering
