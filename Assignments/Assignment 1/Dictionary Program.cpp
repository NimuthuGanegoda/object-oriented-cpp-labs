/*
Student Name : Nimuthu Ganegoda
Student ID : 10695889
Unit: CSP2104 Object Oriented Programming with C++
Assignment 1 : Dictionary Program
*/

#include <algorithm>  // for transform
#include <cctype>     // for tolower
#include <fstream>
#include <iomanip>  // for setw in first/last
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This is the structure to hold each word's data
struct Word
{
  string name;
  string type;
  string definition;
};

// Convert string to lower case
string toLower(string s)
{
  for (size_t i = 0; i < s.size(); ++i)
  {
    s[i] = static_cast<char>(tolower(s[i]));
  }
  return s;
}

// Trim leading and trailing spaces
string trim(const string& s)
{
  if (s.empty())
    return s;
  size_t start = 0;
  while (start < s.size() && isspace(static_cast<unsigned char>(s[start])))
    start++;

  size_t end = s.size();
  while (end > start && isspace(static_cast<unsigned char>(s[end - 1])))
    end--;

  return s.substr(start, end - start);
}

// coverts the type abbreviation to full name
string fulltype(const string& abbr)
{
  if (abbr == "n")
    return "Noun";
  else if (abbr == "v")
    return "Verb";
  else if (abbr == "adv")
    return "Adverb";
  else if (abbr == "adj")
    return "Adjective";
  else if (abbr == "prep")
    return "Preposition";
  else if (abbr == "pn")
    return "Proper Noun";
  else if (abbr == "misc")
    return "Miscellaneous";
  else
    return abbr;  // if type is weird, say this
}

// ====== Task 1.1: Load Dictionary from File ======

/*
Function : loadDictionary
Purpose : This loads the dictionary from a file into the vector
*/

void loadDictionary(vector<Word>& dict)  // Pass by reference so we can change original
{
  ifstream file("dictionary_2026S0.txt");
  if (!file.is_open())  // Check if file opened successfully
  {
    cout << "Error opening dictionary file!" << endl;
    return;
  }

  dict.clear();  // Make sure the dictionary is empty before loading
  string line;

  getline(file, line);  // Read the header line and ignore it

  getline(file, line);  // Read the blank line after header and ignore it

  while (getline(file, line))
  {
    if (line.empty() || line == ".")
      continue;  // Skip empty/separator lines

    Word w;  // Make a new box for this word

    // Line 1: name (and to remove the semicolon (;))
    size_t pos = line.find(';');
    if (pos == string::npos)
      continue;
    w.name = line.substr(0, pos);

    // Line 2: type (and to remove the semicolon (;))
    if (!getline(file, line))
      break;
    pos = line.find(';');
    if (pos == string::npos)
      continue;
    w.type = line.substr(0, pos);

    // Line 3 : definition (and to remove the last semicolon (;))
    if (!getline(file, line))
      break;
    w.definition = line;
    while (!w.definition.empty() && w.definition.back() == ';')
    {
      w.definition.erase(w.definition.size() - 1);  // Remove trailing semicolons
    }

    // Line 4: blank line (don't care if it's not blank)
    getline(file, line);

    dict.push_back(w);  // Add the box to the list
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
    cout << "Dictionary is not loaded. Please load it first." << endl;
    return;
  }

  string input;
  cout << "Enter a word to search: ";
  cin >> input;
  input = toLower(input);  // Convert input to lowercase for case-insensitive search

  bool found = false;
  for (const auto& w : dict)
  {
    if (toLower(w.name) == input)
    {
      found = true;

      // Count definitions by semicolons
      int defCount = 0;
      string def = w.definition;
      size_t pos = 0;
      while ((pos = def.find(';')) != string::npos)
      {
        if (!trim(def.substr(0, pos)).empty())
          defCount++;
        def.erase(0, pos + 1);
      }
      if (!trim(def).empty())
        defCount++;

      cout << "Word Found! " << defCount << " definition(s)." << endl;
      cout << w.name << endl;
      cout << fulltype(w.type) << endl;

      // Print each definition on a new line with numbering
      def = w.definition;
      pos = 0;
      int defIndex = 1;
      while ((pos = def.find(';')) != string::npos)
      {
        string part = trim(def.substr(0, pos));
        if (!part.empty())
        {
          cout << defIndex << ". " << part << endl;
          defIndex++;
        }
        def.erase(0, pos + 1);
      }
      string lastPart = trim(def);
      if (!lastPart.empty())
      {
        cout << defIndex << ". " << lastPart << endl;
      }
    }
  }
  if (!found)
  {
    cout << "Word not found." << endl;  // Word not found message
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
    cout << "Dictionary is not loaded. Please load it first." << endl;
    return;
  }

  cout << "First and Lasts by the starting letter" << endl;  // Header
  cout << "--------------------------------------" << endl;
  cout << left << setw(10) << "Letter" << setw(25) << "First Word" << "Last Word" << endl;
  cout << "--------------------------------------" << endl;

  for (char ch = 'a'; ch <= 'z'; ++ch)
  {
    string first = "";
    string last = "";

    for (const auto& w : dict)
    {
      if (!w.name.empty() && tolower(w.name[0]) == ch)
      {
        string current = toLower(w.name);
        string firstKey = toLower(first);
        string lastKey = toLower(last);

        if (first.empty() || current < firstKey)
          first = w.name;  // Find first word
        if (last.empty() || current > lastKey)
          last = w.name;  // Find last word
      }
    }

    if (!first.empty())
    {
      cout << left << setw(10) << (char)toupper(ch) << setw(25) << first << last << endl;  // Print first and last words
    }
  }
}

int main()
{
  vector<Word> Dictionary;  // Our dictionary storage

  cout << "Dictionary Program - Assignment 1" << endl;

  int choice;
  while (true)
  {
    cout << "1. Load new Dictionary" << endl;
    cout << "2. Search for a Word" << endl;
    cout << "3. First and Last Words by Letter" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      loadDictionary(Dictionary);  // Load dictionary from file
    }
    else if (choice == 2)
    {
      searchWord(Dictionary);  // Search for a word
    }
    else if (choice == 3)
    {
      firstandlast(Dictionary);  // Display first and last words by letter
    }
    else if (choice == 4)
    {
      cout << "Exiting program." << endl;  // Exit message
      break;
    }
    else
    {
      cout << "Invalid choice. Please enter 1-4." << endl;
    }
  }

  return 0;
}