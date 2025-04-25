#ifndef MULTIPLICATIONTABLE_H
#define MULTIPLICATIONTABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"

// Hash Table Implementation With a Multiplication Hash Function: floor(table_size * frac(char_sum * A))
class MultiplicationTable : public HashTable {
    public:
        MultiplicationTable(); // Constructor
        MultiplicationTable(size_t S); // Constructor with User-Defined Slot Number
        virtual ~MultiplicationTable(); // Destructor
        
    private:
        virtual int hash(std::string key) const override;
};

#endif