#include <iostream>
#include <fstream>
#include "NaiveTable.h"
#include "MultiplicationTable.h"
#include "MidSquareTable.h"

int main() {
    std::ifstream words_alpha;
    words_alpha.open("../inputFiles/words_alpha.txt");

    NaiveTable nt {};

    nt.insert(words_alpha);
    nt.assessHashFunction();
    
    words_alpha.close();
    words_alpha.open("../inputFiles/words_alpha.txt");

    MultiplicationTable mt {};

    mt.insert(words_alpha);
    mt.assessHashFunction();

    words_alpha.close();
    words_alpha.open("../inputFiles/words_alpha.txt");

    MidSquareTable mst {};

    mst.insert(words_alpha);
    mst.assessHashFunction();

    words_alpha.close();

    return 0;
}