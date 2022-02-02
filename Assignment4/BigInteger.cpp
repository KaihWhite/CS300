//
// Created by Kaih White on 11/13/2021.
//
#include "DoublyLinkedList.h"
#include "BigInteger.h"
#include "IllegalArgumentException.h"

BigInteger::BigInteger() : neg(false) {
    myInt = new DoublyLinkedList<int>;
}

BigInteger::~BigInteger() {
    delete myInt;
}

BigInteger::BigInteger(std::string item) : neg(false) {
    myInt = new DoublyLinkedList<int>;
    int count = 0;
    for(int i = 0; i < item.size(); i++){
        if(item[i] > int('0')-1 && item[i] < int('9')+1){
            myInt->insertLast(item[i] - '0');
            count++;
        }
        else if(item[i] == '-'){
            neg = true;
        }
        else{
            throw IllegalArgumentException("A non-numeric character was entered.");
        }
    }
}

int BigInteger::getLength() {
    return myInt->getLength();
}

bool BigInteger::isNegative() {
    return neg;
}

BigInteger BigInteger::operator+(BigInteger& other) {
    BigInteger fin;
    this->myInt->setIteratorLast();
    other.myInt->setIteratorLast();
    int add1 = 0, add2 = 0, carry = 0;
    while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
        if (!this->myInt->isIteratorNULL()) {
            add1 = this->myInt->getData();
            this->myInt->prev();
        }
        else{
            add1 = 0;
        }
        if (!other.myInt->isIteratorNULL()) {
            add2 = other.myInt->getData();
            other.myInt->prev();
        }
        else{
            add2 = 0;
        }
        if(carry + add1 + add2 > 9){
            fin.myInt->insertFirst((carry+add1+add2)%10);
            carry = 1;
        }
        else{
            fin.myInt->insertFirst((carry+add1+add2));
            carry = 0;
        }
    }
    return fin;
}

BigInteger BigInteger::operator-(BigInteger& other) {
    BigInteger fin;
    this->myInt->setIteratorLast();
    other.myInt->setIteratorLast();
    int add = 0, sub = 0, carry = 0;
    if(this->myInt == other.myInt){
        fin.myInt->insertFirst(0);
        return fin;
    }
    if(*this > other){
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (!this->myInt->isIteratorNULL()) {
                add = this->myInt->getData();
                this->myInt->prev();
            }
            else{
                add = 0;
            }
            if (!other.myInt->isIteratorNULL()) {
                sub = other.myInt->getData();
                other.myInt->prev();
            }
            else{
                sub = 0;
            }
            if(sub > add){
                fin.myInt->insertFirst(add+10-(sub+carry));
                carry = 1;
            }
            else{
                fin.myInt->insertFirst(add-(sub+carry));
                carry = 0;
            }
        }
    }
    else{
        fin.neg = true;
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (!other.myInt->isIteratorNULL()) {
                add = other.myInt->getData();
                other.myInt->prev();
            }
            else{
                add = 0;
            }
            if (!this->myInt->isIteratorNULL()) {
                sub = this->myInt->getData();
                this->myInt->prev();
            }
            else{
                sub = 0;
            }
            if(carry+sub > add){
                fin.myInt->insertFirst(add+10-(sub+carry));
                carry = 1;
            }
            else{
                fin.myInt->insertFirst(add-(sub+carry));
                carry = 0;
            }
        }
    }
    return fin;
}

BigInteger& BigInteger::operator=(BigInteger& other) {
    this->myInt = other.myInt;
    return *this;
}

bool BigInteger::operator==(BigInteger& other) {
    if(myInt->getLength() != other.myInt->getLength()){
        return false;
    }
    if(this->neg != other.neg){
        return false;
    }
    this->myInt->setIteratorFirst();
    other.myInt->setIteratorFirst();
    while(!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()){
        if(this->myInt->getData() != other.myInt->getData()){
            return false;
        }
        this->myInt->next();
        other.myInt->next();
    }
    return true;
}

bool BigInteger::operator<=(BigInteger& other) {
    if(myInt->getLength() > other.myInt->getLength()){
        return false;
    }
    if(myInt->getLength() < other.myInt->getLength()){
        return true;
    }
    if(!this->neg && other.neg){
        return false;
    }
    this->myInt->setIteratorFirst();
    other.myInt->setIteratorFirst();
    if(this->neg && other.neg){
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() < other.myInt->getData()) {
                return false;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    else {
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() > other.myInt->getData()) {
                return false;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    return true;
}

bool BigInteger::operator>=(BigInteger& other) {
    if(myInt->getLength() < other.myInt->getLength()){
        return false;
    }
    if(myInt->getLength() > other.myInt->getLength()){
        return true;
    }
    if(this->neg && !other.neg){
        return false;
    }
    this->myInt->setIteratorFirst();
    other.myInt->setIteratorFirst();
    if(this->neg && other.neg){
        while(!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()){
            if(this->myInt->getData() > other.myInt->getData()){
                return false;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    else {
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() < other.myInt->getData()) {
                return false;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    return true;
}

bool BigInteger::operator<(BigInteger& other) {
    if(myInt->getLength() > other.myInt->getLength()){
        return false;
    }
    if(myInt->getLength() < other.myInt->getLength()){
        return true;
    }
    if(!this->neg && other.neg){
        return false;
    }
    this->myInt->setIteratorFirst();
    other.myInt->setIteratorFirst();
    int match = 0;
    if(this->neg && other.neg){
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() < other.myInt->getData()) {
                return false;
            }
            if (this->myInt->getData() == other.myInt->getData()) {
                match++;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    else {
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() > other.myInt->getData()) {
                return false;
            }
            if (this->myInt->getData() == other.myInt->getData()) {
                match++;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    if(match == myInt->getLength()){
        return false;
    }
    return true;
}

bool BigInteger::operator>(BigInteger& other) {
    if(myInt->getLength() < other.myInt->getLength()){
        return false;
    }
    if(myInt->getLength() > other.myInt->getLength()){
        return true;
    }
    if(this->neg && !other.neg){
        return false;
    }
    this->myInt->setIteratorFirst();
    other.myInt->setIteratorFirst();
    int match = 0;
    if(this->neg && other.neg){
        while(!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()){
            if(this->myInt->getData() > other.myInt->getData()){
                return false;
            }
            if(this->myInt->getData() == other.myInt->getData()){
                match++;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    else {
        while (!this->myInt->isIteratorNULL() || !other.myInt->isIteratorNULL()) {
            if (this->myInt->getData() < other.myInt->getData()) {
                return false;
            }
            if (this->myInt->getData() == other.myInt->getData()) {
                match++;
            }
            this->myInt->next();
            other.myInt->next();
        }
    }
    if(match == myInt->getLength()){
        return false;
    }
    return true;
}

ostream& operator<<(ostream& out, const BigInteger& other){
    other.myInt->setIteratorFirst();
    while(!other.myInt->isIteratorNULL()){
        out << other.myInt->getData();
        other.myInt->next();
    }
    return out;
}

ifstream& operator>>(ifstream& in, BigInteger& other){
    string item;
    in >> item;
    for(char c : item){
        other.myInt->insertLast(c - '0');
    }
    return in;
}