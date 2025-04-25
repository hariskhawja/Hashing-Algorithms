#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include "HashTable.h"
#include "MidSquareTable.h"

// Constructors
MidSquareTable::MidSquareTable() : HashTable() {};
MidSquareTable::MidSquareTable(size_t S) : HashTable(S) {};

MidSquareTable::~MidSquareTable() {}; // Destructor

// Helper Function
int MidSquareTable::getMiddleDigit(int key) const {
    std::string keyAsString = std::to_string(key);

    return static_cast<int>(keyAsString.at(keyAsString.length() / 2));
}

// Mid Square Hash Function: mid_digits(char_sum^2)
int MidSquareTable::hash(std::string val) const {
    const size_t sum = std::accumulate(val.begin(), val.end(), 0);

    return getMiddleDigit(pow(sum, 2));
}