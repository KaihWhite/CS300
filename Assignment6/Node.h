//
// Created by Kaih White on 12/5/2021.
//

#include "UPCEntry.h"

#ifndef ASSIGNMENT6_NODE_H
#define ASSIGNMENT6_NODE_H

class Node{
public:
    Node* next; // points to next item in linked list
    UPCEntry item; // holds the upc information of this node
};

#endif //ASSIGNMENT6_NODE_H
