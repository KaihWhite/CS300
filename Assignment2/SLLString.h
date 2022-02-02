//
// Created by Kaih White on 10/20/2021.
//

#ifndef ASSIGNMENT2_SLLSTRING_H
#define ASSIGNMENT2_SLLSTRING_H

#include <string>
#include <iostream>
#include "Node.h"

class SLLString {
public:
    SLLString(); // Default Constructor
    SLLString(const std::string& other); // Deep Copy constructor with basic string as input
    ~SLLString(); // Destructor
    SLLString(const SLLString& other); // Deep Copy constructor with SLLString as input
    SLLString& operator=(const SLLString& other); // Assignment operator
    int length() const; // Returns length of string
    SLLString& operator+=(const SLLString& other); // Concatenate SLLStrings
    char& operator[](const int n) const; // Index SLLString to access and/or modify specific characters
    int findSubstring(const SLLString& substring) const; // Find SLLString substring within original SLLString
    int findSubstring(const std::string& substring) const; // Fine string substring within original SLLString
    void erase(char c); // Erase every instance of a certain character
    friend std::ostream& operator<<(std::ostream& out, const SLLString& str);
    Node* head; // Head pointer to the SLL
};


#endif //ASSIGNMENT2_SLLSTRING_H
