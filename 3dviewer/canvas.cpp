#include "canvas.h"

void drawLine(struct MyCanvas *canvas, struct Point2D pa, struct Point2D pb) {
    canvas->sceneptr->addLine(pa.x, -pa.y, pb.x, -pb.y, QPen(Qt::darkGreen));
}
