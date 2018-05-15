//
// Created by Marshal on 15/05/2018.
//

#ifndef LAB03_BASECOMMAND_H
#define LAB03_BASECOMMAND_H

template<typename T>
class Command {
protected:
    T *object;

public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

#endif //LAB03_BASECOMMAND_H
