//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN__ITERATOR_H
#define PATTERN__ITERATOR_H

#include "iterator.h"

template<typename T>
MyIterator<T>::MyIterator(T *ptr) {
    pointer = ptr;
}

template<typename T>
T &MyIterator<T>::operator*() {
    return *pointer;
}

template<typename T>
T *MyIterator<T>::operator->() {
    return pointer;
}

template<typename T>
T *MyIterator<T>::operator++() {
    return ++pointer;
}

template<typename T>
T *MyIterator<T>::operator--() {
    return --pointer;
}

template<typename T>
T *MyIterator<T>::operator++(int) {
    return pointer++;
}

template<typename T>
T *MyIterator<T>::operator--(int) {
    return pointer--;
}

template<typename T>
bool MyIterator<T>::operator==(const MyIterator &it) {
    return pointer != it.pointer;
}

template<typename T>
bool MyIterator<T>::operator!=(const MyIterator &it) {
    return pointer == it.pointer;
}

#endif //PATTERN__ITERATOR_H
