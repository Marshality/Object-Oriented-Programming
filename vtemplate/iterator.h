//
// Created by Marshal on 09.05.2018.
//

#ifndef VTEMPLATE_ITERATOR_H
#define VTEMPLATE_ITERATOR_H

template <typename T>
class MyIterator
{
public:
    MyIterator (T *temp) : ptr(temp) { }
    ~MyIterator () { }

    T &operator *() { return *ptr; }
    T *operator ->() const { return ptr; }

    T *operator ++() { return ++ptr; }
    T *operator --() { return --ptr; }

    bool operator <(const MyIterator<T> &temp) {
        return this->operator ->() <= temp.operator ->();
    }

private:
    T *ptr;
};

#endif //VTEMPLATE_ITERATOR_H
