//
// Created by Kaih White on 11/29/2021.
//

#include "Customer.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Customer::Customer() : arrival(0), duration(0){}

Customer::Customer(int a, int d) : arrival(a), duration(d){}

vector<Customer> readCustomers() {
    string item;
    int a, d; // arrival, duration
    vector<Customer> customers; // vector, customers, to be returned
    std::fstream file("data2.txt"); // input file
    file >> item; // get first line, number of customers
    while(!file.eof()){ // until end of file
        file >> item; // take first character
        stringstream s(item); // convert to string
        s >> a; // first number, arrival
        file >> item; // take second character
        stringstream v(item); // convert to string
        v >> d; // second number, duration
        Customer c(a, d); // create customer with arrival (a) and duration (d)
        customers.push_back(c); // add to customers
    }
    return customers;
}