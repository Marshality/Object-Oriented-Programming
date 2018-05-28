//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_FILE_H
#define LAB03_FILE_H

#include "stdio.h"
#include "BaseParser.h"
#include "../model/CarcaseModel.h"
#include <iostream>
#include "../exception/exceptions.h"

class CarcaseParser : public BaseParser {
private:
    FILE *file;

    Point loadPoint() {
        double x, y, z;

        if (fscanf(file, "%lf %lf %lf", &x, &y, &z) != 3) throw corruptFileException();
        Point point(x, y, z);

        return point;
    }

    Edge loadEdge() {
        int a, b;

        if (fscanf(file, "%d %d", &a, &b) != 2) throw corruptFileException();
        Edge edge(a, b);

        return edge;
    }

public:
    CarcaseParser() = default;

    CarcaseParser(const char *filename) { file = fopen(filename, "r"); };
    ~CarcaseParser() {}

    void parse(BaseModel &model) {
        int pointsCount = 0, edgesCount = 0;

        if (fscanf(file, "%d %d", &pointsCount, &edgesCount) != 2) throw corruptFileException();

        MyVector<Point> points(pointsCount);
        MyVector<Edge> edges(edgesCount);

        for (int i = 0; i < pointsCount; i++) points[i] = loadPoint();

        for (int i = 0; i < edgesCount; i++) edges[i] = loadEdge();

        model.setPoints(points);
        model.setEdges(edges);
    };
};

#endif //LAB03_FILE_H
