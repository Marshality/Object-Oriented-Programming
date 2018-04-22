#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "model.h"
#include "errors.h"

struct MoveData {
    double dx;
    double dy;
    double dz;
};

struct ScaleData {
    double k;
};

struct RotateData {
    double xa;
    double ya;
    double za;
};

errorCode moveFunc(struct PointsList points, struct Point3D *list, struct MoveData data);
errorCode scaleFunc(struct PointsList points, struct Point3D *list, struct ScaleData data);
errorCode rotateX(struct PointsList points, struct Point3D *list, struct RotateData data);
errorCode rotateY(struct PointsList points, struct Point3D *list, struct RotateData data);
errorCode rotateZ(struct PointsList points, struct Point3D *list, struct RotateData data);
errorCode rotateFunc(struct PointsList points, struct Point3D *list, struct RotateData data);

#endif // TRANSFORM_H
