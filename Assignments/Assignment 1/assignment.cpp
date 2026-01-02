#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

// struct holds information for the name of the structure Word
struct Word {
    string name;
    string type;
    string definition;
};

vector<Word> wordList; // This holds all the words
bool isloaded = false; // Flag to check if data is loaded

// Makes the string lowercase
string tolower(string s) 
{
    string  result = s;
    for (int i = 0; i < result.length(); i++) 
    {
        result[i] = tolower(result[i]);
    }
    return result;
}

// Full type Name is taken for display 
string getType(string typeName) 
{
    if (typeName == "n") return "(noun)";
    else if (typeName == "v") return "(verb)";
    else if (typeName == "adv") return "(adverb)";
    else if (typeName == "adj") return "(adjective)";
    else if (typeName == "prep") return "(preposition)";
    else if (typeName == "pn") return "(proper noun)";
    else if (typeName == "n_and_v") return "(noun and verb)";
    else if (typeName == "misc") return "(misc)";
    else return "(" + typeName + ")"; // just in case
}

// Task 1.1. Load new Dictionary
void loadDictionary() 
{
    ifstream file("dictionary_2026S0.txt");

    if (!file) 
    {
        cout << "Error: Could not open the dictionary file." << endl;
        return;
    }

    Dictionary.clear();

    string line;
    Word currentWord;
    int linenum = 0;

    cout <<"Loading dictionary... please wait..." << endl;
}