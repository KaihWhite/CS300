/*
    Author: Fatma C Serce
    Date: October, 2019
    Description: This is simple implementation of Queue abstract data type. 
    The class provide abstract functions for the following operations:
    - enqueue
    - dequeue
    - isEmpty
    - isFull
    
    The class also provides a concrete method called, display, which writes the contents
    of queue object into the given output stream object
*/

#ifndef QUEUE_ADT
#define QUEUE_ADT
#include <iostream>

using namespace std;

template <class T>
class QueueADT{
    public:
        virtual void enqueue(const T&) = 0; // adds object to end of queue
        virtual void dequeue() = 0; // removes object from front of queue
        virtual T& qfront() = 0; // peeks at object at front of queue
        virtual bool isEmpty() = 0; // checks whether the queue is empty
        virtual bool isFull() = 0;   // checks whether the queue is full
       
};

#endif