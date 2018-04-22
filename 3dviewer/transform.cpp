#include "transform.h"
#include <math.h>
#include <iostream>
#include "errors.h"

#define PI      3.14159265
#define DEGREES 180

errorCode moveFunc(struct PointsList points, struct Point3D *list, struct MoveData data) {
    for (int i = 0; i < points.count; i++) {
        list[i].x += data.dx;
        list[i].y += data.dy;
        list[i].z += data.dz;
    }

    return err_noErr;
}

errorCode scaleFunc(struct PointsList points, struct Point3D *list, struct ScaleData data) {
    for (int i = 0; i < points.count; i++) {
        list[i].x *= data.k;
        list[i].y *= data.k;
        list[i].z *= data.k;
    }

    return err_noErr;
}

errorCode rotateX(struct PointsList points, struct Point3D *list, struct RotateData data) {
    double tmp_y;
    double tmp_z;

    for (int i = 0; i < points.count; i++) {
        tmp_y = list[i].y;
        tmp_z = list[i].z;

        list[i].x = list[i].x;
        list[i].y = tmp_y * cos(data.xa * PI / DEGREES) + tmp_z * sin(data.xa * PI / DEGREES);
        list[i].z = -tmp_y * sin(data.xa * PI / DEGREES) + tmp_z * cos(data.xa * PI / DEGREES);
    }

    return err_noErr;
}

errorCode rotateY(struct PointsList points, struct Point3D *list, struct RotateData data) {
    double tmp_x;
    double tmp_z;

    for (int i = 0; i < points.count; i++) {
        tmp_x = list[i].x;
        tmp_z = list[i].z;

        list[i].x = tmp_x * cos(data.ya * PI / DEGREES) + tmp_z * sin(data.ya * PI / DEGREES);
        list[i].y = list[i].y;
        list[i].z = -tmp_x * sin(data.ya * PI / DEGREES) + tmp_z * cos(data.ya * PI / DEGREES);
    }

    return err_noErr;
}

errorCode rotateZ(struct PointsList points, struct Point3D *list, struct RotateData data) {
    double tmp_x;
    double tmp_y;

    for (int i = 0; i < points.count; i++) {
        tmp_x = list[i].x;
        tmp_y = list[i].y;

        list[i].x = tmp_x * cos(data.za * PI / DEGREES) - tmp_y * sin(data.za * PI / DEGREES);
        list[i].y = tmp_x * sin(data.za * PI / DEGREES) + tmp_y * cos(data.za * PI / DEGREES);
        list[i].z = list[i].z;
    }

    return err_noErr;
}

errorCode rotateFunc(struct PointsList points, struct Point3D *list, struct RotateData data) {
    errorCode result = err_noErr;

    result = rotateX(points, list, data);
    result = rotateY(points, list, data);
    result = rotateZ(points, list, data);

    return result;
}
