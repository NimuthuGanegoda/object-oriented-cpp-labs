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
string tolower(string s)
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
    else if (abbr == "n_and_v") return "(noun and verb)";
    else if (abbr == "misc") return "(misc)";
    else return "(" + abbr + ")";//if type is weird, say this
}

// ====== Task 1.1: Load Dictionary from File ======
void loadDistionary(vector<Word>& dict) // Pass by reference so we can change original
{
    ifstream file ("dictionary_2026S0.txt");
    if (!file.is_open()) // Check if file opened successfully
    {
        cout << "Error opening dictionary file!" << endl;
        return;
    }

    dict.clear(); // Make sure the dictionary is empty before loading
    string line;

    getline(file, line); // Read the header line and ignore it

    while (getline(file, line))
    {
        if (line.empty ()) continue; // Skip empty lines

        Word w; // Make a new box for this word

        // Line 1: name (and to remove the semicolon (;))
        size_t pos = line.find(';');
        w.name = (pos != string::npos) ? line.substr(0, post) : line;

        // Line 2: type (and to remove the semicolon (;))
        getline (file, line);
        pos = line.find(';');
        w.type = (pos != string::npos) ? line.substr(0, pos) : line;
    }   
    // Line 3 : definition (and to remove the last semicolon (;))
        getline (file, line);
        pos = line.find_last_of(';');
        w.definition = (pos != string::npos) ? line.substr(0, pos) : line;

        // Line 4: blank line (don't care if it's not blank)
        getline (file, line);

        dict.push_back(w); // Add the box to the list
    }

    file.close();
    cout << "Dictionary loaded with " << dict.size() << " words." << endl;
}

// ====== Task 1.2: Search for a Word ======

void searchWord(const vector<Word>& dict)
{
    
}