//
// Created by Marshal on 14/05/2018.
//

#ifndef LAB03_VIEWER_H
#define LAB03_VIEWER_H

#include "command/commands.h"
#include "canvas/drawer.h"

class Receiver { // 3DViewer
private:
    Command<Parser> *p_command;
    Command<Model> *m_command;
    Command<Drawer> *d_command;
    Model model;

public:
    Receiver() = default;

    void loadModel(char *filename) {
        p_command = new LoadModelCmd(&model, filename);
        p_command->execute();
    }

    void drawModel(MyCanvas<QGraphicsScene> *canvas, Drawer drawer) {
        d_command = new DrawModelCmd(&model, canvas);
        d_command->execute();
    }

    void rotateModel(double xa, double ya, double za) {
        m_command = new RotateModelCmd(&model, xa, ya, za);
        m_command->execute();
    }

    void scaleModel(double k) {
        m_command = new ScaleModelCmd(&model, k);
        m_command->execute();
    }

    void moveModel(double dx, double dy, double dz) {
        m_command = new MoveModelCmd(&model, dx, dy, dz);
        m_command->execute();
    }
};

#endif //LAB03_VIEWER_H
