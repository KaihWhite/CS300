//
// Created by Kaih White on 10/11/2021.
//

#include <vector>
#include "PlainBag.h"
#include <iostream>

template <class T>
PlainBag<T>::PlainBag() = default; // default constructor

// Inserts an item into the bag if the maximum capacity has not been reached yet
template <class T>
void PlainBag<T>::insert(T item){ // parameter is item to be inserted
    if(items.size() < 20){ // checks to see if there are less than 20 items in the bag
        items.push_back(item); // if there are less than 20 items, another item can be inserted
    }
    else{
        std::cout << "Already at maximum storage capacity of 20" << std::endl; // no more than 20 items in the bag
    }
}

// Prints the contents of the bag
template <class T>
void PlainBag<T>::print(){
    std::cout << "\nBag content:";
    for( T i : items){ // goes through all the items currently in the bag sequentially
        std::cout << i << " "; // prints the current item
    }
    std::cout << std::endl; // once all items have been printed, the print ends
}

// returns the number of all items in the bag
template <class T>
int PlainBag<T>::size(){
    return items.size(); // returns the size as an integer
}

// checks the bag to see if it is empty
template <class T>
bool PlainBag<T>::checkFull(){
    if( items.size() > 19){ // if there are more than 19 items, hence the bag is full
        return true;
    }
    return false; // otherwise, the bag is not full
}

// checks the bag to see if it is empty
template <class T>
bool PlainBag<T>::checkEmpty(){
    if( items.empty()){ // checks to see if there are no items in the bag, hence the bag is empty
        return true;
    }
    return false; // otherwise, the bag is not empty
}

// checks to see if a specific item is in the bag
template <class T>
bool PlainBag<T>::inBag(T item){ // parameter is the item to be looked for
    for (T i : items) { // go through all items in the bag sequentially
        if (i == item){ // if current item in bag is equal to item being looked for
            return true; // item was found
        }
    }
    return false; // item was never found
}

// Returns the amount of copies of a certain item in the bag
template <class T>
int PlainBag<T>::itemCount(T item){ // parameter is the item to be looked for
    int count = 0; // the count of the certain item
    for(T i : items){ // goes through the bag's items sequentially
        if(item == i){ // if the item to be looked for is equivalent to the current item from the bag
            count++; // add one to the count of the certain item
        }
    }
    return count; // return the count of copies of the item
}

// removes an item from the bag
template <class T>
void PlainBag<T>::remove(T item){ // parameter is item to be removed
    for(int i = 0 ; i < items.size() ; i++){
        if(items[i] == item){
            items.erase(items.begin() + i);
            return;
        }
    }
}

// clears the bag -- removes all items from the bag
template <class T>
void PlainBag<T>::clear(){
    items.clear();
}
