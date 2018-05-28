//
// Created by Marshal on 27/05/2018.
//

#ifndef LAB03_PARSERCOMMAND_H
#define LAB03_PARSERCOMMAND_H

#include "BaseCommand.h"

class ParserCommand : public Command {
protected:
    BaseParser *parser;
};

#endif //LAB03_PARSERCOMMAND_H
