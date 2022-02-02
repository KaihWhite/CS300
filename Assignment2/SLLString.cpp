//
// Created by Kaih White on 10/20/2021.
//

#include "SLLString.h"
#include <string>
#include <iostream>

// Default constructor
SLLString::SLLString() {
    head = new Node; // beginning of new string, but is empty
}

// Copy constructor that takes in a regular string
SLLString::SLLString(const std::string& other){
    head = new Node; // beginning of newly created string
    Node* n = head;
    for(int i = 0; i < other.size(); i++){ // goes through entire string
        if ( i < other.size() - 1) { // creates new nodes in linked list until no more new nodes are needed
            Node *next = new Node;
            n -> go = next;
            n -> item = other[i];
            n = next; // To next node
        }
        else { // fills in last node without creating a new node
            n -> item = other[i];
        }
    }
    n -> go = nullptr; // end of string
}

// Destructor: deletes the SLLString
SLLString::~SLLString(){
    if(head != nullptr) {
        Node *n = head -> go;
        delete head; // delete head node
        head = nullptr;
        while (n != nullptr) {
            if(n -> go != nullptr){ // deletes all middle nodes
                Node *prev = n;
                n = n -> go;
                delete prev;
                prev = nullptr;
            }
            else{ // deletes last node
                delete n;
                n = nullptr;
            }
        }
    }
}

// Copy constructor that takes in another SLLString
SLLString::SLLString(const SLLString& other){
    head = new Node; // beginning of newly created string
    Node* n = head;
    Node* o = other.head;
    while(o != nullptr){ // goes through entire string
        if( o -> go != nullptr) { // creates new nodes to fill in until no more new nodes are needed
            Node *next = new Node;
            n -> go = next;
            n -> item = o -> item;
            n = next;
        }
        else{ // fills in last node
            n -> item = o -> item;
        }
        o = o -> go;
    }
    n -> go = nullptr; // end of string
}

// Assignment operator
SLLString& SLLString::operator= (const SLLString& other){
    Node* n = head; // takes previously constructed head node
    Node* o = other.head;
    while(o != nullptr){ // goes through entire string
        if( o -> go != nullptr) { // creates new nodes and fills them in as needed
            Node *next = new Node;
            n -> go = next;
            n -> item = o -> item;
            n = next;
        }
        else{ // fills in last node without creating any new ones
            n -> item = o -> item;
        }
        o = o -> go;
    }
    n -> go = nullptr; // end of string
    return *this;
}

// Returns the length of the string
int SLLString::length() const{
    Node* n = head;
    int count = 0;
    while(n != nullptr){ // goes through entire string
        count++; // counts nodes
        n = n -> go; // next node
    }
    return count; // return number of nodes counted
}

// Allow SSLStrings to be concatenated together
SLLString& SLLString::operator+= (const SLLString& other){
    Node* n = head;
    Node* o = other.head;

    while( n -> go != nullptr){ // goes to end of string
        n = n -> go;
    }

    while( o != nullptr){ // goes through the entire other string and adds new nodes to original string
        Node* next = new Node;
        n -> go = next; // new node being added to original string
        next -> item = o -> item; // each added node is filled in along with corresponding item from other string
        n = next;
        o = o -> go;
    }
    n -> go = nullptr; // end of the new string

    return* this;
}

// Allows string to be indexed, thus allowing specific characters to be accessed and modified
char& SLLString::operator[] (const int num) const{
    Node* n = head;
    for(int i = 0; i < num; i++){ // goes to desired index in linked list
        n = n -> go;
    }
    return n -> item; // returns item stored in desired node
}

// Finds the substring, given as a SLLstring, in the string and returns the location of the first character
int SLLString::findSubstring(const SLLString& substring) const{
    Node* n = head;
    Node* ohead = substring.head;
    int count = 0; // location that will be returned if substring is found
    while(n != nullptr){
        if(ohead -> item == n -> item){ // if letter is equal to beginning of substring
            Node* o = ohead; // placeholder node for other string
            Node* nc = n; // placeholder node for original string
            while(true){
                nc = nc -> go;
                o = o -> go;
                if (o == nullptr){ // checks to see if end of substring was reached
                    return count; // if it was, return the starting location of the substring in the original string
                }
                if(nc -> item != o -> item){ // if a character does not match
                    break; // continue looking for substring in the rest of original string
                }
            }

        }
        n = n -> go;
        count++; // move potential starting location of substring forward
    }
    std::cout << "Given substring does not exist in this string." << std::endl;
    return 0; // if the substring doesn't exist within the string, returns 0
}

// Finds the substring in the string and returns the location of the first character if it exists, otherwise returns 0
int SLLString::findSubstring(const std::string &substring) const{
    Node* n = head;
    int count = 0;
    while(n != nullptr){
        if(substring[0] == n -> item){
            Node* nc = n;
            int i = 1;
            while(true){
                nc = nc -> go;
                if (i > substring.size() - 1){ // end of substring reached without a mismatch
                    return count; // match found, return starting location
                }
                if(nc -> item != substring[i]){ // character in the string and potentially found substring do not match
                    break; // continue looking for substring
                }
                i++;
            }
        }
        n = n -> go;
        count++; // move potential starting location forward
    }
    std::cout << "Given substring does not exist in this string." << std::endl;
    return 0; // substring was not found
}

// Erases every instance of the character in the string
void SLLString::erase(char c){
    Node* n = head;
    int count = 0;
    while(n -> go != nullptr){
        Node* prev = n; // previous node
        n = n -> go; // middle node to potentially be deleted
        Node* next = n -> go; // next node
        if(!count){ // checks if this is the start of the list
            if(prev -> item == c) {
                delete prev;
                head = n; // moves head forward
                continue;
            }
        }
        if(n -> item == c){
            delete n; // removes middle node
            prev -> go = next; // points previous node to next node
            n = prev; // continues checkin list starting from previous node
        }
        if(n -> go == nullptr){ // checks the very last node to see if it is a character that needs to be erased
            if(n -> item == c){
                delete n; // remove last node
                prev -> go = nullptr; // new end of string where node previously was
                n = prev;
            }
        }
        count++;
    }
}

// Allows SLLString to be used with the cout statment as to be printed to the console directly
std::ostream& operator<<(std::ostream& out, const SLLString& str){
    Node* n = str.head;
    while(n != nullptr){ // goes through entire string
        out << n -> item; // adds item to the outstream object
        n = n -> go;
    }
    return out; // returns outstream object to be printed
}

