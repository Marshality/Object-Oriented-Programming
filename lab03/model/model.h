//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MODEL_H
#define LAB03_MODEL_H

#include "point.h"
#include "edge.h"
#include "../vector/_vector.h"
#include <vector>
#include "../canvas/canvas.h"

class Model {
private:
    MyVector<Point> points;
    MyVector<Edge> edges;

public:
    Model() = default;

    Model(MyVector<Point> points, MyVector<Edge> edges) {
        this->points = points;
        this->edges = edges;
    }

    MyVector<Point> getPoints() { return points; }
    MyVector<Edge> getEdges() { return edges; }
//
//    void draw(MyCanvas *canvas) {
//        for (int i = 0; i < edges.getSize(); i++) {
//            canvas->drawLine(points[i])
//        }
//    }

    ~Model() = default;
};

#endif //LAB03_MODEL_H
