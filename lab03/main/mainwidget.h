//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MAINWIDGET_H
#define LAB03_MAINWIDGET_H

#include <QMainWindow>
#include "../canvas/canvas.h"
#include "../viewer.h"

namespace Ui {
    class mainwidget;
}

class mainwidget : public QMainWindow {
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();

private slots:
    void on_loadButton_clicked();
    void on_rotateButton_clicked();
    void on_scaleButton_clicked();
    void on_moveButton_clicked();

private:
    Ui::mainwidget *ui;
    Receiver receiver;
    Drawer drawer;
    MyCanvas<QGraphicsScene> canvas = new QGraphicsScene();
};


#endif //LAB03_MAINWIDGET_H
