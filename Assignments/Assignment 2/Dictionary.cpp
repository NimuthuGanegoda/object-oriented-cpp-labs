// Dictionary class implementation (code)
#include "Dictionary.h"

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

// Constructor: set file name
Dictionary::Dictionary() : filename("dictionary_2026S0.txt")
{
  // seed random once
  srand(static_cast<unsigned>(time(0)));
}

// Load all words from the file
bool Dictionary::loadDictionary()
{
  ifstream file(filename.c_str());
  if (!file.is_open())
  {
    // file open failed
    cout << "Error opening dictionary file!\n";
    return false;
  }

  dictionary.clear();
  string line, name, type, def;

  // Skip header + blank line
  getline(file, line);
  getline(file, line);

  while (getline(file, line))
  {
    // skip empty or separator lines
    if (line.empty() || line == ".")
      continue;

    // line 1: word name
    size_t pos = line.find(';');
    if (pos == string::npos)
      continue;
    name = line.substr(0, pos);

    // line 2: word type
    if (!getline(file, line))
      break;
    pos = line.find(';');
    if (pos == string::npos)
      continue;
    type = line.substr(0, pos);

    // line 3: definition
    if (!getline(file, def))
      break;

    // trim trailing ';' or spaces
    while (!def.empty() && (def[def.size() - 1] == ';' || isspace(static_cast<unsigned char>(def[def.size() - 1]))))
    {
      def.erase(def.size() - 1);
    }

    // store the word
    dictionary.push_back(Word(name, type, def));
  }

  cout << "Dictionary loaded with " << dictionary.size() << " words.\n";
  return true;
}

// Search for a word (case-insensitive)
void Dictionary::searchWord()
{
  if (dictionary.empty())
  {
    // no data yet
    cout << "Error 202601- no dictionary loaded -\n";
    return;
  }

  string input;
  cout << "Enter word to search: ";
  cin >> input;

  // make input lowercase
  for (size_t i = 0; i < input.size(); ++i)
    input[i] = static_cast<char>(tolower(input[i]));

  // loop over all words
  for (size_t i = 0; i < dictionary.size(); ++i)
  {
    string n = dictionary[i].getName();
    for (size_t j = 0; j < n.size(); ++j)
      n[j] = static_cast<char>(tolower(n[j]));

    if (n == input)
    {
      // found it
      cout << "Word Found – with " << dictionary[i].countDefinitions() << " definitions\n";

      string wordName = dictionary[i].getName();
      string wordType = dictionary[i].getType();
      string wordDef = dictionary[i].getDefinition();

      cout << wordName << "\n";
      if (wordType == "n")
        cout << "(noun)\n";
      else if (wordType == "v")
        cout << "(verb)\n";
      else if (wordType == "adv")
        cout << "(adverb)\n";
      else if (wordType == "adj")
        cout << "(adjective)\n";
      else if (wordType == "prep")
        cout << "(preposition)\n";
      else if (wordType == "pn")
        cout << "(proper noun)\n";
      else if (wordType == "n_and_v")
        cout << "(noun and verb)\n";
      else if (wordType == "misc")
        cout << "(misc)\n";
      else
        cout << "(" << wordType << ")\n";

      // Numbered definitions split by semicolons
      int defIndex = 1;
      size_t pos = 0;
      while ((pos = wordDef.find(';')) != string::npos)
      {
        string part = wordDef.substr(0, pos);

        // trim leading/trailing spaces
        size_t start = 0;
        while (start < part.size() && isspace(static_cast<unsigned char>(part[start])))
          start++;
        size_t end = part.size();
        while (end > start && isspace(static_cast<unsigned char>(part[end - 1])))
          end--;
        part = part.substr(start, end - start);

        if (!part.empty())
        {
          cout << defIndex << ". " << part << "\n";
          defIndex++;
        }
        wordDef.erase(0, pos + 1);
      }

      // last definition
      size_t start = 0;
      while (start < wordDef.size() && isspace(static_cast<unsigned char>(wordDef[start])))
        start++;
      size_t end = wordDef.size();
      while (end > start && isspace(static_cast<unsigned char>(wordDef[end - 1])))
        end--;
      wordDef = wordDef.substr(start, end - start);

      if (!wordDef.empty())
        cout << defIndex << ". " << wordDef << "\n";
      return;
    }
  }

  cout << "word not found.\n";
}

// Print a random word
void Dictionary::displayRandomWord()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -\n";
    return;
  }
  // pick random index
  size_t idx = static_cast<size_t>(rand()) % dictionary.size();
  dictionary[idx].printDefinition();
}

// Base menu
void Dictionary::programMenu()
{
  while (true)
  {
    cout << "\n1. Load Dictionary\n"
         << "2. Search Word\n"
         << "3. Display Random Word\n"
         << "4. Exit\n"
         << "Enter choice: ";
    int choice;
    cin >> choice;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input - enter a number.\n";
      continue;
    }

    if (choice == 1)
      loadDictionary();
    else if (choice == 2)
      searchWord();
    else if (choice == 3)
      displayRandomWord();
    else if (choice == 4)
      break;
    else
      cout << "Invalid choice.\n";
  }
}