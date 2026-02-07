// ImprovedDictionary class implementation (code)
#include "ImprovedDictionary.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Constructor
ImprovedDictionary::ImprovedDictionary()
{
}

// Menu with Wordle option
void ImprovedDictionary::programMenu()
{
  while (true)
  {
    cout << "\n1. Load Dictionary\n"
         << "2. Search Word\n"
         << "3. Display Random Word\n"
         << "4. Cheat at Wordle\n"
         << "5. Exit\n"
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
      cheatAtWordle();
    else if (choice == 5)
      break;
    else
      cout << "Invalid choice.\n";
  }
}

// Wordle helper function
void ImprovedDictionary::cheatAtWordle()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -\n";
    return;
  }

  cout << "Wordle Helper (5-letter words only)\n";
  cout << "- Gray letters: NOT in word\n";
  cout << "- Yellow letters: in word (any position)\n";
  cout << "- Green pattern: 5 chars, use '.' for unknown\n\n";

  string gray, yellow, green;
  cout << "Enter gray letters (e.g. rst): ";
  cin >> gray;
  cout << "Enter yellow letters (e.g. ae): ";
  cin >> yellow;
  cout << "Enter green pattern (e.g. a..e.): ";
  cin >> green;

  for (size_t i = 0; i < gray.size(); ++i)
    gray[i] = static_cast<char>(tolower(gray[i]));
  for (size_t i = 0; i < yellow.size(); ++i)
    yellow[i] = static_cast<char>(tolower(yellow[i]));
  for (size_t i = 0; i < green.size(); ++i)
    green[i] = static_cast<char>(tolower(green[i]));

  vector<string> matches;
  // check every word
  for (size_t i = 0; i < dictionary.size(); ++i)
  {
    Word w = dictionary[i];
    if (w.isFiveLetters() && w.excludesLetters(gray) &&
        w.includesLetters(yellow) && w.matchesPositions(green))
    {
      matches.push_back(w.getName());
    }
  }

  if (matches.empty())
  {
    cout << "No matching words found.\n";
  }
  else
  {
    cout << "Matching words (" << matches.size() << " found):\n";
    for (size_t i = 0; i < matches.size(); ++i)
      cout << matches[i] << "\n";
  }
}