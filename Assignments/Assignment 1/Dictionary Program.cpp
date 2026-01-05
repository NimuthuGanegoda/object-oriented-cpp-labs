/*
Student Name : Nimuthu Ganegoda
Student ID : 10695889
Unit: CSP2104 Object Oriented Programming with C++
Assignment 1 : Dictionary Program
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

// extracts only letters from a string and converts to lowercase
string extractLetters(const string& s)
{
    string result;
    for (char c : s)
    {
        if (isalpha(c))
        {
            result += tolower(c);
        }
    }
    return result;
}

// coverts the type abbreviation to full name
string fulltype(const string& abbr)
{
    if (abbr == "n") return "Noun";
    else if (abbr == "v") return "Verb";
    else if (abbr == "adv") return "Adverb";
    else if (abbr == "adj") return "Adjective";
    else if (abbr == "prep") return "Preposition";
    else if (abbr == "pn") return "Proper Noun";
    else if (abbr == "misc") return "Miscellaneous";
    else return abbr;//if type is weird, say this
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
        if (!line.empty() && line.back() == ';')
        {
            w.definition = line.substr(0, line.length() - 1); // Remove last semicolon
        }
        else 
        {
            w.definition = line; // No semicolon to remove
        }

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
            int defCount = 0;
            for (char c : w.definition)
            {
                if (c == ';') defCount++;
            }
        
            cout << "Word Found ! " << defCount << " definition(s) found." << endl;
            cout << w.name << endl;
            cout << fulltype(w.type) << endl;

            // Print each definition on a new line
            string def = w.definition;
            size_t pos = 0;
            while ((pos = def.find(";  ")) != string::npos) // Look for semicolon followed by space
            {
                cout << def.substr(0, pos) << endl; // Print definition up to semicolon
                def.erase(0, pos + 3); // Remove the printed definition and the semicolon and space
            }
            
            // Print the last definition if any
            if (!def.empty())
            {
                cout << def << endl; // Print the last definition
            }
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
                if (first.empty() || extractLetters(w.name) < extractLetters(first)) first = w.name; // Find first word
                if (last.empty() || extractLetters(w.name) > extractLetters(last)) last = w.name; // Find last word
                
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