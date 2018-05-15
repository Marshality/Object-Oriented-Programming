//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_CANVAS_H
#define LAB03_CANVAS_H

#include <QGraphicsScene>

template<typename T>
class MyCanvas {
private:
    T *pointer;

public:
    MyCanvas(T *scene) : pointer(scene) {}
    ~MyCanvas() { delete pointer; }

    T* scene() { return pointer; }

    void drawLine(double x1, double y1, double x2, double y2) { pointer->addLine(x1, y1, x2, y2); }

    void sceneClear() { pointer->clear(); }
};

#endif //LAB03_CANVAS_H
