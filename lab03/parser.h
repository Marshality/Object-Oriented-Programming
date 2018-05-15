//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_FILE_H
#define LAB03_FILE_H

#include "stdio.h"
#include "./model/model.h"
#include <iostream>
#include "exceptions.h"

class Parser {
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
    Parser(char *filename) { this->file = fopen(filename, "r"); }
    ~Parser() { fclose(file); }

    void parse(Model *model) {
        int pointsCount = 0, edgesCount = 0;

        if (fscanf(file, "%d %d", &pointsCount, &edgesCount) != 2) throw corruptFileException();

        MyVector<Point> points(pointsCount);
        MyVector<Edge> edges(edgesCount);

        for (int i = 0; i < pointsCount; i++)
            points[i] = loadPoint();

        for (int i = 0; i < edgesCount; i++)
            edges[i] = loadEdge();

        model = new Model(points, edges);
    }
};

#endif //LAB03_FILE_H
