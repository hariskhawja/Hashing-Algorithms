#ifndef DIVISIONTABLE_H
#define DIVISIONTABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"

// Hash Table Implementation With a Division Hash Function: char_sum % large_prime
class DivisionTable : public HashTable {
    public:
        DivisionTable(); // Constructor
        DivisionTable(size_t S); // Constructor with User-Defined Slot Number
        virtual ~DivisionTable(); // Destructor
        
    private:
        virtual int hash(std::string key) const override;
};

#endif