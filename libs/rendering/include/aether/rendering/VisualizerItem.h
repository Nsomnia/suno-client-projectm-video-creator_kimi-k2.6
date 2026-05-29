#pragma once
#include <QQuickPaintedItem>
#include <memory>

namespace aether::rendering {
class RenderEngine;
}

namespace aether::ui {

class VisualizerItem : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(qreal intensity READ intensity WRITE setIntensity NOTIFY intensityChanged)
public:
    explicit VisualizerItem(QQuickItem* parent = nullptr);
    ~VisualizerItem() override;
    void paint(QPainter* painter) override;
    qreal intensity() const;
    void setIntensity(qreal value);
signals:
    void intensityChanged();
private:
    std::unique_ptr<aether::rendering::RenderEngine> m_engine;
    qreal m_intensity{1.0};
};

} // namespace aether::ui
