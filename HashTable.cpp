#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "HashTable.h"

HashTable::HashTable() : table{HashTable::defaultSize} {}
HashTable::HashTable(size_t S) : table{S} {}

HashTable::~HashTable() {
    for (auto &i : table) {
        while (i) {
            Node* temp = i;
            i = i->next;
            delete temp;
        }
    }
}

void HashTable::insert(std::string val) {
    const size_t tableSlot = hash(val);

    Node* newValNode = new Node{val, table.at(tableSlot)};
    table.at(tableSlot)->next = newValNode;
}

bool HashTable::lookup(std::string val) const {
    const size_t tableSlot = hash(val);

    Node* cur = table.at(tableSlot);

    while (cur) {
        if (cur->val == val) return true;

        cur = cur->next;
    }

    return false;
}

bool HashTable::remove(std::string val) {
    const size_t tableSlot = hash(val);

    Node* cur = table.at(tableSlot);

    // At Head
    if (cur->val == val) {
        Node* temp = cur->next;
        delete cur;
        table.at(tableSlot) = temp;
        return true;
    }

    while (cur->next) {
        if (cur->next->val == val) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return true;
        }

        cur = cur->next;
    }

    return false;
}

void HashTable::listAll() const {
    std::cout << "Hash Code | Bucket Elements" << std::endl;
    for (size_t i = 0; i < getTableSize(); i++) {
        if (table.at(i)) {
            std::cout << i;
            Node* cur = table.at(i);
            
            while (cur) {
                std::cout << " " << cur->val;
                cur = cur->next;
            }

            std::cout << std::endl;
        }
    }
}

/*
Strong Hash Functions Should:
    1. Distribute keys as much as possible
    2. Minimise collisions
    3. Be computationaly fast
*/
void HashTable::assessHashFunction() const {
    std::vector<size_t> bucketSizes {getTableSize(), 0};
    size_t totalItems = 0;

    for (size_t i = 0; i < getTableSize(); i++) {
        Node* cur = table.at(i);

        while (cur) {
            bucketSizes.at(i)++;
            totalItems++;

            cur = cur->next;
        }
    }

    // Basic Stats
    size_t empty = std::count(bucketSizes.begin(), bucketSizes.end(), 0);
    size_t min = *std::min_element(bucketSizes.begin(), bucketSizes.end());
    size_t max = *std::max_element(bucketSizes.begin(), bucketSizes.end());
    double averageSize = static_cast<double>(totalItems / getTableSize());
    
    // Variance Calculation
    double variance = 0;
    for (auto &size : bucketSizes) variance += (size - averageSize) * (size - averageSize);
    
    // Standard Deviation Calculation
    variance /= getTableSize();
    double standardDeviation = std::sqrt(variance);

    std::cout << "Load Factor: " << averageSize << std::endl; // Same as Average
    std::cout << "Empty Buckets: " << empty << "/" << getTableSize() << std::endl;
    std::cout << "Minimum Bucket Size: " << min << std::endl;
    std::cout << "Maximum Bucket Size: " << max << std::endl;
    std::cout << "Average Bucket size: " << averageSize << std::endl;
    std::cout << "Standard Deviation: " << standardDeviation << std::endl;
}

size_t HashTable::getTableSize() const {
    return (size_t)table.size();
}