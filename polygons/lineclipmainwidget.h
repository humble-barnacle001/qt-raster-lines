#ifndef LINECLIPMAINWIDGET_H
#define LINECLIPMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class LineClipMainWidget;
}

class LineClipMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LineClipMainWidget(QWidget *parent = nullptr);
    ~LineClipMainWidget();

private:
    Ui::LineClipMainWidget *ui;

signals:
    void send_grid_width(int gw);
    void reset_shape();
    void send_XY(const QPoint &p);

private slots:
    void on_gridWidth_valueChanged(int arg1);
    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status, bool showTime);

    void setProgressUpdate(QString, int value);
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
};

#endif // LINECLIPMAINWIDGET_H
