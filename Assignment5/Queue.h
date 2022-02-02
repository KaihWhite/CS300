//
// Created by Kaih White on 11/29/2021.
//

#ifndef ASSIGNMENT5_QUEUE_H
#define ASSIGNMENT5_QUEUE_H

#include "QueueADT.h"
#include <vector>

const int MAX_QUEUE = 100; // maximum number of items allowed in queue

template <class T>
class Queue : public QueueADT<T> {
private:
    T items[MAX_QUEUE];
    int front; // index of the front item in the queue
    int back; // index of the back item in the queue
    int count; // number of items in the queue
public:
    Queue(); // constructor
    explicit Queue(vector<T>); // copy constructor with vector input
    void enqueue(const T& t); // adds item to end of queue
    void dequeue(); // removes item from front of queue
    T& qfront(); // peeks at item at the front of the queue
    bool isEmpty(); // checks whether the queue is empty or not
    bool isFull(); // checks whether the queue is full or not
    int getCount(); // returns the number of items currently in queue
};


#endif //ASSIGNMENT5_QUEUE_H
