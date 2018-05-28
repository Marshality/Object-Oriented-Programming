//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_COMMANDS_H
#define LAB03_COMMANDS_H

#include "ParserCommand.h"
#include "ModelCommand.h"
#include "../parser/CarcaseParser.h"
#include "../canvas/drawer.h"

class LoadModelCmd : public ParserCommand {
private:
    BaseModel *model;

public:
    LoadModelCmd(BaseModel *_model, BaseParser *parser) {
        this->model = _model;
        this->parser = parser;
    }

    void execute() {
        this->parser->parse(*model);
    }
};

class DrawModelCmd : public ModelCommand {
private:
    Drawer *drawer;
    MyCanvas *canvas;

public:
    DrawModelCmd(BaseModel *_model, MyCanvas *_canvas) : canvas(_canvas) {
        model = _model;
        drawer = new Drawer(canvas);
    }

    void execute() { model->draw(*drawer); }
};

class RotateModelCmd : public ModelCommand {
private:
    double xa, ya, za;

public:
    RotateModelCmd(BaseModel *_model, double _xa, double _ya, double _za) : xa(_xa), ya(_ya), za(_za) {
        model = _model;
    }

    void execute() { model->rotate(xa, ya, za); }
};

class ScaleModelCmd : public ModelCommand {
private:
    double k;

public:
    ScaleModelCmd(BaseModel *_model, double _k) : k(_k) {
        model = _model;
    }

    void execute() { model->scale(k); }
};

class MoveModelCmd : public ModelCommand {
private:
    double dx, dy, dz;

public:
    MoveModelCmd(BaseModel *_model, double _dx, double _dy, double _dz) : dx(_dx), dy(_dy), dz(_dz) {
        model = _model;
    }

    void execute() { model->move(dx, dy, dz); }
};


#endif //LAB03_COMMANDS_H
