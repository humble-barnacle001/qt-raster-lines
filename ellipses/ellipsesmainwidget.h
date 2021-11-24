#ifndef ELLIPSESMAINWIDGET_H
#define ELLIPSESMAINWIDGET_H

#include <QWidget>

namespace Ui {
class EllipsesMainWidget;
}

class EllipsesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EllipsesMainWidget(QWidget *parent = nullptr);
    ~EllipsesMainWidget();

private:
    Ui::EllipsesMainWidget *ui;
};

#endif // ELLIPSESMAINWIDGET_H
