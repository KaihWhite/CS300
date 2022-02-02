//
// Created by Kaih White on 10/11/2021.
//

#include "MagicChangeBag.h"

template <class T>
MagicChangeBag<T>::MagicChangeBag() = default; // default constructor for Magic Bag

// Insert function for Magic bag that inserts items into a hidden vector that cannot be seen
template <class T>
void MagicChangeBag<T>::insert(T item){ // parameter is item to be inserted
    hidden.push_back(item);
}

// Removes one item, but them reveals the rest of the items in the bag
template <class T>
void MagicChangeBag<T>::remove(T item){ // parameter is item to be removed
    int count = 0;
    for(T i : hidden){ // goes through the items in the bag sequentially
        if(i != item){ // if current item in the bag is not the item being removed
            PlainBag<T>::items.push_back(i); // then add current item to visible items in bag
        }
        else{ // if current item is the item to be removed
            if(count == 0){ // checks to see if one item has already been removed
                count++; // if an items has not been removed, check that an item is to be removed
            }
            else{
                PlainBag<T>::items.push_back(i); // if an item has already been removed, add the item to visible items
            }
        }
    }
    hidden.clear(); // clears the hidden vector. The only item left is the one being removed.
}
