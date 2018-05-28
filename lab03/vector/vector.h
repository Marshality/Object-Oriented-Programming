//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_VECTOR_H
#define LAB03_VECTOR_H

template<typename T>
class MyVector {
private:
    int size;
    T *data;

public:
    // Конструкторы
    MyVector();
    explicit MyVector(int size); // Стандартный конструктор
    MyVector(const MyVector &other);

    // Деструктор
    ~MyVector();

    // Операторы
    T &operator[](int index);
    MyVector<T> &operator=(const MyVector &other);

    // Методы
    int getSize() { return size; }
};

#endif //LAB03_VECTOR_H
