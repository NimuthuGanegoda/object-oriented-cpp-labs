#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <dictionary_2026S0.txt>

using namespace std;

// struct holds information for the name of the structure Word
struct Word {
    string name; // it holds the name of the word
    string type; // e.g., n, v, adj, adv, etc.
    string definition; // it holds the definition of the word
};

// This is the global dictionary variable
vector<Word> dictionary; // This stores all the words in the dictionary
bool isloaded = false; // This indicates whether the dictionary has been loaded

// makes the strings all lowercase
string makelower(string text)
{
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

// conversts type codes to readable names 
string gettypes (string code)
{
    if (code == "n") return "(noun)";
    else if (code == "v") return "(verb)";
    else if (code == "adv") return "(adverb)";
    else if (code == "adj") return "(adjective)";
    else if (code == "prep") return "(preposition)";
    else if (code == "pn") return "(proper noun)";
    else if (code == "n_and_v") return "(noun and verb)";
    else if (code == "misc") return "(miscellaneous)";
    return "(" + code + ")"; // for any other types not listed
}

// ====== TASK 1.1: Loading the Dictionary from a File ======
void loadDictionary() 
{
    ifstream file ("dictionary_2026S0.txt");
    if (!file)
    {
        cout << "Error: Could not open dictionary file." << endl;
        return;
    }
}

// data is cleaned if there is such
dictionary.clear();

Word current; // temporary Word object to hold data
string line; // to hold each line from the file
int lineNum = 0; // to track line numbers
int wordCount = 0; // to count words loaded

cout << "Dictionary loading starting... This might take a while" << endl;

// Dictionary.txt is read line by line
while (getline(file, line)) 
{
    if (!line.empty() && line[line.length() -1] == ';')
    {
        line = line.substr(0, line.length() - 1); // remove the semicolon)
    }

    // Word, Type and Definitions are exteracted and file patterns 
    if (linenum == 0)
    {
        current.name = line; // first line is the word
        lineNum = 1;
    }
    else if (linenum == 1)
    {
        current.type = line;
        linenum = 2;
    }
    else if (linenum == 2)
    {
        current.definition = line;
        linenum = 3;
    }

    else if (linenum == 3)
    {
        if (!current.name.empty ()) 
        {
            dictionary.push_back (currnt);
            wordcount ++;
            // Its reset for the next word
            current.name = "";
            current.type = "";
            current.definition = "";
        }
        linenum = 0; // Start over for the next word
    }
        
}
