//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MODEL_H
#define LAB03_MODEL_H

#include "point.h"
#include "edge.h"
#include "../vtemplate/vector.h"
#include <vector>

class Model {
private:
    std::vector<Point> points;
    std::vector<Edge> edges;

public:
    Model() = default;

    Model(std::vector<Point> points, std::vector<Edge> edges) {
        this->points = points;
        this->edges = edges;
    }
};

#endif //LAB03_MODEL_H
