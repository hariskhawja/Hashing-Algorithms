#include <iostream>
#include <fstream>
#include "NaiveTable.h"
#include "DivisionTable.h"

int main() {
    std::ifstream words_alpha;
    words_alpha.open("../inputFiles/words_alpha.txt");

    NaiveTable nt {};
    DivisionTable dt {};

    nt.insert(words_alpha);
    nt.assessHashFunction();

    words_alpha.close();
    words_alpha.open("../inputFiles/words_alpha.txt");

    dt.insert(words_alpha);
    dt.assessHashFunction();

    words_alpha.close();

    return 0;
}