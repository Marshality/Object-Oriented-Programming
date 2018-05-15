//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_COMMANDS_H
#define LAB03_COMMANDS_H

#include "BaseCommand.h"
#include "../parser.h"
#include "../canvas/drawer.h"

class LoadModelCmd : public Command<Parser> {
private:
    Model *model;

public:
    LoadModelCmd(Model *_model, char *_filename) : model(_model) {
        object = new Parser(_filename);
    }

    void execute() { object->parse(*model); }
};

class DrawModelCmd : public Command<Drawer> {
private:
    Model *model;
    MyCanvas<QGraphicsScene> *canvas;

public:
    DrawModelCmd(Model *_model, MyCanvas<QGraphicsScene> *_canvas) : model(_model), canvas(_canvas) {
        object = new Drawer(canvas);
    }

    void execute() { object->drawModel(model); }
};

class RotateModelCmd : public Command<Model> {
private:
    double xa, ya, za;

public:
    RotateModelCmd(Model *model, double _xa, double _ya, double _za) : xa(_xa), ya(_ya), za(_za) {
        object = model;
    }

    void execute() { object->rotate(xa, ya, za); }
};

class ScaleModelCmd : public Command<Model> {
private:
    double k;

public:
    ScaleModelCmd(Model *model, double _k) : k(_k) {
        object = model;
    }

    void execute() { object->scale(k); }
};

class MoveModelCmd : public Command<Model> {
private:
    double dx, dy, dz;

public:
    MoveModelCmd(Model *model, double _dx, double _dy, double _dz) : dx(_dx), dy(_dy), dz(_dz) {
        object = model;
    }

    void execute() { object->move(dx, dy, dz); }
};


#endif //LAB03_COMMANDS_H
