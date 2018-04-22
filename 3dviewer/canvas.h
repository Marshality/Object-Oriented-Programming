#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include "point.h"

struct MyCanvas { QGraphicsScene *sceneptr; };

void drawLine(struct MyCanvas *canvas, struct Point2D pa, struct Point2D pb);

#endif // CANVAS_H
