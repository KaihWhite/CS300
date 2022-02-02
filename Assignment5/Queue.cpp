//
// Created by Kaih White on 11/29/2021.
//

#include "Queue.h"

// default constructor
template <class T>
Queue<T>::Queue() : front(0), back(-1), count(0){}

// adds item to the end of queue
template <class T>
void Queue<T>::enqueue(const T &t) {
    if(count < MAX_QUEUE) { // if the queue contains less than the max amount allowed
        back = (back + 1) % MAX_QUEUE; // allows the queue to be added to in a circular fashion by moving the "back"
        items[back] = t; // adds item to the queue's back
        count++; // adds to the queue's size count
    }
    else{
        cout << "Queue is full" << endl;
    }
}

// constructor with vector input
template <class T>
Queue<T>::Queue(vector<T> c) : front(0), back(-1), count(0){
    for(T item : c){ // goes through items in the vector
        enqueue(item); // adds them to the queue
    }
}

// removes item from front of queue
template <class T>
void Queue<T>::dequeue() {
    if(!isEmpty()) { // if the queue is not empty
        front = (front + 1) % MAX_QUEUE; //allows the queue to be removed from in a circular fashion by moving the front
        count--; // reduces the queue's size count
    }
    else{
        cout << "Queue is empty" << endl;
    }
}

// peeks at item at the front of the queue
template <class T>
T& Queue<T>::qfront() {
    if(!isEmpty()) { // if not empty
        return items[front]; // give access to the queue's front item
    }
    else{
        cout << "Queue is empty" << endl;
    }
}

// checks whether the queue is empty
template <class T>
bool Queue<T>::isEmpty() {
    return count == 0; // no items in queue
}

// checks whether the queue is full
template <class T>
bool Queue<T>::isFull() {
    return count == MAX_QUEUE; // max items in queue
}

// returns the number of items currently in queue
template <class T>
int Queue<T>::getCount() {
    return count;
}