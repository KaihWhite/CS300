#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
using namespace std;

struct UPCEntry
{
    long long upc = -1; // UPCEntry object starts with an "unknown" number
    string desc = ""; // starts with no description
    UPCEntry(); // default constructor, which doesn't do anything
    UPCEntry(string line); // constructor with string input. Takes a line and grabs the UPC number and description

    int hash1(int tableSize)
    {
        return upc % tableSize;
    }

    int hash2(int tableSize)
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }
};
#endif