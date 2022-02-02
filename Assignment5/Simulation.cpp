//
// Created by Kaih White on 11/29/2021.
//

#include "Simulation.h"
#include "Queue.cpp"

Simulation::Simulation() :avgDelay(0), maxDelay(0) {}


void Simulation::processCustomers(vector<Customer> c) {
    line = new Queue<Customer>(c); // create queue on the heap and point to it with line
    int customerCount = line->getCount(); // get number of customers
    int Time = 0; // time starts at 0
    int delaySum = 0; // the total delay of the customers

    if(line->isEmpty()){
        avgDelay = -1;
        maxDelay = -1;
        return;
    }

    while(!line->isEmpty()){ // until no customer is left in line
        int currentDelay = Time - line->qfront().arrival; // the delay the next customer will have less their arrival
        delaySum += currentDelay; // increase the sum of delay

        if(currentDelay > maxDelay){
            maxDelay = currentDelay; // change to new max
        }

        Time += line->qfront().duration; // skip time to beginning of next customer
        line->dequeue(); // remove last customer from the line
    }
    avgDelay = delaySum / customerCount;
    delete line;
}

void Simulation::printStatistics() {
    cout << "Output:\nMax Delay = " << maxDelay << "\nAverage Delay = " << avgDelay << endl;
}