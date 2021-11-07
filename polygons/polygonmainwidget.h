#ifndef POLYGONMAINWIDGET_H
#define POLYGONMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class PolygonMainWidget;
}

class PolygonMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PolygonMainWidget(QWidget *parent = nullptr);
    ~PolygonMainWidget();

private:
    Ui::PolygonMainWidget *ui;

public slots:
    void change_widget(int index);

signals:
    void send_data(int x1, int y1, int x2, int y2);
    void send_grid_width(int gw);
    void reset_shape();
    void select_seed();

private slots:
    void on_gridWidth_valueChanged(int arg1);
    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status, bool showTime);

    void setFillStatus(bool status);
    void setProgressUpdate(QString, int value);
    void on_seedButton_clicked();
};

#endif // POLYGONMAINWIDGET_H
