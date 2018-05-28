//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_POINT_H
#define LAB03_POINT_H

class Point {
private:
    double x, y, z;

public:
    Point() = default;

    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double getX() { return this->x; }
    double getY() { return this->y; }
    double getZ() { return this->z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }
};

#endif //LAB03_POINT_H
