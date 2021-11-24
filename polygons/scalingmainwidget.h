#ifndef SCALINGMAINWIDGET_H
#define SCALINGMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class ScalingMainWidget;
}

class ScalingMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScalingMainWidget(QWidget *parent = nullptr);
    ~ScalingMainWidget();

private:
    Ui::ScalingMainWidget *ui;

signals:
    void send_grid_width(int gw);
    void reset_shape();
    void send_XY(const QPointF &p);

private slots:
    void on_gridWidth_valueChanged(int arg1);
    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status, bool showTime);

    void setProgressUpdate(QString, int value);
    void on_spinBox_valueChanged(double arg1);
    void on_spinBox_2_valueChanged(double arg1);
};

#endif // SCALINGMAINWIDGET_H
