//
// Created by Kaih White on 11/19/2021.
//

#include "IllegalArgumentException.h"
#include <iostream>

IllegalArgumentException::IllegalArgumentException(const std::string msg){
    std::cout << msg << std::endl;
}