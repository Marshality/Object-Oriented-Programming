//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MODEL_H
#define LAB03_MODEL_H

#include "point.h"
#include "edge.h"
#include "../vector/_vector.h"
#include <vector>

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

    ~Model() = default;
};

#endif //LAB03_MODEL_H
