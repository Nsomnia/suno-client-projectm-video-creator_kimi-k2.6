#pragma once
#include <memory>
#include <QObject>
#include <QElapsedTimer>
#include "IRenderer.h"

namespace aether::rendering {

class RenderEngine : public QObject {
    Q_OBJECT
public:
    explicit RenderEngine(QObject* parent = nullptr);
    void setRenderer(std::unique_ptr<IRenderer> renderer);
    IRenderer* renderer() const;
    void renderFrame(QPainter* painter, const QSize& size);
    Q_INVOKABLE void setIntensity(qreal intensity);
    Q_INVOKABLE qreal intensity() const;
private:
    std::unique_ptr<IRenderer> m_renderer;
    QElapsedTimer m_timer;
};

} // namespace aether::rendering
