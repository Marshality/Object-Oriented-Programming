//
// Created by Marshal on 12/05/2018.
//

#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QFileDialog>

#include <iostream>
#include "../viewer.h"
#include "../canvas/drawer.h"

#define WIDTH 1000
#define HEIGHT 1000

mainwidget::mainwidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Lab03");

    drawer = Drawer(&canvas);

    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->setScene(canvas.scene());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    canvas.scene()->setSceneRect(-WIDTH, -HEIGHT, WIDTH * 2, HEIGHT * 2);
}

mainwidget::~mainwidget() {
    std::cout << "bye!" << std::endl;
    delete ui;
}

void mainwidget::on_loadButton_clicked() {
    QString mdlName = QFileDialog::getOpenFileName(this);
    if (mdlName.isEmpty()) return;

    QByteArray byteArray = mdlName.toLatin1();
    char *filename = byteArray.data();

    puts(filename);

    try {
        receiver.loadModel(filename);
        receiver.drawModel(&canvas, drawer);
    } catch (corruptFileException &e) {
        std::cerr << e.what() << std::endl;
    }
}

void mainwidget::on_rotateButton_clicked() {
    receiver.rotateModel(3, 0, 3);
    receiver.drawModel(&canvas, drawer);
}

void mainwidget::on_scaleButton_clicked() {
    receiver.scaleModel(1.1);
    receiver.drawModel(&canvas, drawer);
}

void mainwidget::on_moveButton_clicked() {
    receiver.moveModel(1, 0, 0);
    receiver.drawModel(&canvas, drawer);
}