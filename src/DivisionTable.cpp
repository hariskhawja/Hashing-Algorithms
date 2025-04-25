#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "HashTable.h"
#include "DivisionTable.h"

// Constructors
DivisionTable::DivisionTable() : HashTable() {};
DivisionTable::DivisionTable(size_t S) : HashTable(S) {};

DivisionTable::~DivisionTable() {}; // Destructor

// Division Hash Function: char_sum % large_prime
int DivisionTable::hash(std::string val) const {
    const size_t sum = std::accumulate(val.begin(), val.end(), 0);
    const int prime = 991; // Randomly Selected Large Prime < table_size

    return sum % prime;
}