//
// Created by Kaih White on 12/4/2021.
//

#include "UPCEntry.h"
#include <sstream>
#include <iostream>

UPCEntry::UPCEntry() {
}

UPCEntry::UPCEntry(string line) {
    stringstream s(line); // create a string stream of the line
    string item;
    getline(s, item, ','); // grab the data before the first comma (the UPC number)
    stringstream n(item); // turn the string into a stringstream so that it easily converts into an integer
    n >> upc; // store info into an integer
    getline(s, item, ','); // get the data before the next comma (the description)
    desc = item; // store the string into the description (type string)
}
