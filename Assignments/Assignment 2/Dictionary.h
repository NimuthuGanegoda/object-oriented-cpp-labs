// Prologue: Base class for dictionary management. Purpose: Load, search, random display, menu. Input: filename. Output: methods. Author: Nimuthu Ganegoda. Date: February 2026.
#pragma once
#include "Word.h"
#include <vector>
#include <string>

class Dictionary {
protected:
    std::vector<Word> dictionary;
    std::string filename = "dictionary_2026S0.txt";

public:
    Dictionary();
    bool loadDictionary();  // Throws exceptions on failure
    void searchWord();
    void displayRandomWord();
    virtual void programMenu();
};