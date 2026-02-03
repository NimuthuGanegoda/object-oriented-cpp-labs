#include "ImprovedDictionary.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Constructor
ImprovedDictionary::ImprovedDictionary()
{
}

// Show extended menu with Wordle option
void ImprovedDictionary::programMenu()
{
  int choice;

  while (true)
  {
    cout << "\n1. Load Dictionary" << endl;
    cout << "2. Search Word" << endl;
    cout << "3. Display Random Word" << endl;
    cout << "4. Cheat at Wordle" << endl;
    cout << "5. Exit" << endl;
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
      cheatAtWordle();
    }
    else if (choice == 5)
    {
      break;
    }
    else
    {
      cout << "Invalid choice." << endl;
    }
  }
}

// Help user find words for Wordle game
void ImprovedDictionary::cheatAtWordle()
{
  if (dictionary.empty())
  {
    cout << "Error 202601- no dictionary loaded -" << endl;
    return;
  }

  string gray, yellow, green;

  cout << "Enter gray letters (exclude, no commas, e.g. rst): ";
  cin >> gray;
  cout << "Enter yellow letters (include anywhere, e.g. ae): ";
  cin >> yellow;
  cout << "Enter green pattern (5 chars, . for unknown, e.g. a..e.): ";
  cin >> green;

  // Convert to lowercase
  transform(gray.begin(), gray.end(), gray.begin(), ::tolower);
  transform(yellow.begin(), yellow.end(), yellow.begin(), ::tolower);
  transform(green.begin(), green.end(), green.begin(), ::tolower);

  // Find matching words
  vector<string> matches;
  for (size_t i = 0; i < dictionary.size(); i++)
  {
    Word w = dictionary[i];
    if (w.isFiveLetters() && w.excludesLetters(gray) && w.includesLetters(yellow) && w.matchesPositions(green))
    {
      matches.push_back(w.getName());
    }
  }

  // Print results
  if (matches.empty())
  {
    cout << "No matching words found." << endl;
  }
  else
  {
    cout << "Matching words (" << matches.size() << " found):" << endl;
    for (size_t i = 0; i < matches.size(); i++)
    {
      cout << matches[i] << endl;
    }
  }
}