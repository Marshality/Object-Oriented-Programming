//
// Created by Marshal on 17/05/2018.
//

#ifndef LAB03_BASEMODEL_H
#define LAB03_BASEMODEL_H

#include "../canvas/drawer.h"

class BaseModel {
protected:
    MyVector<Point> points;
    MyVector<Edge> edges;

public:
    BaseModel() = default;
    virtual ~BaseModel() {}

    virtual void rotate(double xa, double ya, double za) = 0;
    virtual void move(double dx, double dy, double dz) = 0;
    virtual void scale(double k) = 0;

    virtual void setPoints(MyVector<Point> points) = 0;
    virtual void setEdges(MyVector<Edge> edges) = 0;

    virtual void draw(Drawer &drawer) = 0;
};

#endif //LAB03_BASEMODEL_H
