//
// Created by Marshal on 09.05.2018.
//

#ifndef VTEMPLATE_VECTOR_H
#define VTEMPLATE_VECTOR_H

#include "basevector.h"
#include <math.h>
#include <initializer_list>

template<typename T>
class MyVector : public BaseVector {
private:
    int size;
    T *data;

public:
    // Конструкторы
    MyVector();
    explicit MyVector(int size); // Стандартный конструктор

    // Деструктор
    ~MyVector();

    // Операторы
    T &operator[](int index);
    MyVector<T> &operator=(const MyVector &other);
    MyVector<T> operator+(const MyVector &other);
    MyVector<T> operator-(const MyVector &other);
    MyVector<T> &operator+=(const MyVector &other);
    MyVector<T> &operator-=(const MyVector &other);
    MyVector<T> operator*(const MyVector &other); // Умножение векторов
    MyVector<T> &operator*=(const MyVector &other);
    MyVector<T> operator*(const T value); // Умножение вектора на число
    MyVector<T> &operator*=(const T value);
    bool operator==(const MyVector &other);
    bool operator!=(const MyVector &other);
};

#endif //VTEMPLATE_VECTOR_H
