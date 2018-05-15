//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_COMMANDS_H
#define LAB03_COMMANDS_H

#include "BaseCommand.h"
#include "../model/model.h"
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

#endif //LAB03_COMMANDS_H
