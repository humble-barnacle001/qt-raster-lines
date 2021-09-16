#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Graph; }
QT_END_NAMESPACE


class GraphWidget : public QWidget
{
    Q_OBJECT
public:
   GraphWidget(QWidget *parent = nullptr);
   ~GraphWidget();

protected:
   bool m_shape;
   QPoint resolveCoordinates(qreal x, qreal y);
   void paintEvent(QPaintEvent *) override;
   void drawGraph(QPainter &painter);
   void drawPoint(QPainter &qp, const QPoint &gc,const QPoint &point, const QColor &fillCol);
   virtual void drawShape(QPainter & painter) = 0;

private:
    Ui::Graph *ui;
    qint32 grid_width;

public slots:
    void onGridWidthChanged(int w);
    void onResetClicked();

};

#endif // GRAPHWIDGET_H
