//
// Created by Marshal on 14/05/2018.
//

#ifndef LAB03_VIEWER_H
#define LAB03_VIEWER_H

#include "command/commands.h"
#include "canvas/drawer.h"

class Receiver { // 3DViewer
private:
    BaseModel *model = new CarcaseModel();

    ParserCommand *p_command;
    ModelCommand *m_command;

public:
    Receiver() = default;
    ~Receiver() = default;

    void loadModel(const char *filename) {
        p_command = new LoadModelCmd(model, new CarcaseParser(filename));
        p_command->execute();
    }

    void drawModel(MyCanvas *canvas) {
        m_command = new DrawModelCmd(model, canvas);
        m_command->execute();
    }

    void rotateModel(double xa, double ya, double za) {
        m_command = new RotateModelCmd(model, xa, ya, za);
        m_command->execute();
    }

    void scaleModel(double k) {
        m_command = new ScaleModelCmd(model, k);
        m_command->execute();
    }

    void moveModel(double dx, double dy, double dz) {
        m_command = new MoveModelCmd(model, dx, dy, dz);
        m_command->execute();
    }
};

#endif //LAB03_VIEWER_H
