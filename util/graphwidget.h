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
public:
    GraphWidget(QWidget *parent = nullptr, quint8 timer = 100);
    ~GraphWidget();

protected:
    bool m_shape;
    qsizetype curr;
    quint8 anim_timer;
    QList<QPoint> points;
    QPoint resolveCoordinates(qreal x, qreal y);
    QPoint resolvePoint(const QPoint &pos);
    void drawGraph(QPainter &painter);
    void drawPoint(QPainter &qp, const QPoint &point);
    void animateDraw(const QColor &fillCol = Qt::darkBlue);
    virtual const QList<QPoint> drawShape() = 0;

private:
    Ui::Graph *ui;
    qint32 grid_width;
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void onGridWidthChanged(int w);
    void onResetClicked();

signals:
    void send_time(QString name, qint64 t);
    void set_draw_status(QString name, bool s);
};

#endif // GRAPHWIDGET_H
