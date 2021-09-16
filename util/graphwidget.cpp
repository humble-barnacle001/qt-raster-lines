#include "graphwidget.h"
#include "ui_graph.h"

#include <QPainter>

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
    , m_shape(false)
    , ui(new Ui::Graph)
    , grid_width(5)
{
    ui->setupUi(this);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}


void GraphWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    drawGraph(painter);
    if(m_shape)
        this->drawShape(painter);
    painter.end();
}

void GraphWidget::onGridWidthChanged(int w)
{
    this->grid_width = w;
    qint32 dim = 2*w*(ceil(341/2/w)-1)-1;
    this->setFixedSize(dim, dim);
    this->repaint();
}

void GraphWidget::onResetClicked()
{
    this->m_shape = false;
    this->repaint();
}

QPoint GraphWidget::resolveCoordinates(qreal x, qreal y){
    return QPoint(x+this->width()/2, this->width()/2-y);
}

void GraphWidget::drawGraph(QPainter &painter)
{
    painter.setBackgroundMode(Qt::BGMode::OpaqueMode);
    painter.setPen(QColor(Qt::lightGray));
    for(int i=grid_width-1;i<this->width();i+=grid_width)
    {
        painter.drawLine(i,0,i,this->height());
        painter.drawLine(0,i,this->width(),i);
    }
    painter.setPen(QColor(Qt::red));
    painter.drawLine(this->width()/2,0,this->width()/2,this->height());
    painter.drawLine(0,this->height()/2,this->width(),this->height()/2);
}

void GraphWidget::drawPoint(QPainter &qp, const QPoint &gc,const QPoint &point, const QColor &fillCol)
{
    qreal gcx=gc.x(), gcy=gc.y(), cx=point.x()-gcx, cy=gcy-point.y(), t=this->grid_width;

    qreal tx = cx*t+gcx, ty=gcy-cy*t-t+1;

    qp.fillRect(tx, ty, t, t, QBrush(fillCol));
}
