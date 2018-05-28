//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_DRAWER_H
#define LAB03_DRAWER_H

#include "BaseCanvas.h"
#include "../vector/vector.h"
#include "../model/point.h"
#include "../model/edge.h"

class Drawer {
private:
    MyCanvas *canvas;

public:
    Drawer() = default;
    Drawer(MyCanvas *_canvas) : canvas(_canvas) {}
    ~Drawer() = default;

    void drawEdge(MyVector<Point> points, Edge edge) {
        canvas->drawLine(points[edge.getA()].getX(), points[edge.getA()].getY(), \
                        points[edge.getB()].getX(), points[edge.getB()].getY());
    }

    void drawEdges(MyVector<Point> points, MyVector<Edge> edges) {
        for (int i = 0; i < edges.getSize(); i++) drawEdge(points, edges[i]);
    }
};

#endif //LAB03_DRAWER_H
