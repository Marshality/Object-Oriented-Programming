//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_BASECANVAS_H
#define LAB03_BASECANVAS_H

class MyCanvas {
public:
    virtual ~MyCanvas() = default;

    virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
    virtual void sceneClear() = 0;
};

#endif //LAB03_BASECANVAS_H
