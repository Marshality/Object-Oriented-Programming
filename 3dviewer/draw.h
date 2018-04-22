#ifndef DRAW_H
#define DRAW_H

#include "model.h"
#include "errors.h"
#include "canvas.h"

void canvasClear(struct MyCanvas *canvas);
struct Point2D makePoint2D(double x, double y);
void drawEdge(struct MyCanvas *canvas, struct Point3D *list, struct Edge edge);
void drawEdges(struct MyCanvas *canvas, PointsList points, struct EdgesList edges);
errorCode drawModel(struct Model model, struct MyCanvas *canvas);

#endif // DRAW_H
