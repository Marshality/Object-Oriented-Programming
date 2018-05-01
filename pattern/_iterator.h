//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN__ITERATOR_H
#define PATTERN__ITERATOR_H

#include "iterator.h"

template<typename T>
MatrixIterator<T>::MatrixIterator(const Matrix<T> &data) {
    this->data = &data;
    this->current = data(0, 0);
}

template<typename T>
MatrixIterator<T>::MatrixIterator(const MatrixIterator<T> &iterator) {
    this->data = iterator.data;
    this->current = iterator.current;
}

template<typename T>
MatrixIterator<T>::~MatrixIterator() {
    this->data = nullptr;
    this->current = nullptr;
}

template<typename T>
void MatrixIterator<T>::begin() {
    // ...
}

#endif //PATTERN__ITERATOR_H
