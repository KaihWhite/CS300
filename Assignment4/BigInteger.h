//
// Created by Kaih White on 11/13/2021.
//

#ifndef ASSIGNMENT4_BIGINTEGER_H
#define ASSIGNMENT4_BIGINTEGER_H

#include <string>
#include "DoublyLinkedList.h"
#include <fstream>
#include <istream>

class BigInteger {
    bool neg;
    DoublyLinkedList<int>* myInt;
public:
    BigInteger();

    ~BigInteger();

    BigInteger(std::string item);

    int getLength();

    bool isNegative();

    BigInteger operator+(BigInteger& other);

    BigInteger operator-(BigInteger& other);

    BigInteger& operator=(BigInteger& other);

    bool operator<=(BigInteger& other);

    bool operator>=(BigInteger& other);

    bool operator==(BigInteger& other);

    bool operator<(BigInteger& other);

    bool operator>(BigInteger& other);

    friend ostream& operator<<(ostream& out, const BigInteger& other);

    friend ifstream& operator>>(ifstream& in, BigInteger& other);
};


#endif //ASSIGNMENT4_BIGINTEGER_H
