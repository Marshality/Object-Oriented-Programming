//
// Created by Marshal on 14/05/2018.
//

#ifndef LAB03_VIEWER_H
#define LAB03_VIEWER_H

#include "parser.h"

//class Singleton {
//private:
//    static Singleton *self;
//    Singleton() {}
//    virtual ~Singleton() {}
//
//    Model *model;
//
//public:
//    static Singleton* instance() {
//        if (!self) self = new Singleton();
//        return self;
//    }
//
//    void saveModel(Model *model) {
//        this->model = model;
//    }
//
//    Model& getModel() {
//        return *model;
//    }
//};

template<typename T>
class Command {
protected:
    T *object;

public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class LoadModelCmd : public Command<Parser> {
private:
    Model *model;

public:
    LoadModelCmd(Model *_model, char *_filename) : model(_model) { object = new Parser(_filename); }

    void execute() {
        object->parse(model);
    }
};

class Receiver { // 3DViewer
private:
    Command<Parser> *p_command;
    Command<Model> *m_command;
    Model model;
    char *filename;

public:
    Receiver() {}
    Receiver(char *_filename) : filename(_filename), model(Model()) {}

    void loadModel() {
        p_command = new LoadModelCmd(&model, filename);
        p_command->execute();
    }
};

#endif //LAB03_VIEWER_H
