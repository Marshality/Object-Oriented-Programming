//
// Created by Marshal on 10/05/2018.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class corruptFileException : public std::exception {
public:
    const char* what() const noexcept override { return "Corrupt file."; }
};

class memoryAllocationException : public std::exception {
public:
    const char* what() const noexcept override { return "Allocation error."; }
};

#endif //EXCEPTIONS_H
