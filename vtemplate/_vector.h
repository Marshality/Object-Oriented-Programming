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
MyVector<T>::MyVector(int size, T value) {
    this->size = size;
    this->data = new T [size];

    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
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
MyVector<T>::MyVector(MyVector &&other) {
    this->size = other.size;
    this->data = std::move(other.data);
    other.data = nullptr;
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

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> list) {
    this->size = list.size();
    this->data = new T [this->size];

    const T *begin = list.begin();
    const T *end = list.end();
    const T *current = begin;

    for (int i = 0; current != end; current++, i++) {
        this->data[i] = *current;
    }
}

template<typename T>
void MyVector<T>::norm() {
    double abs_value;

    for (int i = 0; i < size; i++) {
        abs_value += pow(data[i], 2);
    }

    for (int i = 0; i < size; i++) {
        data[i] /= sqrt(abs_value);
    }
}

template<typename T>
double MyVector<T>::operator^(const MyVector &other) {
    double abs1 = 0, abs2 = 0, result = 0;

    for (int i = 0; i < size; i++) {
        abs1 += pow(this->data[i], 2);
        abs2 += pow(other.data[i], 2);
    }

    MyVector<T> temp(size);
    temp = *this * other;

    for (int i = 0; i < size; i++) {
        result += temp.data[i];
    }

    return acos(result / (sqrt(abs1) * sqrt(abs2))) * 180 / 3.14159265358979323846264;
}

template<typename T>
bool MyVector<T>::orth(const MyVector &v1, const MyVector &v2) {
    return v1 * v2 == 0;
}

#endif //VTEMPLATE__VECTOR_H
