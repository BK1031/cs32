//
// Created by Bharat Kathi on 5/10/22.
//

#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
using namespace std;

int main() {
    cout << "STARTING LAB 6 TESTS" << endl;

    WordCount wc;
    wc.addAllWords("peter piper picked a peck of pickled piper peck of peter");

    cout << "======= SORTED WORD DUMP =======" << endl;
    wc.dumpWordsSortedByWord(cout);
    cout << endl;

    cout << "======= OCCURRENCE SORTED WORD DUMP =======" << endl;
    wc.dumpWordsSortedByOccurence(cout);
    cout << endl;

    return 0;
}