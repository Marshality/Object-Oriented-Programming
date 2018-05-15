//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_MODEL_H
#define LAB03_MODEL_H

#include "point.h"
#include "edge.h"
#include "../vector/_vector.h"

#include <math.h>

#define PI      3.14159265
#define DEGREES 180

class Model {
private:
    MyVector<Point> points;
    MyVector<Edge> edges;

    void rotateX(double xa) {
        double tmp_y;
        double tmp_z;

        for (int i = 0; i < points.getSize(); i++) {
            tmp_y = points[i].getY();
            tmp_z = points[i].getZ();

            points[i].setY(tmp_y * cos(xa * PI / DEGREES) + tmp_z * sin(xa * PI / DEGREES));
            points[i].setZ(-tmp_y * sin(xa * PI / DEGREES) + tmp_z * cos(xa * PI / DEGREES));
        }
    }

    void rotateY(double ya) {
        double tmp_x;
        double tmp_z;

        for (int i = 0; i < points.getSize(); i++) {
            tmp_x = points[i].getX();
            tmp_z = points[i].getZ();

            points[i].setX(tmp_x * cos(ya * PI / DEGREES) + tmp_z * sin(ya * PI / DEGREES));
            points[i].setZ(-tmp_x * sin(ya * PI / DEGREES) + tmp_z * cos(ya * PI / DEGREES));
        }
    }

    void rotateZ(double za) {
        double tmp_x;
        double tmp_y;

        for (int i = 0; i < points.getSize(); i++) {
            tmp_x = points[i].getX();
            tmp_y = points[i].getY();

            points[i].setX(tmp_x * cos(za * PI / DEGREES) - tmp_y * sin(za * PI / DEGREES));
            points[i].setY(tmp_x * sin(za * PI / DEGREES) + tmp_y * cos(za * PI / DEGREES));
        }
    }

public:
    Model() = default;

    Model(MyVector<Point> points, MyVector<Edge> edges) {
        this->points = points;
        this->edges = edges;
    }

    ~Model() = default;

    MyVector<Point> getPoints() { return points; }
    MyVector<Edge> getEdges() { return edges; }

    void rotate(double xa, double ya, double za) {
        rotateX(xa);
        rotateY(ya);
        rotateZ(za);
    }

    void scale(double k) {
        for (int i = 0; i < points.getSize(); i++) {
            points[i].setX(points[i].getX() * k);
            points[i].setY(points[i].getY() * k);
            points[i].setZ(points[i].getZ() * k);
        }
    }

    void move(double dx, double dy, double dz) {
        for (int i = 0; i < points.getSize(); i++) {
            points[i].setX(points[i].getX() + dx);
            points[i].setY(points[i].getY() + dy);
            points[i].setZ(points[i].getZ() + dz);
        }
    }
};

#endif //LAB03_MODEL_H
