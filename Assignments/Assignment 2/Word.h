// Prologue: Class for storing and printing a dictionary word. Purpose: Encapsulate word data and provide methods for display and Wordle checks. Input: name/type/definition. Output: getters/print. Author: Nimuthu Ganegoda. Date: February 2026.
#pragma once
#include <string>

class Word {
private:
    std::string name;
    std::string type;
    std::string definition;

public:
    Word(const std::string& n, const std::string& t, const std::string& d);

    std::string getName() const;
    std::string getType() const;
    std::string getDefinition() const;

    void printDefinition() const;  // Prints name, full type in brackets, definitions on separate lines

    // Wordle helper methods
    bool isFiveLetters() const;
    bool excludesLetters(const std::string& gray) const;  // No gray letters in word
    bool includesLetters(const std::string& yellow) const;  // All yellow letters present anywhere
    bool matchesPositions(const std::string& green) const;  // Green pattern like "a..e." (5 chars, . = any)
};