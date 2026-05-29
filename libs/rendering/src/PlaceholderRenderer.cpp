#include "aether/rendering/PlaceholderRenderer.h"
#include <QPainter>
#include <QLinearGradient>
#include <QtMath>
#include <algorithm>

namespace aether::rendering {

PlaceholderRenderer::PlaceholderRenderer()
    : m_rng(std::random_device{}())
{
    m_barHeights.resize(m_barCount, 0.0);
    m_particles.resize(m_particleCount);
}

void PlaceholderRenderer::initialize()
{
    // No-op
}

void PlaceholderRenderer::shutdown()
{
    // No-op
}

void PlaceholderRenderer::render(QPainter* painter, const QSize& size, qreal deltaTimeMs)
{
    if (!painter || size.width() <= 0 || size.height() <= 0)
        return;

    const qreal time = m_simulatedTime + deltaTimeMs * 0.001;
    m_simulatedTime = time;

    updateSimulatedAudioData(time);
    updateParticles(deltaTimeMs, size.width(), size.height());

    painter->setRenderHint(QPainter::Antialiasing);

    // Background
    painter->fillRect(QRect(0, 0, size.width(), size.height()), QColor(10, 10, 18));

    drawBars(painter, size, time);
    drawWaveform(painter, size, time);
    drawParticles(painter, size);
}

void PlaceholderRenderer::updateSimulatedAudioData(qreal time)
{
    for (int i = 0; i < m_barCount; ++i) {
        const qreal t = time * 2.0 + i * 0.3;
        const qreal base = (qSin(t) + qSin(t * 1.7) * 0.5 + qSin(t * 3.1) * 0.3) * 0.5 + 0.5;
        m_barHeights[i] = base * m_intensity;
    }
}

void PlaceholderRenderer::setBarCount(int count)
{
    m_barCount = std::max(1, count);
    m_barHeights.resize(m_barCount, 0.0);
}

void PlaceholderRenderer::setParticleCount(int count)
{
    m_particleCount = std::max(0, count);
    m_particles.resize(m_particleCount);
}

void PlaceholderRenderer::updateParticles(qreal deltaTimeMs, int width, int height)
{
    const qreal dt = deltaTimeMs * 0.001;
    std::uniform_real_distribution<qreal> distX(0.0, static_cast<qreal>(width));
    std::uniform_real_distribution<qreal> distR(1.0, 4.0);
    std::uniform_real_distribution<qreal> distLife(2.0, 6.0);

    for (auto& p : m_particles) {
        if (p.life <= 0.0 || p.y < -10.0) {
            // Respawn
            p.x = distX(m_rng);
            p.y = static_cast<qreal>(height) + distR(m_rng);
            p.vx = (std::uniform_real_distribution<qreal>(-15.0, 15.0)(m_rng));
            p.vy = -(std::uniform_real_distribution<qreal>(20.0, 60.0)(m_rng));
            p.radius = distR(m_rng);
            p.maxLife = distLife(m_rng);
            p.life = p.maxLife;
        }

        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.life -= dt;
        p.alpha = std::clamp(p.life / p.maxLife, 0.0, 1.0);
    }
}

void PlaceholderRenderer::drawBars(QPainter* painter, const QSize& size, qreal time)
{
    const int w = size.width();
    const int h = size.height();
    const qreal barWidth = static_cast<qreal>(w) / m_barCount;
    const qreal maxBarHeight = h * 0.45;

    for (int i = 0; i < m_barCount; ++i) {
        const qreal heightRatio = m_barHeights[i];
        const qreal barHeight = maxBarHeight * heightRatio;
        const qreal x = i * barWidth;
        const qreal y = (h - barHeight) * 0.5;

        QRectF barRect(x + 1.0, y, barWidth - 2.0, barHeight);

        QLinearGradient gradient(barRect.topLeft(), barRect.bottomLeft());
        const qreal hueShift = qSin(time * 0.5 + i * 0.1) * 30.0;
        gradient.setColorAt(0.0, QColor::fromHsvF(std::fmod((180.0 + hueShift) / 360.0, 1.0), 0.9, 1.0));
        gradient.setColorAt(0.5, QColor::fromHsvF(std::fmod((300.0 + hueShift) / 360.0, 1.0), 0.9, 0.9));
        gradient.setColorAt(1.0, QColor::fromHsvF(std::fmod((180.0 + hueShift) / 360.0, 1.0), 0.9, 0.4));

        painter->fillRect(barRect, gradient);
    }
}

void PlaceholderRenderer::drawWaveform(QPainter* painter, const QSize& size, qreal time)
{
    const int w = size.width();
    const int h = size.height();
    const int points = w / 2;
    const qreal centerY = h * 0.5;
    const qreal amplitude = h * 0.12 * m_intensity;

    QPolygonF poly;
    for (int i = 0; i <= points; ++i) {
        const qreal x = static_cast<qreal>(i) / points * w;
        const qreal t = time * 3.0 + x * 0.02;
        const qreal y = centerY + qSin(t) * amplitude
                        + qSin(t * 2.3) * amplitude * 0.5
                        + qSin(t * 5.7) * amplitude * 0.25;
        poly.append(QPointF(x, y));
    }

    QPen pen(QColor(0, 255, 255), 2.5);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawPolyline(poly);

    // Glow effect
    QPen glowPen(QColor(0, 255, 255, 80), 6.0);
    glowPen.setCapStyle(Qt::RoundCap);
    glowPen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(glowPen);
    painter->drawPolyline(poly);
}

void PlaceholderRenderer::drawParticles(QPainter* painter, const QSize& size)
{
    Q_UNUSED(size)
    for (const auto& p : m_particles) {
        if (p.alpha <= 0.0)
            continue;

        QColor color(255, 0, 255, static_cast<int>(p.alpha * 200));
        painter->setPen(Qt::NoPen);
        painter->setBrush(color);
        painter->drawEllipse(QPointF(p.x, p.y), p.radius, p.radius);
    }
}

} // namespace aether::rendering
