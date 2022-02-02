#include <iostream>
#include <fstream>
#include "Customer.h"
#include "Simulation.h"
#include <vector>

using namespace std;



//please don't modify main function
int main() {

    vector<Customer> customers = readCustomers(); //read list of customers and arrival times from a file
    Simulation s;
    cout << "Processing Customers:" << endl;
    s.processCustomers(customers); //simulates the teller serving the customers in the queue
    s.printStatistics();  // prints out the maxium delay and the average delay.

    return 0;
}