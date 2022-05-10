// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string & word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int count = 0;
    for (size_t i = 0; i < CAPACITY; i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            if (table[i].at(j).first != "") {
                count += table[i].at(j).second;
            }
        }
    }
	return count;
}

int WordCount::getNumUniqueWords() const {
    int count = 0;
    for (size_t i = 0; i < CAPACITY; i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            if (table[i].at(j).first != "" && table[i].at(j).second >= 1) {
                count++;
            }
        }
    }
    return count;
}

int WordCount::getWordCount(const std::string & word) const {
    int count = 0;
    std::string validWord = makeValidWord(word);
    for (size_t i = 0; i < CAPACITY; i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            if (table[i].at(j).first == validWord) {
                count = table[i].at(j).second;
            }
        }
    }
    return count;
}
	
int WordCount::incrWordCount(const std::string & word) {
    int count = -1;
    std::string validWord = makeValidWord(word);
    if (validWord == "") {
        return 0;
    }
    size_t index = hash(validWord);
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index].at(i).first == validWord) {
            table[index].at(i).second++;
            count = table[index].at(i).second;
            return count;
        }
    }
    pair<std::string, int> PAIR(validWord, 1);
    table[index].push_back(PAIR);
    count = 1;
    return count;
}

int WordCount::decrWordCount(const std::string & word) {
    int count = 0;
    std::string validWord = makeValidWord(word);
    size_t index = hash(validWord);
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index].at(i).first == validWord && table[index].at(i).second > 1) {
            table[index].at(i).second--;
            count = table[index].at(i).second;
            return count;
        }
        if (table[index].at(i).first == validWord && table[index].at(i).second == 1) {
            table[index].erase(table[index].begin() + i);
            return count;
        }
    }
    count = -1;
    return count;
}

bool WordCount::isWordChar(char c) {
    if (isalpha(c)) {
        return true;
    }
    return false;
}

std::string WordCount::makeValidWord(const std::string & word) {
    std::string validWord = "";

    for (size_t i = 0; i < word.length(); i++) {
        if (isWordChar(word[i]) == true) {
            validWord += tolower(word[i]);
        }
        else if (word[i] == '-' || word[i] == '\'') {
            if (validWord.length() != 0 && i < word.length() - 1) {
                validWord += word[i];
            }
        }
    }
    while (validWord[0] == '-' || validWord[0] == '\'') {
        validWord = validWord.substr(1, validWord.length());
    }
    while (validWord[validWord.length() - 1] == '-' || validWord[validWord.length() - 1] == '\'') {
        validWord = validWord.substr(0, validWord.length() - 1);
    }
    return validWord;
}
