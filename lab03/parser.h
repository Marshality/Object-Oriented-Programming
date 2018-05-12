//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_FILE_H
#define LAB03_FILE_H

#include "stdio.h"
#include "model/model.h"
#include "exceptions.h"

class Parser {
private:
    char *filename;
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
    Parser(char *filename) {
        this->filename = filename;
        this->file = fopen(filename, "r");
    }

    ~Parser() { fclose(this->file); }

    int parse(Model *mdl) {
        int pointsCount = 0, edgesCount = 0;

        if (fscanf(file, "%d %d", &pointsCount, &edgesCount) != 2) return -1;

        std::vector<Point> points;
        std::vector<Edge> edges;

        points.reserve(pointsCount);
        edges.reserve(edgesCount);

        for (int i = 0; i < pointsCount; i++) {
            points[i] = loadPoint();
            std::cout << points[i].get_x() << " " << points[i].get_y() << " " << points[i].get_z() << std::endl;
        }
        for (int i = 0; i < edgesCount; i++) {
            edges[i] = loadEdge();
            std::cout << edges[i].get_a() << " " << edges[i].get_b() << std::endl;
        }

        mdl = new Model(points, edges);

        return 0;
    }
};

#endif //LAB03_FILE_H
