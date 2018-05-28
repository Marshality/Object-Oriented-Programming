//
// Created by Marshal on 12/05/2018.
//

#include "mainwidget.h"
#include "../cmake-build-debug/lab03_autogen/include/ui_mainwidget.h"

#include "../canvas/QtCanvas.h"

#include <QFileDialog>

#include <iostream>

#define WIDTH 1000
#define HEIGHT 1000

mainwidget::mainwidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Lab03");

    drawer = Drawer(canvas);

    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->setScene(canvas->scene());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    canvas->scene()->setSceneRect(-WIDTH, -HEIGHT, WIDTH * 2, HEIGHT * 2);
}

mainwidget::~mainwidget() {
    std::cout << "bye!" << std::endl;
    delete ui;
}

void mainwidget::on_loadButton_clicked() {
    QString mdlName = QFileDialog::getOpenFileName(this);
    if (mdlName.isEmpty()) return;

    QByteArray byteArray = mdlName.toLatin1();
    const char *filename = byteArray.data();

    puts(filename);

    try {
        receiver.loadModel(filename);
        canvas->sceneClear();
        receiver.drawModel(canvas);
    } catch (corruptFileException &e) {
        std::cerr << e.what() << std::endl;
    }
}

void mainwidget::on_rotateButton_clicked() {
    double xa = ui->rx_input->text().toDouble();
    double ya = ui->ry_input->text().toDouble();
    double za = ui->rz_input->text().toDouble();

    receiver.rotateModel(xa, ya, za);
    canvas->sceneClear();
    receiver.drawModel(canvas);
}

void mainwidget::on_scaleButton_clicked() {
    double k = ui->scale_input->text().toDouble();

    receiver.scaleModel(k);
    canvas->sceneClear();
    receiver.drawModel(canvas);
}

void mainwidget::on_moveButton_clicked() {
    double dx = ui->dx_input->text().toDouble();
    double dy = ui->dy_input->text().toDouble();
    double dz = ui->dz_input->text().toDouble();

    receiver.moveModel(dx, dy, dz);
    canvas->sceneClear();
    receiver.drawModel(canvas);
}