#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include "HashTable.h"

// Constructors
HashTable::HashTable() : table{HashTable::defaultSize} {}
HashTable::HashTable(size_t S) : table{S} {}

// Destructor
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
    table.at(tableSlot) = newValNode;
}

void HashTable::insert(std::ifstream &file) {
    std::string word;
    while (file >> word) {
        insert(word);
    }
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
    std::vector<size_t> bucketSizes(getTableSize(), 0);
    std::map<std::string, size_t> histogram = {
        {"0-99   ", 0},
        {"100-199", 0},
        {"200-299", 0},
        {"300-399", 0},
        {"400-499", 0},
        {"500-599", 0},
        {"600-699", 0},
        {"700-799", 0},
        {"800-899", 0},
        {"900-999", 0}
    };

    size_t totalItems = 0;

    for (size_t i = 0; i < getTableSize(); i++) {
        Node* cur = table.at(i);
        size_t curSize = 0;

        while (cur) {
            bucketSizes.at(i)++;
            curSize++;

            cur = cur->next;
        }
        
        totalItems += curSize;

        if (i < 100) histogram.at("0-99   ") += curSize;
        else if (i < 200) histogram.at("100-199") += curSize;
        else if (i < 300) histogram.at("200-299") += curSize;
        else if (i < 400) histogram.at("300-399") += curSize;
        else if (i < 500) histogram.at("400-499") += curSize;
        else if (i < 600) histogram.at("500-599") += curSize;
        else if (i < 700) histogram.at("600-699") += curSize;
        else if (i < 800) histogram.at("700-799") += curSize;
        else if (i < 900) histogram.at("800-899") += curSize;
        else histogram.at("900-999") += curSize;
    }

    // Basic Stats
    size_t empty = std::count(bucketSizes.begin(), bucketSizes.end(), 0);
    size_t min = *std::min_element(bucketSizes.begin(), bucketSizes.end());
    size_t max = *std::max_element(bucketSizes.begin(), bucketSizes.end());
    double averageSize = static_cast<double>(totalItems) / getTableSize();
    
    // Variance Calculation
    double variance = 0;
    for (auto &size : bucketSizes) {
        variance += (size - averageSize) * (size - averageSize);
    }
    
    // Standard Deviation Calculation
    variance /= getTableSize();
    double standardDeviation = sqrt(variance);
    
    // Hash Function Data
    std::cout << "------------------" << std::endl;
    std::cout << "Hash Function Data" << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << "Total Items: " << totalItems << std::endl;
    std::cout << "Load Factor: " << averageSize << std::endl; // Same as Average
    std::cout << "Empty Buckets: " << empty << "/" << getTableSize() << std::endl;
    std::cout << "Minimum Bucket Size: " << min << std::endl;
    std::cout << "Maximum Bucket Size: " << max << std::endl;
    std::cout << "Average Bucket size: " << averageSize << std::endl;
    std::cout << "Standard Deviation: " << standardDeviation << std::endl;

    // Bucket Distribution as Histogram
    std::cout << "-----------------------" << std::endl;
    std::cout << "Bucket Distribution" << std::endl;
    std::cout << "-----------------------" << std::endl;

    for (auto &pair : histogram) {
        std::cout << pair.first << ": ";

        for (size_t i = 0; i < pair.second; i += 1000) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

size_t HashTable::getTableSize() const {
    return (size_t)table.size();
}