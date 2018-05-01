//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN_MATRIX_H
#define PATTERN_MATRIX_H

#include "basematrix.h"
#include <memory>

template<typename T>
class Matrix : public BaseMatrix {
private:
    int rows, columns;
    T **data;

public:
    // Конструкторы
    Matrix();
    Matrix(int rows, int columns);
    Matrix(int value);
    Matrix(const Matrix &other); // Конструктор копирования
    //Matrix(Matrix &&other); // Конструктор перемещения

    // Деструктор
    ~Matrix();

    // Методы
    void add(T value, int i, int j) {
        data[i][j] = value;
    }

    // Операторы // +; +=; -; -=; *; *=; & - ?
    const T &operator()(int i, int j) const;
    bool operator==(const Matrix &other);
    bool operator!=(const Matrix &other);
    Matrix<T> &operator=(const Matrix &other);
    const Matrix<T> operator+(const Matrix &other) const;
};

#endif //PATTERN_MATRIX_H
