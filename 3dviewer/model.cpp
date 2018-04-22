#include "model.h"
#include <stdio.h>
#include <iostream>

struct Model * initModel() {
    struct Model *model = new struct Model;

    if (model) {
        model->edges.count = 0;
        model->points.count = 0;
        model->edges.list = nullptr;
        model->points.list = nullptr;
    } else return nullptr;

    return model;
}

void freePoints(struct PointsList *points) {
    if (!points) return;
    delete points->list;
}

void freeEdges(struct EdgesList *edges) {
    if (!edges) return;
    delete edges->list;
}

errorCode freeModel(struct Model *model) {
    freePoints(&(model->points));
    freeEdges(&(model->edges));

    return err_noErr;
}

errorCode loadPoint(struct Point3D *point, FILE *file) {
    errorCode result = err_noErr;

    if (fscanf(file, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
        result = err_fIsNotCorrect;

    return result;
}

errorCode loadEdge(struct Edge *edge, FILE *file) {
    errorCode result = err_noErr;

    if (fscanf(file, "%d %d", &edge->a, &edge->b) != 2) result = err_fIsNotCorrect;

    return result;
}

errorCode parseFile(struct PointsList *points, struct EdgesList *edges, FILE *file) {
    errorCode result = err_noErr;

    if (fscanf(file, "%d %d", &points->count, &edges->count) != 2) return err_fIsNotCorrect;

    points->list = new struct Point3D[points->count];
    if (!points->list) return err_mNotAllocated;

    edges->list = new struct Edge[edges->count];
    if (!edges->list) {
        freePoints(points);
        return err_mNotAllocated;
    }

    for (int i = 0; (i < points->count) && (result == err_noErr); i++)
        result = loadPoint(&points->list[i], file);

    if (result == err_fIsNotCorrect) {
        std::cout << result << std::endl;
        freePoints(points);
        return result;
    }

    for (int i = 0; (i < edges->count) && (result == err_noErr); i++)
        result = loadEdge(&edges->list[i], file);

    if (result == err_fIsNotCorrect) {
        freePoints(points);
        freeEdges(edges);
    }

    return result;
}

//void printmodel(struct Model *model) {
//    std::cout << "#Vertices: " << model->points.count << "\n#Edges: " << model->edges.count << std::endl;

//    for (int i = 0; i < model->points.count; i++) {
//        std::cout << "X: " << model->points.list[i].x << " Y: " <<
//            model->points.list[i].y << " Z: " << model->points.list[i].z << std::endl;
//    }

//    for (int i = 0; i < model->edges.count; i++) {
//        std::cout << "A: " << model->edges.list[i].a << " B: " << model->edges.list[i].b << std::endl;
//    }
//}

errorCode loadModel(struct Model *model, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return err_fNotExist;

    struct Model *temp = initModel();
    if (!temp) return err_mNotAllocated;

    errorCode result = parseFile(&temp->points, &temp->edges, file);

    if (result == err_noErr) {
        if (model->points.count > 0) freeModel(model);
        *model = *temp;
    }

    fclose(file);

    return result;
}
