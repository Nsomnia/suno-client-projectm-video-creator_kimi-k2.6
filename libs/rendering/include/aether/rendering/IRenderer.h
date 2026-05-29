#pragma once
#include <QSize>
#include <QPainter>
#include <QObject>

namespace aether::rendering {

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual void render(QPainter* painter, const QSize& size, qreal deltaTimeMs) = 0;
    virtual QString name() const = 0;
    virtual void setIntensity(qreal intensity) { m_intensity = intensity; }
    virtual qreal intensity() const { return m_intensity; }
protected:
    qreal m_intensity{1.0};
};

} // namespace aether::rendering
