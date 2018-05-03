//
// Created by Marshal on 29/04/2018.
//

#ifndef PATTERN_ITERATOR_H
#define PATTERN_ITERATOR_H

template<typename T>
class MyIterator {
private:
    T *pointer;

public:
    // Конструктор
    explicit MyIterator(T *ptr);

    // Деструктор
    ~MyIterator() = default;

    // Операторы
    T &operator*();
    T *operator->();
    T *operator++();
    T *operator--();
    T *operator++(int);
    T *operator--(int);
    bool operator<(const MyIterator &it);
    bool operator==(const MyIterator &it);
    bool operator!=(const MyIterator &it);
};

#endif //PATTERN_ITERATOR_H
