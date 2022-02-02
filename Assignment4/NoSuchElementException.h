//
// Created by Kaih White on 11/19/2021.
//

#ifndef ASSIGNMENT4_NOSUCHELEMENTEXCEPTION_H
#define ASSIGNMENT4_NOSUCHELEMENTEXCEPTION_H

#include <string>

class NoSuchElementException:public std::exception {
public:
    explicit NoSuchElementException(std::string msg);
};


#endif //ASSIGNMENT4_NOSUCHELEMENTEXCEPTION_H
