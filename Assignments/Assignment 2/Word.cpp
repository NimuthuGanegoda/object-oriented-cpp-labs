#include "Word.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

// Constructor
Word::Word(const std::string& n, const std::string& t, const std::string& d) : name(n), type(t), definition(d) {}

// Getters
std::string Word::getName() const { return name; }
std::string Word::getType() const { return type; }
std::string Word::getDefinition() const { return definition; }

// Print formatted definition
void Word::printDefinition() const {
    std::cout << name << std::endl;

    // Map type to full name (as per brief Table 1)
    std::string fullType = "(" + type + ")";  // Fallback
    if (type == "n") fullType = "(noun)";
    else if (type == "v") fullType = "(verb)";
    else if (type == "adv") fullType = "(adverb)";
    else if (type == "adj") fullType = "(adjective)";
    else if (type == "prep") fullType = "(preposition)";
    else if (type == "pn") fullType = "(proper noun)";
    else if (type == "n_and_v") fullType = "(noun and verb)";
    else if (type == "misc") fullType = "(misc)";
    std::cout << fullType << std::endl;

    // Split and print definitions on separate lines (split on ";  ")
    std::string def = definition;
    size_t pos = 0;
    while ((pos = def.find(";  ")) != std::string::npos) {
        std::cout << def.substr(0, pos) << std::endl;
        def.erase(0, pos + 3);  // Remove ";  "
    }
    std::cout << def << std::endl;
}

// Wordle checks
bool Word::isFiveLetters() const {
    return name.length() == 5;
}

bool Word::excludesLetters(const std::string& gray) const {
    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    for (char c : gray) {
        char lowerC = std::tolower(c);
        if (lowerName.find(lowerC) != std::string::npos) return false;
    }
    return true;
}

bool Word::includesLetters(const std::string& yellow) const {
    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    for (char c : yellow) {
        char lowerC = std::tolower(c);
        if (lowerName.find(lowerC) == std::string::npos) return false;
    }
    return true;
}

bool Word::matchesPositions(const std::string& green) const {
    if (green.length() != 5) return false;
    for (size_t i = 0; i < 5; ++i) {
        if (green[i] != '.' && std::tolower(green[i]) != std::tolower(name[i])) return false;
    }
    return true;
}