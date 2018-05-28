//
// Created by Marshal on 22/05/2018.
//

#ifndef LAB03_BASEPARSER_H
#define LAB03_BASEPARSER_H

#include "../model/BaseModel.h"
#include "../model/point.h"
#include "../model/edge.h"

class BaseParser {
public:
    BaseParser() = default;
    virtual ~BaseParser() = default;

    virtual void parse(BaseModel &model) = 0;
};

#endif //LAB03_BASEPARSER_H
