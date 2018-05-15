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

    double get_x() {
        return this->x;
    }

    double get_y() {
        return this->y;
    }

    double get_z() {
        return this->z;
    }
};

#endif //LAB03_POINT_H
