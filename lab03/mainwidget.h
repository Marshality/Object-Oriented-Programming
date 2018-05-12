//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MAINWIDGET_H
#define LAB03_MAINWIDGET_H

#include <QMainWindow>
#include <QGraphicsScene>

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

private:
    Ui::mainwidget *ui;
    QGraphicsScene *scene;
};


#endif //LAB03_MAINWIDGET_H
