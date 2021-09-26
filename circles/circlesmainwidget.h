#ifndef CIRCLESMAINWIDGET_H
#define CIRCLESMAINWIDGET_H

#include <QWidget>

namespace Ui
{
    class CirclesMainWidget;
}

class CirclesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CirclesMainWidget(QWidget *parent = nullptr);
    ~CirclesMainWidget();

private slots:
    void on_algoSelector_currentIndexChanged(int index);

    void on_gridWidth_valueChanged(int arg1);

    void on_drawButton_clicked();

    void on_resetButton_clicked();

    void onTimePassed(QString, qint64 t);

    void setDrawButtonStatus(QString, bool status);

    void setProgressUpdate(QString, int value);

signals:
    void send_data(qint32 cx, qint32 cy, qint32 r);
    void send_grid_width(int gw);
    void reset_shape();

private:
    Ui::CirclesMainWidget *ui;
};

#endif // CIRCLESMAINWIDGET_H
