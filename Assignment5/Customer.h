//
// Created by Kaih White on 11/29/2021.
//

#ifndef ASSIGNMENT5_CUSTOMER_H
#define ASSIGNMENT5_CUSTOMER_H

#include <vector>



class Customer {
public:
    int arrival; // arrival time of customer
    int duration; // duration time of customer being helped

    Customer(); // constructor
    Customer(int a, int d); // constructor with arrival time (int) and duration (int) inputs
};

std::vector<Customer> readCustomers(); // reads the input file and returns a vector of all customers

#endif //ASSIGNMENT5_CUSTOMER_H
