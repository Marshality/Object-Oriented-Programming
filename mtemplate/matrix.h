//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN_MATRIX_H
#define PATTERN_MATRIX_H

#include "basematrix.h"
#include <memory>
#include <ostream>
#include "iterator.h"

template<typename T>
class Matrix : public BaseMatrix {
private:
    int rows, columns;
    T **data;

    // Выделение памяти
    T** allocator();

public:
    // Конструкторы
    Matrix();
    Matrix(int rows, int columns); // Стандартный конструктор
    Matrix(int rows, int columns, T value); // Конструктор заполнения матрицы
    explicit Matrix(int value); // Конструктор квадратной матрицы
    explicit Matrix(const Matrix &other); // Конструктор копирования
    Matrix(Matrix &&other); // Конструктор перемещения

    // Деструктор
    ~Matrix();

    // Операторы
    const T &operator()(int i, int j) const;
    T* &operator[](int index);
    bool operator==(const Matrix &other);
    bool operator!=(const Matrix &other);
    Matrix<T> &operator=(const Matrix &other);
    const Matrix<T> operator+(const Matrix &other) const;
    Matrix<T> &operator+=(const Matrix &other);
    const Matrix<T> operator-(const Matrix &other) const;
    Matrix<T> &operator-=(const Matrix &other);
    const Matrix<T> operator*(const Matrix &other) const;
    const Matrix<T> operator*(T value) const;
    Matrix<T> &operator*=(const Matrix &other);
    Matrix<T> &operator*=(T value);

    // Методы
    MyIterator<T> begin();
    MyIterator<T> end();
};

#endif //PATTERN_MATRIX_H
