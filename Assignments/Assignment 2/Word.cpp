#include "Word.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Constructor - initialize word data
Word::Word(const string& n, const string& t, const string& d) 
    : name(n), type(t), definition(d) 
{
}

// Return the word name
string Word::getName() const { 
    return name; 
}

// Return the word type
string Word::getType() const { 
    return type; 
}

// Return the definition
string Word::getDefinition() const { 
    return definition; 
}

// Print the word with its type and definitions
void Word::printDefinition() const {
    cout << name << endl;

    // Convert abbreviation to full word type
    string fullType = "(" + type + ")";
    if (type == "n") fullType = "(noun)";
    else if (type == "v") fullType = "(verb)";
    else if (type == "adv") fullType = "(adverb)";
    else if (type == "adj") fullType = "(adjective)";
    else if (type == "prep") fullType = "(preposition)";
    else if (type == "pn") fullType = "(proper noun)";
    else if (type == "n_and_v") fullType = "(noun and verb)";
    else if (type == "misc") fullType = "(misc)";
    
    cout << fullType << endl;

    // Print each definition on a new line
    string def = definition;
    size_t pos = 0;
    
    while ((pos = def.find(";  ")) != string::npos) {
        cout << def.substr(0, pos) << endl;
        def = def.substr(pos + 3);
    }
    
    // Print the last definition
    if (!def.empty()) {
        cout << def << endl;
    }
}

// Check if word has exactly 5 letters
bool Word::isFiveLetters() const {
    return name.length() == 5;
}

// Check if word does NOT contain any gray letters
bool Word::excludesLetters(const string& gray) const {
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    
    for (int i = 0; i < gray.length(); i++) {
        char c = tolower(gray[i]);
        if (lowerName.find(c) != string::npos) {
            return false;  // Found a gray letter, so exclude this word
        }
    }
    return true;  // No gray letters found
}

// Check if word contains ALL yellow letters
bool Word::includesLetters(const string& yellow) const {
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    
    for (int i = 0; i < yellow.length(); i++) {
        char c = tolower(yellow[i]);
        if (lowerName.find(c) == string::npos) {
            return false;  // Yellow letter is missing
        }
    }
    return true;  // All yellow letters are present
}

// Check if word matches the green pattern (. means any letter)
bool Word::matchesPositions(const string& green) const {
    // Must be exactly 5 characters
    if (green.length() != 5) {
        return false;
    }
    
    // Check each position
    for (int i = 0; i < 5; i++) {
        if (green[i] != '.') {  // . means any letter is OK
            if (tolower(green[i]) != tolower(name[i])) {
                return false;  // Letter at this position doesn't match
            }
        }
    }
    return true;  // All positions match
}