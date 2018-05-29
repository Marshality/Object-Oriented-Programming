//
// Created by Marshal on 29/05/2018.
//

#ifndef ELEVATOR_MAINWIDGET_H
#define ELEVATOR_MAINWIDGET_H

#include <QMainWindow>

namespace Ui {
    class mainwidget;
}

class mainwidget : public QMainWindow {
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();

private:
    Ui::mainwidget *ui;
};

#endif //ELEVATOR_MAINWIDGET_H
