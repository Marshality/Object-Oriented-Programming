//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN__MATRIX_H
#define PATTERN__MATRIX_H

#include <stdexcept>
#include "matrix.h"
#include <iostream>

template<typename T>
Matrix<T>::Matrix() {
    rows = 0;
    columns = 0;
    data = nullptr;
}

template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    this->data = this->allocator();
}

template<typename T>
Matrix<T>::Matrix(int value) {
    this->rows = value;
    this->columns = value;

    this->data = this->allocator();
}

template<typename T>
Matrix<T>::~Matrix() {
    free(data);
}

template<typename T>
const T &Matrix<T>::operator()(int i, int j) const {
    if (i >= rows || j >= columns || i < 0 || j < 0) {
        throw "Out of range.";
    }

    return data[i][j];
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) {
    this->rows = other.rows;
    this->columns = other.columns;

    this->data = this->allocator();

    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }
}

template<typename T>
bool Matrix<T>::operator==(const Matrix &other) {
    bool flag = true;

    if (this->rows == other.rows && this->columns == other.columns) {
        for (int i = 0; i < this->rows && flag; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->data[i][j] != other.data[i][j]) flag = false;
            }
        }
    } else flag = false;

    return flag;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix &other) {
    bool flag = false;

    if (this->rows == other.rows && this->columns == other.columns) {
        for (int i = 0; i < this->rows && !flag; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->data[i][j] != other.data[i][j]) flag = true;
            }
        }
    } else flag = true;

    return flag;
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &other) {
    if (this->data != nullptr) {
        this->~Matrix();
    }

    this->rows = other.rows;
    this->columns = other.columns;

    this->data = this->allocator();

    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix &other) const {
    if (rows != other.rows || columns != other.columns) {
        throw "Sizes are not equal.";
    }

    Matrix<T> temp(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return temp;
}

template<typename T>
Matrix<T>::Matrix(Matrix &&other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->data = std::move(other.data);

    other.data = nullptr;
}

template<typename T>
Matrix<T>::Matrix(int rows, int columns, T value) {
    this->rows = rows;
    this->columns = columns;

    this->data = this->allocator();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            data[i][j] = value;
        }
    }
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &other) {
    if (rows != other.rows || columns != other.columns) {
        throw "Sizes are not equal.";
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->data[i][j] += other.data[i][j];
        }
    }

    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator-(const Matrix &other) const {
    if (rows != other.rows || columns != other.columns) {
        throw "Sizes are not equal.";
    }

    Matrix<T> temp(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return temp;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &other) {
    if (rows != other.rows || columns != other.columns) {
        throw "Sizes are not equal.";
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->data[i][j] -= other.data[i][j];
        }
    }

    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix &other) const {
    Matrix<T> temp(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp.data[i][j] = data[i][j] * other.data[i][j];
        }
    }

    return temp;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const T value) const {
    Matrix<T> temp(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp.data[i][j] = data[i][j] * value;
        }
    }

    return temp;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->data[i][j] *= other.data[i][j];
        }
    }

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const T value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->data[i][j] *= value;
        }
    }

    return *this;
}

template<typename T>
MyIterator<T> Matrix<T>::end() {
    return MyIterator<T>(&this->data[rows - 1][columns - 1]);
}

template<typename T>
MyIterator<T> Matrix<T>::begin() {
    return MyIterator<T>(&this->data[0][0]);
}

template<typename T>
T* &Matrix<T>::operator[](int index) {
    if (index >= rows || index >= columns || index < 0 || index < 0) {
        throw "Out of range.";
    }

    return data[index];
}

template<typename T>
T **Matrix<T>::allocator() {
    data = (T**)malloc(rows * sizeof(T*) +
                       rows * columns * sizeof(T));

    for (int i = 0; i < rows; i++)
        data[i] = (T*)((char*)data + rows * sizeof(T*) +
                       i * columns * sizeof(T));

    return this->data;
}

#endif //PATTERN__MATRIX_H
