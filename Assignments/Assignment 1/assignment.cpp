/*
Student Name : Nimuthu Ganegoda
Student ID : 10695889
Unit: CSP2104 Object Oriented Programming with C++
*/


#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // for transform
#include <cctype>    // for tolower
#include <iomanip>   // for setw in first/last

using namespace std;

// This is the structure to hold each word's data
struct Word 
{
    string name;
    string type;
    string definition;
};

// To covert sting in to lower case
string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// coverts the type abbreviation to full name
string fulltype(const string& abbr)
{
    if (abbr == "n") return "(noun)";
    else if (abbr == "v") return "(verb)";
    else if (abbr == "adv") return "(adverb)";
    else if (abbr == "adj") return "(adjective)";
    else if (abbr == "prep") return "(preposition)";
    else if (abbr == "pn") return "(proper noun)";
    else if (abbr == "misc") return "(misc)";
    else return "(" + abbr + ")";//if type is weird, say this
}

// ====== Task 1.1: Load Dictionary from File ======

/* 
Function : loadDictionary
Purpose : This loads the dictionary from a file into the vector
*/

void loadDictionary(vector<Word>& dict) // Pass by reference so we can change original
{
    ifstream file ("/home/nimuthu/Repo/object-oriented-cpp-labs/Assignments/Assignment 1/dictionary_2026S0.txt");
    if (!file.is_open()) // Check if file opened successfully
    {
        cout << "Error opening dictionary file!" << endl;
        return;
    }

    dict.clear(); // Make sure the dictionary is empty before loading
    string line;

    getline(file, line); // Read the header line and ignore it

    getline(file,line); // Read the blank line after header and ignore it

    while (getline(file, line))
    {
        if (line.empty()) continue; // Skip empty lines

        Word w; // Make a new box for this word

        // Line 1: name (and to remove the semicolon (;))
        size_t pos = line.find(';');
        w.name = line.substr(0, pos);

        // Line 2: type (and to remove the semicolon (;))
        getline (file, line);
        pos = line.find(';');
        w.type = line.substr(0, pos);
       
    // Line 3 : definition (and to remove the last semicolon (;))
        getline (file, line);
        pos = line.find_last_of(';');
        w.definition = line.substr(0, pos);

        // Line 4: blank line (don't care if it's not blank)
        getline (file, line);

        dict.push_back(w); // Add the box to the list
    }

    file.close();
    cout << "Dictionary loaded with " << dict.size() << " words." << endl;
}

// ====== Task 1.2: Search for a Word ======

/* 
Function : searchWord
Purpose : This searches for a word in the dictionary and prints its details if found
*/

void searchWord(const vector<Word>& dict)
{
    if (dict.empty())
    {
        cout << "The Dictionary is not loaded... Please load it first." << endl;
        return;
    }

    string input;
    cout << "Enter a word to which you are searching for: ";
    cin >> input;
    input = toLower(input); // Convert input to lowercase for case-insensitive search

    bool found = false;
    for (const auto& w : dict)
    {
        if (toLower(w.name) == input)
        {
            found = true;

            // Definitions are counted by (semicolons ;)
            int defCount = 1;
            size_t pos = 0;
            while ((pos = w.definition.find(";  ", pos)) != string::npos) // Look for semicolon followed by space
            {
                defCount++;
                pos += 3; // Move past the found semicolon and space
            }
        
            cout << "Word Found !" << defCount << " definition(s) found." << endl;
            cout << w.name << endl;
            cout << fulltype(w.type) << endl;

            // Print each definition on a new line
            string def = w.definition;
            pos = 0;
            while ((pos = def.find(";  ")) != string::npos) // Look for semicolon followed by space
            {
                cout << def.substr(0, pos) << endl; // Print definition up to semicolon
                def.erase(0, pos + 3); // Remove the printed definition and the semicolon and space
            }
            cout << def << endl; // Print the last definition

            break; // Exit loop after finding the word
        }

    }
    if (!found)
    {
        cout << "Word Not Found !" << endl; // Word not found message
    }
}

// ====== Task 1.3 : First and Last ======

/* 
Function : first and last
Purpose : This prints the first and the last words which starts from each letter A-Z
*/

void firstandlast(const vector<Word>& dict)
{
    if (dict.empty())
    {
        cout << "The Dictionary is not loaded... Please load it first." << endl;
        return;
    }

    cout << "First and Lasts by the starting letter" << endl; // Header
    cout << "--------------------------------------" <<endl; 
    cout << left << setw(10) << "Letter" << setw(25) << "First Word" << "Last Word" << endl;
    cout << "--------------------------------------" <<endl;

    for (char ch = 'a' ; ch <= 'z'; ++ch)
    {
        string first = "";
        string last = "";

        for (const auto& w : dict)
        {
            if (!w.name.empty() && tolower(w.name[0]) == ch)
            {
                if (first.empty() || w.name < first) first = w.name;
                if (last.empty() || w.name > last) last = w.name;
            }
        }

        if (!first.empty()) 
        {
            cout << left << setw(10) << (char)toupper(ch)
                 << setw(25) << first << last << endl;
        }
    }
}

int main() 
{
    vector<Word> Dictionary; // Our dictionary storage

    cout << "Dictionary Program - Assignment 1" << endl;

    int choice;
    while (true)
    {
        cout << "1. Load new Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. First and Last Words by Letter" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            loadDictionary(Dictionary); // Load dictionary from file
        }
        else if (choice == 2)
        {
            searchWord(Dictionary); // Search for a word
        }
        else if (choice == 3)
        {
            firstandlast(Dictionary); // Display first and last words by letter
        }
        else
        {
            cout << "Exiting program." << endl; // Exit message
            break;
        }
    }

    return 0;
}