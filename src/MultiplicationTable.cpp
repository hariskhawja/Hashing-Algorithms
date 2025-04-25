#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include "HashTable.h"
#include "MultiplicationTable.h"

// Constructors
MultiplicationTable::MultiplicationTable() : HashTable() {};
MultiplicationTable::MultiplicationTable(size_t S) : HashTable(S) {};

MultiplicationTable::~MultiplicationTable() {}; // Destructor

// Multiplication Hash Function: floor(table_size * frac(char_sum * A))
int MultiplicationTable::hash(std::string val) const {
    const size_t sum = std::accumulate(val.begin(), val.end(), 0);
    const double A = 0.6180339887; // Randomly Selected A Value: Golden Ratio

    return static_cast<int>(floor( getTableSize() * (sum*A - floor(sum*A)) ));
}