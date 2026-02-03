#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <random>
#include <algorithm>
#include <cctype>

// Constructor
Dictionary::Dictionary() {}

// Load with exceptions
bool Dictionary::loadDictionary() {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening dictionary file: " + filename);
        }

        dictionary.clear();
        std::string line;
        std::getline(file, line);  // Skip header "2026-S0 dictionary contains..."

        while (std::getline(file, line)) {
            if (line.empty()) continue;

            size_t pos = line.find(';');
            std::string n = (pos != std::string::npos) ? line.substr(0, pos) : line;

            if (!std::getline(file, line)) throw std::runtime_error("Incomplete word entry: missing type");
            pos = line.find(';');
            std::string t = (pos != std::string::npos) ? line.substr(0, pos) : line;

            if (!std::getline(file, line)) throw std::runtime_error("Incomplete word entry: missing definition");
            pos = line.rfind(';');
            std::string d = (pos != std::string::npos) ? line.substr(0, pos) : line;

            std::getline(file, line);  // Blank line

            dictionary.emplace_back(n, t, d);
        }

        std::cout << "Dictionary loaded with " << dictionary.size() << " words." << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Load error: " << e.what() << std::endl;
        return false;
    }
}

// Search (case-insensitive)
void Dictionary::searchWord() {
    if (dictionary.empty()) {
        std::cout << "Error 202601- no dictionary loaded -" << std::endl;
        return;
    }

    std::string input;
    std::cout << "Enter word to search: ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (const Word& w : dictionary) {
        std::string nameLower = w.getName();
        std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        if (nameLower == input) {
            int defCount = 1;  // Count definitions
            std::string def = w.getDefinition();
            size_t pos = 0;
            while ((pos = def.find(";  ", pos)) != std::string::npos) {
                defCount++;
                pos += 3;
            }
            std::cout << "Word Found – with " << defCount << " definitions" << std::endl;
            w.printDefinition();
            return;
        }
    }
    std::cout << "word not found." << std::endl;
}

// Random word
void Dictionary::displayRandomWord() {
    if (dictionary.empty()) {
        std::cout << "Error 202601- no dictionary loaded -" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, dictionary.size() - 1);
    dictionary[distr(gen)].printDefinition();
}

// Base menu
void Dictionary::programMenu() {
    int choice;
    while (true) {
        std::cout << "\n1. Load Dictionary\n2. Search Word\n3. Display Random Word\n4. Exit\nEnter choice: ";
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
        else if (choice == 4) break;
        else std::cout << "Invalid choice." << std::endl;
    }
}