//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03__VECTOR_H
#define LAB03__VECTOR_H

#include "vector.h"

template<typename T>
MyVector<T>::MyVector(int size) {
    this->size = size;
    this->data = new T [size];
}

template<typename T>
MyVector<T>::MyVector(const MyVector &other) {
    this->size = other.size;
    this->data = new T [other.size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    delete [] this->data;
}

template<typename T>
T &MyVector<T>::operator[](int index) {
    return data[index];
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
    if (this->data) {
        delete[] this->data;
    }

    this->size = other.size;
    this->data = new T[other.size];

    for (int i = 0; i < other.size; i++) {
        this->data[i] = other.data[i];
    }

    return *this;
}

template<typename T>
MyVector<T>::MyVector() {
    this->size = 0;
    this->data = nullptr;
}


#endif //LAB03__VECTOR_H
