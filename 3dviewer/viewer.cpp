#include "viewer.h"
#include "errors.h"
#include "model.h"
#include "draw.h"
#include "transform.h"

errorCode doIt(viewerAction action, struct ModelData *model_data) {
    errorCode result = err_noErr;
    static struct Model *model = initModel();

    switch (action) {
    case LoadAction:
        result = loadModel(model, model_data->filename);
        break;
    case DeleteAction:
        result = freeModel(model);
        break;
    case DrawAction:
        result = drawModel(*model, model_data->canvas);
        break;
    case MoveAction:
        result = moveFunc(model->points, model->points.list, model_data->m_data);
        break;
    case ScaleAction:
        result = scaleFunc(model->points, model->points.list, model_data->s_data);
        break;
    case RotateAction:
        result = rotateFunc(model->points, model->points.list, model_data->r_data);
        break;
    default:
        result = err_UnknownAction;
        break;
    }

    return result;
}
