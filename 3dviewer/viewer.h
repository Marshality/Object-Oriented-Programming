#ifndef VIEWER_H
#define VIEWER_H

#include "canvas.h"
#include "errors.h"
#include "transform.h"

enum viewerAction { LoadAction, DeleteAction, DrawAction, MoveAction, ScaleAction, RotateAction };

struct ModelData {
    MoveData m_data;
    ScaleData s_data;
    RotateData r_data;
    char *filename;
    struct MyCanvas *canvas;
};

errorCode doIt(viewerAction action, struct ModelData *model_data);

#endif // VIEWER_H
