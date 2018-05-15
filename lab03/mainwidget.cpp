//
// Created by Marshal on 12/05/2018.
//

#include "mainwidget.h"
#include "./cmake-build-debug/lab03_autogen/include/ui_mainwidget.h"

#include <QFileDialog>

#include <iostream>
#include "viewer.h"

#define WIDTH 1000
#define HEIGHT 1000

mainwidget::mainwidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Lab03");

    scene = new QGraphicsScene();
    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(-WIDTH, -HEIGHT, WIDTH * 2, HEIGHT * 2);
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

    Receiver rec(filename);
    try {
        rec.loadModel();
    } catch (corruptFileException &e) {
        std::cerr << e.what() << std::endl;
    }
}