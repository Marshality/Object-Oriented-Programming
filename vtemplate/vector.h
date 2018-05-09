//
// Created by Marshal on 09.05.2018.
//

#ifndef VTEMPLATE_VECTOR_H
#define VTEMPLATE_VECTOR_H

#include "basevector.h"
#include <math.h>
#include "iterator.h"
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
    MyVector(int size, T value); // Конструктор заполнения
    MyVector(std::initializer_list<T> list);
    explicit MyVector(const MyVector &other); // Конструктор копирования
    MyVector(MyVector &&other); // Конструктор переноса

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

    double operator^(const MyVector &other); // Угол между векторами

    // Методы
    void norm(); // Нормирование
    bool orth(const MyVector &v1, const MyVector &v2); // Проверка на ортогональность

    // Итератор
    MyIterator<T> begin() { return MyIterator<T>(&this->data[size - 1]); }
    MyIterator<T> end() { return MyIterator<T>(&this->data[0]); }
};

#endif //VTEMPLATE_VECTOR_H
