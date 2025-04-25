#ifndef NAIVETABLE_H
#define NAIVETABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"

// Hash Table Implementation With a Naive Hash Function: char_sum % table_size; aka Division Method
class NaiveTable : public HashTable {
    public:
        NaiveTable(); // Constructor
        NaiveTable(size_t S); // Constructor with User-Defined Slot Number
        virtual ~NaiveTable(); // Destructor
        
    private:
        virtual int hash(std::string key) const override;
};

#endif