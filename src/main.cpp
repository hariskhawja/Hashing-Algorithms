#include <iostream>
#include <fstream>
#include "NaiveTable.h"

int main() {
    std::ifstream words_alpha;
    words_alpha.open("../inputFiles/words_alpha.txt");

    NaiveTable nt {};

    nt.insert(words_alpha);
    nt.assessHashFunction();

    words_alpha.close();
    words_alpha.open("../inputFiles/words_alpha.txt");


    words_alpha.close();

    return 0;
}