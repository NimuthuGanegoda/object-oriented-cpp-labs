/*
Your Name: [Put Your Full Name Here]
Student ID: [Your Student Number]
Unit: CSP2104 Object-oriented Programming with C++
Date: January 2026
Purpose: Assignment 1 - Dictionary Program
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  // for transform
#include <cctype>     // for tolower
#include <iomanip>    // for setw in first/last

using namespace std;

// Struct for each word (like a box to hold name, type, and meaning)
struct Word {
    string name;
    string type;
    string definition;
};

// Helper: Change a word to all small letters (for no-case search)
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Helper: Change short type like "n" to full "(noun)"
string getFullType(const string& abbr) {
    if (abbr == "n") return "(noun)";
    if (abbr == "v") return "(verb)";
    if (abbr == "adv") return "(adverb)";
    if (abbr == "adj") return "(adjective)";
    if (abbr == "prep") return "(preposition)";
    if (abbr == "pn") return "(proper noun)";
    if (abbr == "n_and_v") return "(noun and verb)";
    if (abbr == "misc") return "(misc)";
    return "(unknown)";  // If type is weird, say this
}

// Helper: Count how many meanings by counting ';' (add 1 because last one has no ;)
int countDefinitions(const string& def) {
    int count = 0;
    for (char c : def) {
        if (c == ';') count++;
    }
    return count + 1;
}

/*
Function: loadDictionary
Purpose: Read the file and save each word group into the list (vector)
Input: The list to fill (by reference, so it changes the original)
Output: None
Author: [Your Name]
Date: Jan 2026
*/
void loadDictionary(vector<Word>& dict) {
    ifstream file("dictionary_2026S0.txt");
    if (!file) {
        cout << "Error loading file!" << endl;
        return;
    }
    dict.clear();
    string line;
    // FIXED: Skip the first header line (the note about how many words)
    getline(file, line);  // Reads "2026-S0 dictionary contains 105160 words " and ignores it
    
    while (getline(file, line)) {  // Loop to read each group
        if (line.empty()) continue;  // Skip empty lines
        size_t semi = line.find(';');
        if (semi != string::npos) line = line.substr(0, semi);  // Remove ;
        Word w;  // Make a new box for this word
        w.name = line;  // Save name
        
        if (!getline(file, line)) break;  // Get type
        semi = line.find(';');
        if (semi != string::npos) line = line.substr(0, semi);
        w.type = line;  // Save type
        
        if (!getline(file, line)) break;  // Get definition
        semi = line.find_last_of(';');
        if (semi != string::npos) line = line.substr(0, semi);  // Remove last ;
        w.definition = line;  // Save definition
        
        getline(file, line);  // Skip the blank line (don't care if it's not blank)
        
        dict.push_back(w);  // Add the box to the list
    }
    file.close();
    cout << "Loaded " << dict.size() << " words." << endl;
}

/*
Function: searchWord
Purpose: Ask for a word, look in the list, print if found (with meanings on separate lines)
Input: The list to search (const so it doesn't change)
Output: None
Author: [Your Name]
Date: Jan 2026
*/
void searchWord(const vector<Word>& dict) {
    if (dict.empty()) {
        cout << "Error 202601- no dictionary loaded -" << endl;
        return;
    }
    string input;
    cout << "Enter a word: ";
    cin >> input;
    input = toLower(input);  // Make small letters
    
    for (const auto& w : dict) {  // Look at each box in list
        string wName = toLower(w.name);
        if (wName == input) {
            int numDefs = countDefinitions(w.definition);
            cout << "Word Found – with " << numDefs << " definitions" << endl;
            cout << w.name << endl;
            cout << getFullType(w.type) << endl;
            
            // FIXED: Split meanings on ";  " (semicolon + two spaces)
            string def = w.definition;
            size_t pos = 0;
            while ((pos = def.find(";  ")) != string::npos) {  // Look for ";  "
                cout << def.substr(0, pos) << endl;  // Print first part
                def.erase(0, pos + 3);  // Remove up to ";  " (3 chars: ; and two spaces)
            }
            cout << def << endl;  // Print the last part
            return;
        }
    }
    cout << "word not found." << endl;
}

/*
Function: firstAndLast
Purpose: For each letter A-Z, find and print first and last word starting with it
Input: The list (const)
Output: None
Author: [Your Name]
Date: Jan 2026
*/
void firstAndLast(const vector<Word>& dict) {
    if (dict.empty()) {
        cout << "Error 202601- no dictionary loaded -" << endl;
        return;
    }
    cout << "First and Last Words by Starting Letter:" << endl;
    cout << left << setw(10) << "Letter" << setw(20) << "First Word" << setw(20) << "Last Word" << endl;
    
    for (char let = 'a'; let <= 'z'; ++let) {
        string first = "", last = "";
        for (const auto& w : dict) {
            if (w.name[0] == let) {  // If starts with this letter
                if (first.empty() || w.name < first) first = w.name;
                if (last.empty() || w.name > last) last = w.name;
            }
        }
        if (!first.empty()) {
            cout << left << setw(10) << (char)toupper(let) << setw(20) << first << setw(20) << last << endl;
        }
    }
}

int main() {
    vector<Word> Dictionary;
    
    cout << "Welcome to Dictionary Program!" << endl;
    cout << "Instructions: Load dictionary first. Searches are case-insensitive." << endl;
    
    int choice;
    while (true) {
        cout << "\n1. Load new Dictionary" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. First and Last" << endl;
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input! Exiting." << endl;
            break;
        }
        if (choice == 1) loadDictionary(Dictionary);
        else if (choice == 2) searchWord(Dictionary);
        else if (choice == 3) firstAndLast(Dictionary);
        else cout << "Invalid choice. Try again." << endl;
    }
    return 0;
}