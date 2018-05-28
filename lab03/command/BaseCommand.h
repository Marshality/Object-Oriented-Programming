//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_BASECOMMAND_H
#define LAB03_BASECOMMAND_H

#include "../model/BaseModel.h"
#include "../parser/CarcaseParser.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //LAB03_BASECOMMAND_H
