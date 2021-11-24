#ifndef ROTATIONMAINWIDGET_H
#define ROTATIONMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class RotationMainWidget;
}

class RotationMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RotationMainWidget(QWidget *parent = nullptr);
    ~RotationMainWidget();

private:
    Ui::RotationMainWidget *ui;

signals:
    void send_grid_width(int gw);
    void reset_shape();
    void send_angle(int ang);

private slots:
    void on_gridWidth_valueChanged(int arg1);
    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status, bool showTime);

    void setProgressUpdate(QString, int value);
    void on_spinBox_valueChanged(int arg1);
};

#endif // ROTATIONMAINWIDGET_H
