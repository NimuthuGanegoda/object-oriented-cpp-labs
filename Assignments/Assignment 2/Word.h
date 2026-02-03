// Prologue: Class to store word information
// Purpose: Hold and display word data
// Author: Nimuthu Ganegoda
// Date: February 2026

#pragma once
#include <string>
using namespace std;

class Word {
private:
    string name;
    string type;
    string definition;

public:
    // Constructor
    Word(const string& n, const string& t, const string& d);

    // Getter functions
    string getName() const;
    string getType() const;
    string getDefinition() const;

    // Display functions
    void printDefinition() const;

    // Wordle helper functions
    bool isFiveLetters() const;
    bool excludesLetters(const string& gray) const;
    bool includesLetters(const string& yellow) const;
    bool matchesPositions(const string& green) const;
};