#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "HashTable.h"
#include "NaiveTable.h"

// Constructors
NaiveTable::NaiveTable() : HashTable() {};
NaiveTable::NaiveTable(size_t S) : HashTable(S) {};

NaiveTable::~NaiveTable() {}; // Destructor

// Naive Hash Function: char_sum % table_size
int NaiveTable::hash(std::string val) const {
    const size_t sum = std::accumulate(val.begin(), val.end(), 0);

    return sum % getTableSize();
}