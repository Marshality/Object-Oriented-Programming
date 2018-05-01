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

    data = new T* [rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new T [columns];
    }

    std::cout << "Matrix constructor: " << this << std::endl;
}

template<typename T>
Matrix<T>::Matrix(int value) {
    this->rows = value;
    this->columns = value;

    data = new T* [value];

    for (int i = 0; i < value; i++) {
        data[i] = new T [value];
    }

    std::cout << "Matrix constructor: " << this << std::endl;
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }

    delete[] data;

    std::cout << "Destructor: " << this << std::endl;
}

template<typename T>
const T &Matrix<T>::operator()(int i, int j) const {
    if (i >= rows || j >= columns || i < 0 || j < 0) {
        throw std::range_error("Out of range.");
    }

    return data[i][j];
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) {
    this->rows = other.rows;
    this->columns = other.columns;

    this->data = new T* [other.rows];

    for (int i = 0; i < other.rows; i++) {
        this->data[i] = new T [other.columns];
    }

    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }

    std::cout << "Copy constructor: " << this << std::endl;
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

    this->data = new T* [other.rows];

    for (int i = 0; i < other.rows; i++) {
        this->data[i] = new T [other.columns];
    }

    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }

    std::cout << "= operator: " << this << std::endl;

    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix &other) const {
    if (rows != other.rows || columns != other.columns) {
        throw -1;
    }

    Matrix<T> temp(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return temp;
}

//template<typename T>
//Matrix<T>::Matrix(Matrix &&other) {
//    this->rows = std::move(other.rows);
//    this->columns = std::move(other.columns);
//
//    this->data = std::move(other.data);
//    other.data = nullptr;
//
//    std::cout << "Move constructor: " << this << std::endl;
//}

#endif //PATTERN__MATRIX_H
