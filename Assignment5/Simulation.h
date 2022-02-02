//
// Created by Kaih White on 11/29/2021.
//

#ifndef ASSIGNMENT5_SIMULATION_H
#define ASSIGNMENT5_SIMULATION_H

#include "Queue.h"
#include <vector>
#include "Customer.h"

class Simulation {
public:
    int avgDelay; // average delay of the customers
    int maxDelay; // max delay of the customers
    Queue<Customer>* line; // pointer to Queue that contains the customers

    Simulation(); // simulation constructor
    void processCustomers(vector<Customer> c); // calculate simulation
    void printStatistics(); // output observations
};

#endif //ASSIGNMENT5_SIMULATION_H
