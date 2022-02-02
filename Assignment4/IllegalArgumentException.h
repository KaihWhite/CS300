//
// Created by Kaih White on 11/19/2021.
//

#ifndef ASSIGNMENT4_ILLEGALARGUMENTEXCEPTION_H
#define ASSIGNMENT4_ILLEGALARGUMENTEXCEPTION_H

#include <string>

class IllegalArgumentException: public std::exception {
public:
    explicit IllegalArgumentException(const std::string msg);
};


#endif //ASSIGNMENT4_ILLEGALARGUMENTEXCEPTION_H
