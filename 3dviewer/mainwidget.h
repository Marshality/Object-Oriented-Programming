#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include "canvas.h"
#include "viewer.h"

namespace Ui {
class mainwidget;
}

class mainwidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();

private slots:
    void on_loadButton_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

private:
    Ui::mainwidget *ui;
    struct MyCanvas *scene;
    struct ModelData model_data;
};

#endif // MAINWIDGET_H
