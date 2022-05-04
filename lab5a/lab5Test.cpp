//
// Created by Bharat Kathi on 5/3/22.
//
#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"

using std::cout;
using std::endl;

int main() {
    cout << "STARTING LAB 5 TESTS" << endl;

    WordCount cars;

    cout << "======= EMPTY HASH =======" << endl;
    assertEquals(0, cars.getTotalWords(), "cars.getTotalWords()", 17);
    assertEquals(0, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 18);
    assertEquals(0, cars.getWordCount("toyota"), "cars.getWordCount(\"toyota\")", 19);
    cout << endl;

    assertTrue(cars.isWordChar('f'), "cars.isWordChar('f')", 22);
    assertTrue(cars.isWordChar('C'), "cars.isWordChar('C')", 23);
    assertEquals(false, cars.isWordChar('$'), "cars.isWordChar('$')", 24);
    assertEquals(false, cars.isWordChar('?'), "cars.isWordChar('?')", 25);
    cout << endl;

    assertEquals("ferrari", cars.makeValidWord("fer31rari6"), "cars.makeValidWord(\"fer31rari6\")", 28);
    assertEquals("honda", cars.makeValidWord("!ho#@nda4"), "cars.makeValidWord(\"!ho#@nda4\")", 29);
    assertEquals("audi", cars.makeValidWord("'aUdi -*"), "cars.makeValidWord(\"'aUdi -*\")", 30);
    assertEquals("mercedes-benz", cars.makeValidWord("Mercedes-Benz"), "cars.makeValidWord(\"Mercedes-Benz\")", 32);
    assertEquals("", cars.makeValidWord("-%^-!--$@=="), "cars.makeValidWord(\"-%^-!--$@==\")", 34);
    cout << endl;

    cout << "======= INCREMENT HASH =======" << endl;
    assertEquals(0, cars.incrWordCount("-%^-!--$@=="), "cars.incrWordCount(\"-%^-!--$@==\")", 36);
    cars.incrWordCount("Mercedes-BENZ");
    assertEquals(1, cars.getTotalWords(), "cars.getTotalWords()", 38);
    assertEquals(1, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 39);
    assertEquals(1, cars.getWordCount("mercedes-benz"), "cars.getWordCount(\"mercedes-benz\")", 40);

    for (int i = 0; i < 14; i++) {
        cars.incrWordCount("Toyota");
    }

    assertEquals(15, cars.getTotalWords(), "cars.getTotalWords()", 46);
    assertEquals(2, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 48);
    assertEquals(14, cars.getWordCount("toyota"), "cars.getWordCount(\"toyota\")", 49);

    cars.incrWordCount("h0onda");
    cars.incrWordCount("AUD1I");
    cars.incrWordCount("Ferr@ari");
    cars.incrWordCount("Ferr@ari@-");

    assertEquals(19, cars.getTotalWords(), "cars.getTotalWords()", 55);
    assertEquals(5, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 56);
    assertEquals(2, cars.getWordCount("ferrari"), "cars.getWordCount(\"ferrari\")", 57);

    cars.incrWordCount("");

    assertEquals(19, cars.getTotalWords(), "cars.getTotalWords()", 61);
    assertEquals(5, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 62);
    assertEquals(0, cars.getWordCount(""), "cars.getWordCount(\"\")", 63);
    cout << endl;

    cout << "======= DECREMENT HASH =======" << endl;

    for (int j = 0; j < 5; j++) {
        cars.decrWordCount("TOYOTA");
    }

    assertEquals(14, cars.getTotalWords(), "cars.getTotalWords()", 72);
    assertEquals(5, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 73);
    assertEquals(9, cars.getWordCount("toyota"), "cars.getWordCount(\"toyota\")", 74);

    for (int k = 0; k < 5; k++) {
        cars.decrWordCount("fer@rari");
    }

    assertEquals(12, cars.getTotalWords(), "cars.getTotalWords()", 80);
    assertEquals(4, cars.getNumUniqueWords(), "cars.getNumUniqueWords()", 81);
    assertEquals(0, cars.getWordCount("ferrari"), "cars.getWordCount(\"ferrari\")", 82);

    return 0;
}