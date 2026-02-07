// Word class header (stores one word)
#ifndef WORD_H
#define WORD_H

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// This class stores one word and its info
class Word
{
  string name;        // word name
  string type;        // word type
  string definition;  // word meaning

  // helper: remove extra spaces
  string trim(const string& s) const
  {
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start])))
      start++;

    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1])))
      end--;

    return s.substr(start, end - start);
  }

  // helper: convert short type to full word
  string typeFullName() const
  {
    if (type == "n")
      return "(noun)";
    if (type == "v")
      return "(verb)";
    if (type == "adv")
      return "(adverb)";
    if (type == "adj")
      return "(adjective)";
    if (type == "prep")
      return "(preposition)";
    if (type == "pn")
      return "(proper noun)";
    if (type == "n_and_v")
      return "(noun and verb)";
    if (type == "misc")
      return "(misc)";
    return "(" + type + ")";
  }

 public:
  // Constructor
  Word(const string& n, const string& t, const string& d) : name(n), type(t), definition(d)
  {
  }

  // Getters (read data)
  const string& getName() const
  {
    return name;
  }
  const string& getType() const
  {
    return type;
  }
  const string& getDefinition() const
  {
    return definition;
  }

  // Setters (change data)
  void setName(const string& n)
  {
    name = n;
  }
  void setType(const string& t)
  {
    type = t;
  }
  void setDefinition(const string& d)
  {
    definition = d;
  }

  // Count definitions by ';'
  int countDefinitions() const
  {
    int count = 0;
    string def = definition;
    size_t pos = 0;
    while ((pos = def.find(';')) != string::npos)
    {
      if (!trim(def.substr(0, pos)).empty())
        count++;
      def.erase(0, pos + 1);
    }
    if (!trim(def).empty())
      count++;
    return count;
  }

  // Print the word with numbers for each definition
  void printDefinition() const
  {
    cout << name << "\n";
    cout << typeFullName() << "\n";

    string def = definition;
    size_t pos = 0;
    int index = 1;

    while ((pos = def.find(';')) != string::npos)
    {
      string part = trim(def.substr(0, pos));
      if (!part.empty())
      {
        cout << index << ". " << part << "\n";
        index++;
      }
      def.erase(0, pos + 1);
    }

    string lastPart = trim(def);
    if (!lastPart.empty())
      cout << index << ". " << lastPart << "\n";
  }

  // Wordle helper functions
  bool isFiveLetters() const
  {
    return name.size() == 5;
  }

  bool excludesLetters(const string& gray) const
  {
    string lower = name;
    for (size_t i = 0; i < lower.size(); ++i)
      lower[i] = static_cast<char>(tolower(lower[i]));

    for (size_t i = 0; i < gray.size(); ++i)
    {
      char c = static_cast<char>(tolower(gray[i]));
      if (lower.find(c) != string::npos)
        return false;
    }
    return true;
  }

  bool includesLetters(const string& yellow) const
  {
    string lower = name;
    for (size_t i = 0; i < lower.size(); ++i)
      lower[i] = static_cast<char>(tolower(lower[i]));

    for (size_t i = 0; i < yellow.size(); ++i)
    {
      char c = static_cast<char>(tolower(yellow[i]));
      if (lower.find(c) == string::npos)
        return false;
    }
    return true;
  }

  bool matchesPositions(const string& green) const
  {
    if (green.size() != 5)
      return false;
    for (size_t i = 0; i < 5; ++i)
    {
      if (green[i] != '.' && tolower(green[i]) != tolower(name[i]))
        return false;
    }
    return true;
  }
};

#endif
