#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include <set>
#include "Node.h"

#ifndef ASSIGNMENT6_twoHashTable_H
#define ASSIGNMENT6_twoHashTable_H

using namespace std;


class TwoHashTable
{
private:
    Node** table;// Array of node pointers of which contain the UPC information and pointers to the next item in the bin
    int* tableCount; // Parallel array of table that contains the number of nodes (size) of each linked list (bins)
    int tSize; // Total size of table array
    set<int> dupeCheck; // Set that helps with stopping duplicate entries


    float stddev(int *binLengths, int tableSize) // checks the standard deviation of bin lengths
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }

public:
    TwoHashTable(string filename, int tableSize); // constructor of HashTable which reads in csv file
    ~TwoHashTable();
    bool insert(UPCEntry &item); // returns true if successful, false otherwise.
    Position search(UPCEntry &item); // if not found, return the default position with both indices set as -1
    float getStdDev(); // returns the standard deviation of bin lengths
};

#endif