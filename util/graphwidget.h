#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Graph;
}
QT_END_NAMESPACE

class GraphWidget : public QWidget
{
    Q_OBJECT

protected:
    using CustomPair = QPair<QPoint, QColor>;
    using CustomPairList = QVector<CustomPair>;

public:
    GraphWidget(QWidget *parent = nullptr, qsizetype dim = 351, quint32 timer = 100);
    ~GraphWidget();
    GraphWidget::CustomPairList::const_iterator getDefaultPoints();

protected:
    bool m_shape;
    qsizetype curr;
    quint32 anim_timer;
    GraphWidget::CustomPairList points, defaultPoints;
    QPoint resolveCoordinates(qreal x, qreal y);
    QPoint resolvePoint(const QPoint &pos);
    void drawGraph(QPainter &painter);
    void drawPoint(QPainter &qp, const QPoint &point);
    void animateDraw();
    void updateDefaultPoints(const GraphWidget::CustomPair &pointColorPair, bool update = true, bool remove = false);
    void updateDefaultPoints(const GraphWidget::CustomPairList &list);
    void removeAllDefaultPoints();
    qint32 getGridWidth();
    // void addPointsToDefault();
    virtual const GraphWidget::CustomPairList drawShape() = 0;

private:
    Ui::Graph *ui;
    qint32 grid_width;
    qsizetype max_dim;
    bool m_signal;
    void drawDefaultPoints(QPainter &painter);
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

public slots:
    void onGridWidthChanged(int w);
    void onResetClicked();

signals:
    void send_time(QString name, qint64 t);
    void set_draw_status(QString name, bool s, bool showTime = true);
    void update_progress(QString name, int value);
    void mouse_dbl_clicked(const QPoint &x);

    // Polygon special
    void set_fillButton_status(bool status);
};

#endif // GRAPHWIDGET_H
