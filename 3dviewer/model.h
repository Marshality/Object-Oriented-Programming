#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "errors.h"
#include <stdio.h>

struct EdgesList {
    int count;
    Edge *list;
};

struct PointsList {
    int count;
    Point3D *list;
};

struct Model {
    PointsList points;
    EdgesList edges;
};

struct Model * initModel();
void freePoints(struct PointsList *points);
void freeEdges(struct EdgesList *edges);
errorCode freeModel(struct Model *model);
errorCode loadPoint(struct Point3D *point, FILE *file);
errorCode loadEdge(struct Edge *edge, FILE *file);
errorCode parseFile(struct PointsList *points, struct EdgesList *edges, FILE *file);
errorCode loadModel(struct Model *model, char *filename);
void printmodel(struct Model *model);

#endif // MODEL_H
