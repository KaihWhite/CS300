//
// Created by Kaih White on 12/4/2021.
//

#include "twoHashTable.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

bool TwoHashTable::insert(UPCEntry &item) {
    int h1 = item.hash1(tSize); // store first hash index
    int h2 = item.hash2(tSize); // store second hash index

    if(dupeCheck.count(item.upc)){ // checks whether the upc number exists in the dupeCheck set already
        return false; // if it does, return false
    }

    if(tableCount[h1] > tableCount[h2]){ // if the first hash index has a larger bin size than the second
        if(tableCount[h2] == 0){ // if no nodes currently exist in this bin
            table[h2] = new Node; // add a new, first node
            table[h2]->item = item;
            table[h2]->next = nullptr;
            dupeCheck.insert(item.upc); // add upc number to dupeCheck set
            tableCount[h2]++; // increase the size of this bin
            return true;
        }
        else{ // if a node already exists in this bin
            Node* head = table[h2];
            while(head->next != nullptr){ // goes through to the last node of the bin
                head = head->next;
            }
            Node* n = new Node; // add a new node to the end
            n->item = item;
            n->next = nullptr;
            head->next = n; // point the current node to the new last node
            dupeCheck.insert(item.upc); // add upc number to dupeCheck set
            tableCount[h2]++; // increase the size of this bin
            return true;
        }
    }
    else{ // same as previous but for the first hash index
        if(tableCount[h1] == 0){
            table[h1] = new Node;
            table[h1]->item = item;
            table[h1]->next = nullptr;
            dupeCheck.insert(item.upc);
            tableCount[h1]++;
            return true;
        }
        else{
            Node* head = table[h1];
            while(head->next != nullptr){
                head = head->next;
            }
            Node* n = new Node;
            n->item = item;
            n->next = nullptr;
            head->next = n;
            dupeCheck.insert(item.upc);
            tableCount[h1]++;
            return true;
        }
    }
}

TwoHashTable::TwoHashTable(string filename, int tableSize) {
    table = new Node*[tableSize]; // create array of pointers for the HashTable
    tableCount = new int[tableSize]; // create parallel array for counting bin size
    fill(tableCount, tableCount + tableSize, 0); // set all bin size counts to zero
    tSize = tableSize; // store table size variable

    fstream file(filename); // file object
    string item;
    getline(file, item); // grab first line
    while(!file.eof()){ // until end of file
        getline(file, item); // get next line
        UPCEntry add(item); // create UPC object with line information
        insert(add); // add the UPC object to the HashTable
    }
}

Position TwoHashTable::search(UPCEntry &item) {
    Position pos; // empty position
    int h1 = item.hash1(tSize); // first hash index
    int h2 = item.hash2(tSize); // second hash index

    int count = 0; // start bin count at 0

    Node* n = table[h1];
    while(n != nullptr){
         if(n->item.upc == item.upc){ // does the current node contain the UPC object we are looking for?
             pos.indexInTable = h1; // table index
             pos.indexInBin = tableCount[h1] - count - 1; // bin index
             return pos; // return found position
         }
         n = n->next;
         count++; // move to next bin
    }

    count = 0;
    n = table[h2];
    while(n != nullptr){
        if(n->item.upc == item.upc){ // does the current object at this index have the object we are looking for?
            pos.indexInTable = h2;
            pos.indexInBin = tableCount[h2] - count - 1;
            return pos;
        }
        n = n->next;
        count++;
    }
    return pos; // if object was never found, return position of -1, -1
}

float TwoHashTable::getStdDev() {
    return stddev(tableCount, tSize); // return standard dev of bin size
}

TwoHashTable::~TwoHashTable() {
    delete[] tableCount;
    Node* n;
    for(int i = 0; i < tSize; i++){
        n = table[i];
        while(n != nullptr){
            Node* prev = n;
            n = n->next;
            delete prev;
        }
    }
    delete[] table;
}