#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include <iostream>

#include "viewer.h"
#include "model.h"
#include "errors.h"

#define WIDTH 1000
#define HEIGHT 1000

mainwidget::mainwidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Object-Oriented Programming #1");

    scene = new struct MyCanvas;
    scene->sceneptr = new QGraphicsScene();
    model_data.canvas = scene;

    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->setScene(scene->sceneptr);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->sceneptr->setSceneRect(-WIDTH, -HEIGHT, WIDTH * 2, HEIGHT * 2);
}

mainwidget::~mainwidget()
{
    std::cout << "bye!" << std::endl;
    doIt(DeleteAction, &model_data);
    delete ui;
}

void mainwidget::on_loadButton_clicked()
{
    QString modelName = QFileDialog::getOpenFileName(this, "~\\");
    if (modelName.isEmpty()) return;

    QByteArray bytearray = modelName.toLatin1();
    char *filename = bytearray.data();
    model_data.filename = filename;

    errorCode result = doIt(LoadAction, &model_data);

    if (result == err_fIsNotCorrect) {
        QMessageBox::warning(this, "Error!", "File is empty or incorrect!");
    }

    result = doIt(DrawAction, &model_data);
}

void mainwidget::on_moveButton_clicked()
{
    MoveData data;

    data.dx = ui->dx_input->text().toDouble();
    data.dy = ui->dy_input->text().toDouble();
    data.dz = ui->dz_input->text().toDouble();

    model_data.m_data = data;

    errorCode result = doIt(MoveAction, &model_data);
    result = doIt(DrawAction, &model_data);
}

void mainwidget::on_scaleButton_clicked()
{
    ScaleData data;

    data.k = ui->scale_input->text().toDouble();

    model_data.s_data = data;

    errorCode result = doIt(ScaleAction, &model_data);
    result = doIt(DrawAction, &model_data);
}

void mainwidget::on_rotateButton_clicked()
{
    RotateData data;

    data.xa = ui->rx_input->text().toDouble();
    data.ya = ui->ry_input->text().toDouble();
    data.za = ui->rz_input->text().toDouble();

    model_data.r_data = data;

    errorCode result = doIt(RotateAction, &model_data);
    result = doIt(DrawAction, &model_data);
}
