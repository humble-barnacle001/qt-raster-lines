#ifndef CIRCLESMAINWIDGET_H
#define CIRCLESMAINWIDGET_H

#include <QWidget>

namespace Ui {
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

private:
    Ui::CirclesMainWidget *ui;
};

#endif // CIRCLESMAINWIDGET_H
