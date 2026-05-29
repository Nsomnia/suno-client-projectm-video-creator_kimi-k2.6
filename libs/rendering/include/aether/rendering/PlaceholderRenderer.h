#pragma once
#include "IRenderer.h"
#include <QVector>
#include <QColor>
#include <random>

namespace aether::rendering {

struct Particle {
    qreal x{0.0};
    qreal y{0.0};
    qreal vx{0.0};
    qreal vy{0.0};
    qreal radius{2.0};
    qreal alpha{1.0};
    qreal life{1.0};
    qreal maxLife{1.0};
};

class PlaceholderRenderer : public IRenderer {
public:
    PlaceholderRenderer();
    void initialize() override;
    void shutdown() override;
    void render(QPainter* painter, const QSize& size, qreal deltaTimeMs) override;
    QString name() const override { return QStringLiteral("PlaceholderRenderer"); }

    void updateSimulatedAudioData(qreal time);
    void setBarCount(int count);
    void setParticleCount(int count);

private:
    void updateParticles(qreal deltaTimeMs, int width, int height);
    void drawBars(QPainter* painter, const QSize& size, qreal time);
    void drawWaveform(QPainter* painter, const QSize& size, qreal time);
    void drawParticles(QPainter* painter, const QSize& size);

    QVector<qreal> m_barHeights;
    QVector<Particle> m_particles;
    int m_barCount{64};
    int m_particleCount{40};
    qreal m_simulatedTime{0.0};
    std::mt19937 m_rng;
};

} // namespace aether::rendering
