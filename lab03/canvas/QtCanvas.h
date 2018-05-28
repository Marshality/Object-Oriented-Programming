//
// Created by Marshal on 27/05/2018.
//

#ifndef LAB03_QTCANVAS_H
#define LAB03_QTCANVAS_H

#include "QGraphicsScene"
#include "BaseCanvas.h"

class QtCanvas : public MyCanvas {
private:
    QGraphicsScene *pointer;

public:
    QtCanvas(QGraphicsScene *pointer) { this->pointer = pointer; };

    QGraphicsScene* scene() { return pointer; }

    void drawLine(double x1, double y1, double x2, double y2) { this->pointer->addLine(x1, y1, x2, y2); }

    void sceneClear() { pointer->clear(); }
};

#endif //LAB03_QTCANVAS_H
