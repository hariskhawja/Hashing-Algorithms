#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

class HashTable {
    public:
        HashTable(); // Constructor
        HashTable(size_t S); // Constructor with User-Defined Slot Number
        static const size_t defaultSize = 1000;
        
        // True if Operation Successful
        bool lookup(std::string val) const;
        bool insert(std::string val);
        bool remove(std::string val);

        void listAll() const;
        void hashData() const;

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
        virtual size_t hash(std::string key) const = 0;
        const size_t size;
};

#endif