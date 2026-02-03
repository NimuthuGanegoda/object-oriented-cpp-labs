// Prologue: Base class for dictionary operations
// Purpose: Load dictionary, search words, display random words
// Author: Nimuthu Ganegoda
// Date: February 2026

#pragma once
#include "Word.h"
#include <vector>
#include <string>

using namespace std;

class Dictionary {
protected:
    vector<Word> dictionary;
    string filename;

public:
    // Constructor
    Dictionary();

    // Main functions
    bool loadDictionary();
    void searchWord();
    void displayRandomWord();
    virtual void programMenu();
};