//
// Created by Marshal on 09.05.2018.
//

#ifndef VTEMPLATE__VECTOR_H
#define VTEMPLATE__VECTOR_H

#include "vector.h"
#include <iostream>

template<typename T>
MyVector<T>::MyVector() {
    this->size = 0;
    this->data = nullptr;
}

template<typename T>
MyVector<T>::MyVector(int size) {
    this->size = size;
    this->data = new T [size];
}

template<typename T>
MyVector<T>::~MyVector() {
    delete [] data;
}

template<typename T>
T &MyVector<T>::operator[](int index) {
    return data[index];
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
    if (this->data) {
        delete [] this->data;
    }

    this->size = other.size;
    this->data = new T [other.size];

    for (int i = 0; i < other.size; i++) {
        this->data[i] = other.data[i];
    }

    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator+=(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    for (int i = 0; i < this->size; i++) {
        this->data[i] += other.data[i];
    }

    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator-=(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    for (int i = 0; i < this->size; i++) {
        this->data[i] -= other.data[i];
    }

    return *this;
}

template<typename T>
MyVector<T> MyVector<T>::operator+(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    MyVector<T> temp(this->size);

    for (int i = 0; i < this->size; i++) {
        temp.data[i] = this->data[i] + other.data[i];
    }

    return temp;
}

template<typename T>
MyVector<T> MyVector<T>::operator-(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    MyVector<T> temp(this->size);

    for (int i = 0; i < this->size; i++) {
        temp.data[i] = this->data[i] - other.data[i];
    }

    return temp;
}

template<typename T>
MyVector<T> MyVector<T>::operator*(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    MyVector<T> temp(this->size);

    for (int i = 0; i < this->size; i++) {
        temp.data[i] = this->data[i] * other.data[i];
    }

    return temp;
}

template<typename T>
MyVector<T> MyVector<T>::operator*(const T value) {
    MyVector<T> temp(this->size);

    for (int i = 0; i < this->size; i++) {
        temp.data[i] = this->data[i] * value;
    }

    return temp;
}

template<typename T>
MyVector<T> &MyVector<T>::operator*=(const MyVector &other) {
    if (this->size != other.size) {
        throw "Sizes are not equal.";
    }

    for (int i = 0; i < this->size; i++) {
        this->data[i] *= other.data[i];
    }

    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator*=(const T value) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] *= value;
    }

    return *this;
}

template<typename T>
bool MyVector<T>::operator==(const MyVector &other) {
    bool flag = true;

    if (this->size == other.size) {
        for (int i = 0; i < this->size && flag; i++) {
            if (this->data[i] != other.data[i]) flag = false;
        }
    } else {
        flag = false;
    }

    return flag;
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector &other) {
    bool flag = false;

    if (this->size == other.size) {
        for (int i = 0; i < this->size && !flag; i++) {
            if (this->data[i] != other.data[i]) flag = true;
        }
    } else {
        flag = true;
    }

    return flag;
}

#endif //VTEMPLATE__VECTOR_H
