//
// Created by Marshal on 10/05/2018.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class NotEqualSizesException : public std::exception {
public:
    const char* what() const noexcept override { return "Sizes are not equal."; }
};

class OutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override { return "Out of range."; }
};

#endif //EXCEPTIONS_H
