#include "ImprovedDictionary.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>

// Constructor
ImprovedDictionary::ImprovedDictionary() {}

// Overridden menu with Wordle option
void ImprovedDictionary::programMenu() {
    int choice;
    while (true) {
        std::cout << "\n1. Load Dictionary\n2. Search Word\n3. Display Random Word\n4. Cheat at Wordle\n5. Exit\nEnter choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input - enter a number." << std::endl;
            continue;
        }

        if (choice == 1) loadDictionary();
        else if (choice == 2) searchWord();
        else if (choice == 3) displayRandomWord();
        else if (choice == 4) cheatAtWordle();
        else if (choice == 5) break;
        else std::cout << "Invalid choice." << std::endl;
    }
}

// Cheat at Wordle feature
void ImprovedDictionary::cheatAtWordle() {
    if (dictionary.empty()) {
        std::cout << "Error 202601- no dictionary loaded -" << std::endl;
        return;
    }

    std::string gray, yellow, green;
    std::cout << "Enter gray letters (exclude, no commas, e.g. rst): ";
    std::cin >> gray;
    std::cout << "Enter yellow letters (include anywhere, e.g. ae): ";
    std::cin >> yellow;
    std::cout << "Enter green pattern (5 chars, . for unknown, e.g. a..e.): ";
    std::cin >> green;

    // Normalize to lower
    std::transform(gray.begin(), gray.end(), gray.begin(), ::tolower);
    std::transform(yellow.begin(), yellow.end(), yellow.begin(), ::tolower);
    std::transform(green.begin(), green.end(), green.begin(), ::tolower);

    // Find matches
    std::vector<std::string> matches;
    for (const Word& w : dictionary) {
        if (w.isFiveLetters() && w.excludesLetters(gray) && w.includesLetters(yellow) && w.matchesPositions(green)) {
            matches.push_back(w.getName());
        }
    }

    if (matches.empty()) {
        std::cout << "No matching words found." << std::endl;
    } else {
        std::cout << "Matching words:" << std::endl;
        for (const std::string& m : matches) {
            std::cout << m << std::endl;
        }
    }
}