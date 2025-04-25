#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

class HashTable {
    public:
        HashTable(); // Constructor
        HashTable(size_t S); // Constructor with User-Defined Slot Number
        static const size_t defaultSize = 1000;
        
        void insert(std::string val);

        // True if Operation Successful
        bool lookup(std::string val) const;
        bool remove(std::string val);

        void listAll() const;
        void assessHashFunction() const;

    protected:
        virtual ~HashTable(); // Destructor
        size_t getTableSize() const;

        // Node to Hold Values
        struct Node {
            std::string val;
            Node* next;
        };

    private:
        std::vector<Node*> table; // Table Represented as Vector
        virtual int hash(std::string key) const = 0;
};

#endif