#include "draw.h"

struct Point2D makePoint2D(double x, double y) {
    struct Point2D point;

    point.x = x;
    point.y = y;

    return point;
}

void canvasClear(struct MyCanvas *canvas) {
    canvas->sceneptr->clear();
}

void drawEdge(struct MyCanvas *canvas, struct Point3D *list, struct Edge edge) {
    struct Point2D pa = makePoint2D(list[edge.a].x, list[edge.a].y);
    struct Point2D pb = makePoint2D(list[edge.b].x, list[edge.b].y);

    drawLine(canvas, pa, pb);
}

void drawEdges(struct MyCanvas *canvas, struct PointsList points, struct EdgesList edges) {
    for (int i = 0; i < edges.count; i++) drawEdge(canvas, points.list, edges.list[i]);
}

errorCode drawModel(struct Model model, struct MyCanvas *canvas) {
    errorCode result = err_noErr;

    canvasClear(canvas);
    drawEdges(canvas, model.points, model.edges);

    return result;
}
