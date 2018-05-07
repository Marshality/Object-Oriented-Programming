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

    data = (T**)malloc(rows * sizeof(T*) +
                       rows * columns * sizeof(T));

    for (int i = 0; i < rows; i++)
        data[i] = (T*)((char*)data + rows * sizeof(T*) +
                       i * columns * sizeof(T));
}

template<typename T>
Matrix<T>::Matrix(int value) {
    this->rows = value;
    this->columns = value;

    data = (T**)malloc(value * sizeof(T*) +
                       value * value * sizeof(T));

    for (int i = 0; i < value; i++)
        data[i] = (T*)((char*)value + value * sizeof(T*) +
                       i * value * sizeof(T));
}

template<typename T>
Matrix<T>::~Matrix() {
    //delete[] data;
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

    this->data = (T**)malloc(other.rows * sizeof(T*) +
                             other.rows * other.columns * sizeof(T));

    for (int i = 0; i < rows; i++)
        this->data[i] = (T*)((char*)this->data + other.rows * sizeof(T*) +
                             i * other.columns * sizeof(T));

    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }
}

template<typename T>
bool Matrix<T>::operator==(const Matrix &other) {
    if (this->rows == other.rows && this->columns == other.columns) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->data[i][j] != other.data[i][j]) return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix &other) {
    if (this->rows == other.rows && this->columns == other.columns) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->data[i][j] != other.data[i][j]) return true;
            }
        }
        return false;
    } else {
        return true;
    }
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &other) {
    if (this->data != nullptr) {
        this->~Matrix();
    }

    this->rows = other.rows;
    this->columns = other.columns;

    this->data = (T**)malloc(other.rows * sizeof(T*) +
                       other.rows * other.columns * sizeof(T));

    for (int i = 0; i < rows; i++)
        this->data[i] = (T*)((char*)this->data + other.rows * sizeof(T*) +
                       i * other.columns * sizeof(T));

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

    data = (T**)malloc(rows * sizeof(T*) +
                  rows * columns * sizeof(T));

    for (int i = 0; i < rows; i++)
        data[i] = (T*)((char*)data + rows * sizeof(T*) +
                           i * columns * sizeof(T));

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

#endif //PATTERN__MATRIX_H
