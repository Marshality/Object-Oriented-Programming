//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN_ITERATOR_H
#define PATTERN_ITERATOR_H

#include "matrix.h"

template<typename T> class Matrix;

template<typename T>
class BaseIterator {
public:
    virtual void begin() = 0;
    virtual void next() = 0;
    virtual void end() = 0;

protected:
    T *current;
};

template<typename T>
class MatrixIterator : public BaseIterator<T> {
private:
    const Matrix<T> *data;

public:
    // Конструкторы
    MatrixIterator(const Matrix<T> &data);
    MatrixIterator(const MatrixIterator<T> &iterator);

    // Деструктор
    ~MatrixIterator();

    // Методы
    void begin();
    void next();
    void end();
};

#endif //PATTERN_ITERATOR_H
