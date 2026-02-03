#include "Dictionary.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>

using namespace std;

// Constructor - set up the filename
Dictionary::Dictionary()
{
  filename = "dictionary_2026S0.txt";
  srand(time(0));
}

// Load dictionary from file
bool Dictionary::loadDictionary()
{
  ifstream file(filename);

  if (!file.is_open())
  {
    cout << "Error opening dictionary file!" << endl;
    return false;
  }

  dictionary.clear();
  string line;
  bool hasLine = false;

  // Skip the header line and empty line
  getline(file, line);
  getline(file, line);

  // Read all words
  while (true)
  {
    if (!hasLine)
    {
      if (!getline(file, line))
        break;
    }
    hasLine = false;

    if (line.empty() || line == ".")
      continue;

    // Read word name (ends with semicolon)
    size_t pos = line.find(';');
    if (pos == string::npos)
      continue;
    string n = line.substr(0, pos);

    // Read word type (ends with semicolon)
    if (!getline(file, line))
      break;
    pos = line.find(';');
    if (pos == string::npos)
      continue;
    string t = line.substr(0, pos);

    // Read definition (ends with semicolon)
    if (!getline(file, line))
      break;
    string d = line;
    if (!d.empty() && d.back() == ';')
    {
      d = d.substr(0, d.length() - 1);
    }

    // Read separator/blank line (if present)
    if (getline(file, line))
    {
      if (!line.empty() && line != ".")
      {
        hasLine = true;
      }
    }

    if (!n.empty())
    {
      dictionary.push_back(Word(n, t, d));
    }
  }

  file.close();
  cout << "Dictionary loaded with " << dictionary.size() << " words." << endl;
  return true;
}

// Search for a word (case-insensitive)
void Dictionary::searchWord()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -" << endl;
    return;
  }

  string input;
  cout << "Enter word to search: ";
  cin >> input;

  // Convert input to lowercase
  transform(input.begin(), input.end(), input.begin(), ::tolower);

  // Search through dictionary
  bool found = false;
  for (size_t i = 0; i < dictionary.size(); i++)
  {
    string wordName = dictionary[i].getName();
    transform(wordName.begin(), wordName.end(), wordName.begin(), ::tolower);

    if (wordName == input)
    {
      // Count the definitions
      int defCount = 1;
      string def = dictionary[i].getDefinition();
      size_t pos = 0;

      while ((pos = def.find(";  ", pos)) != string::npos)
      {
        defCount++;
        pos = pos + 3;
      }

      cout << "Word Found – with " << defCount << " definitions" << endl;
      dictionary[i].printDefinition();
      found = true;
      break;
    }
  }

  if (!found)
  {
    cout << "word not found." << endl;
  }
}

// Display a random word
void Dictionary::displayRandomWord()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -" << endl;
    return;
  }

  // Pick a random number
  size_t randomIndex = rand() % dictionary.size();
  dictionary[randomIndex].printDefinition();
}

// Show menu and get user choice
void Dictionary::programMenu()
{
  int choice;

  while (true)
  {
    cout << "\n1. Load Dictionary" << endl;
    cout << "2. Search Word" << endl;
    cout << "3. Display Random Word" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // Check for bad input
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input - enter a number." << endl;
      continue;
    }

    if (choice == 1)
    {
      loadDictionary();
    }
    else if (choice == 2)
    {
      searchWord();
    }
    else if (choice == 3)
    {
      displayRandomWord();
    }
    else if (choice == 4)
    {
      break;
    }
    else
    {
      cout << "Invalid choice." << endl;
    }
  }
}