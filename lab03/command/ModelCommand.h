//
// Created by Marshal on 27/05/2018.
//

#ifndef LAB03_MODELCOMMAND_H
#define LAB03_MODELCOMMAND_H

#include "BaseCommand.h"

class ModelCommand : public Command {
protected:
    BaseModel *model;
};

#endif //LAB03_MODELCOMMAND_H
