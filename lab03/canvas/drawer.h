//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_DRAWER_H
#define LAB03_DRAWER_H

#include "canvas.h"
#include "../vector/vector.h"
#include "../model/point.h"
#include "../model/edge.h"
#include "../model/model.h"

class Drawer {
private:
    MyCanvas<QGraphicsScene> *canvas;

public:
    Drawer() = default;
    Drawer(MyCanvas<QGraphicsScene> *_canvas) : canvas(_canvas) {}
    ~Drawer() = default;

    void drawEdge(MyVector<Point> points, Edge edge) {
        canvas->drawLine(points[edge.get_a()].get_x(), points[edge.get_a()].get_y(), \
                        points[edge.get_b()].get_x(), points[edge.get_b()].get_y());
    }

    void drawEdges(MyVector<Point> points, MyVector<Edge> edges) {
        for (int i = 0; i < edges.getSize(); i++) drawEdge(points, edges[i]);
    }

    void drawModel(Model *model) {
        canvas->sceneClear();
        drawEdges(model->getPoints(), model->getEdges());
    }
};

#endif //LAB03_DRAWER_H
