//
// Created by Marshal on 29/05/2018.
//

#include "mainwidget.h"
#include "../cmake-build-debug/elevator_autogen/include/ui_mainwidget.h"

#include <iostream>

mainwidget::mainwidget(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainwidget) {
    ui->setupUi(this);
    this->setWindowTitle("Elevator");
}

mainwidget::~mainwidget() {
    std::cout << "bye!" << std::endl;
    delete ui;
}