#include "graphwidget.h"
#include "ui_graph.h"

#include <cmath>
#include <QPainter>
#include <QMouseEvent>
#include <QTimeLine>

GraphWidget::GraphWidget(QWidget *parent, qsizetype dim, quint32 timer)
    : QWidget(parent), m_shape(false), curr(-1), anim_timer(timer),
      ui(new Ui::Graph), grid_width(5), max_dim(dim), m_signal(true)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawGraph(painter);
    if (m_shape)
    {
        if (curr < points.count())
        {
            painter.setBrush(QBrush(QColor(Qt::darkBlue)));
            for (qsizetype i = 0; i <= curr; i++)
                this->drawPoint(painter, points.at(i));
        }
        if (curr == points.count() - 1 && m_signal)
        {
            m_signal = false;
            emit set_draw_status(this->objectName(), true);
        }
    }
    painter.end();
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint gc = resolvePoint(event->pos());
    this->setToolTip(QString::asprintf("%d, %d", gc.x(), gc.y()));
}

void GraphWidget::onGridWidthChanged(int w)
{
    this->grid_width = w;
    qint32 dim = 2 * w * (std::ceil(max_dim / 2 / w) - 1) - 1;
    this->setFixedSize(dim, dim);
    this->repaint();
}

void GraphWidget::onResetClicked()
{
    this->m_shape = false;
    this->curr = -1;
    this->repaint();
}

QPoint GraphWidget::resolveCoordinates(qreal x, qreal y)
{
    return QPoint(x + this->width() / 2, this->width() / 2 - y);
}

QPoint GraphWidget::resolvePoint(const QPoint &pos)
{
    return QPoint(std::floor(1.0 * (pos.x() - this->width() / 2) / this->grid_width), std::floor(1.0 * (this->width() / 2 - pos.y()) / this->grid_width));
}

void GraphWidget::drawGraph(QPainter &painter)
{
    painter.setBackgroundMode(Qt::BGMode::OpaqueMode);
    painter.setPen(QColor(Qt::lightGray));
    for (int i = grid_width - 1; i < this->width(); i += grid_width)
    {
        painter.drawLine(i, 0, i, this->height());
        painter.drawLine(0, i, this->width(), i);
    }
    painter.setBrush(QBrush(QColor(Qt::red)));
    painter.fillRect(this->width() / 2, 0, grid_width, this->height(), painter.brush());
    painter.fillRect(0, this->height() / 2 - grid_width, this->width(), grid_width, painter.brush());
}

void GraphWidget::drawPoint(QPainter &qp, const QPoint &point)
{
    qreal cx = point.x(), cy = point.y(), t = this->grid_width;

    QPoint rc = resolveCoordinates(cx * t, cy * t + t - 1);

    qp.fillRect(rc.x(), rc.y(), t, t, qp.brush());
}

void GraphWidget::animateDraw(const QColor &)
{
    this->points = this->drawShape();
    qsizetype t = this->points.count();

    emit set_draw_status(this->objectName(), false);
    emit update_progress(this->objectName(), 0);
    m_signal = true;

    QTimeLine *tl = new QTimeLine(t * this->anim_timer);
    tl->setFrameRange(-1, t - 1);
    connect(tl, &QTimeLine::frameChanged, [=](int frame)
            {
                this->curr = frame;
                this->repaint();
                emit update_progress(this->objectName(), (frame+1)*1.0/t*100);
            });
    tl->start();
}
