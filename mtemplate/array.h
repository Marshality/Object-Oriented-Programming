//
// Created by Marshal on 10/05/2018.
//

#ifndef MTEMPLATE_ARRAY_H
#define MTEMPLATE_ARRAY_H

template<typename T>
class MyArray {
private:
    int size;
    T *data;

public:
    MyArray(int size) {
        this->size = size;
        data = new T [size];
    }

    ~MyArray() { delete [] data; }

    T &operator[](int index) { return data[index]; }
};


#endif //MTEMPLATE_ARRAY_H
