#ifndef REFLECTIONMAINWIDGET_H
#define REFLECTIONMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class ReflectionMainWidget;
}

class ReflectionMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReflectionMainWidget(QWidget *parent = nullptr);
    ~ReflectionMainWidget();

private:
    Ui::ReflectionMainWidget *ui;

signals:
    void send_grid_width(int gw);
    void reset_shape();
    void line_select();

private slots:
    void on_gridWidth_valueChanged(int arg1);
    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status, bool showTime);
    void setLineButtonStatus(bool status);

    void setProgressUpdate(QString, int value);
    void on_lineButton_clicked();
};

#endif // REFLECTIONMAINWIDGET_H
