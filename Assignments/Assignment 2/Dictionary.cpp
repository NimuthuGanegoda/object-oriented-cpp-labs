#include "Dictionary.h"

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

Dictionary::Dictionary() : filename("dictionary_2026S0.txt")
{
  srand(static_cast<unsigned>(time(0)));
}

bool Dictionary::loadDictionary()
{
  ifstream file(filename.c_str());
  if (!file.is_open())
  {
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
    if (line.empty() || line == ".")
      continue;

    size_t pos = line.find(';');
    if (pos == string::npos)
      continue;
    name = line.substr(0, pos);

    if (!getline(file, line))
      break;
    pos = line.find(';');
    if (pos == string::npos)
      continue;
    type = line.substr(0, pos);

    if (!getline(file, def))
      break;
    if (!def.empty() && def[def.size() - 1] == ';')
      def.erase(def.size() - 1);

    dictionary.push_back(Word(name, type, def));
  }

  cout << "Dictionary loaded with " << dictionary.size() << " words.\n";
  return true;
}

void Dictionary::searchWord()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -\n";
    return;
  }

  string input;
  cout << "Enter word to search: ";
  cin >> input;

  for (size_t i = 0; i < input.size(); ++i)
    input[i] = static_cast<char>(tolower(input[i]));
  for (size_t i = 0; i < dictionary.size(); ++i)
  {
    string n = dictionary[i].getName();
    for (size_t j = 0; j < n.size(); ++j)
      n[j] = static_cast<char>(tolower(n[j]));

    if (n == input)
    {
      int defs = 1;
      string d = dictionary[i].getDefinition();
      size_t pos = 0;
      while ((pos = d.find(";  ", pos)) != string::npos)
      {
        defs++;
        pos += 3;
      }
      cout << "Word Found – with " << defs << " definitions\n";
      dictionary[i].printDefinition();
      return;
    }
  }

  cout << "word not found.\n";
}

void Dictionary::displayRandomWord()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -\n";
    return;
  }
  size_t idx = static_cast<size_t>(rand()) % dictionary.size();
  dictionary[idx].printDefinition();
}

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