#ifndef MIDSQUARETABLE_H
#define MIDSQUARETABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"

// Hash Table Implementation With a Mid Square Hash Function: mid_digits(char_sum^2)
class MidSquareTable : public HashTable {
    public:
        MidSquareTable(); // Constructor
        MidSquareTable(size_t S); // Constructor with User-Defined Slot Number
        virtual ~MidSquareTable(); // Destructor
        
    private:
        virtual int hash(std::string key) const override;
        int getMiddleDigit(int key) const;
};

#endif