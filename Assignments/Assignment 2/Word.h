#ifndef WORD_H
#define WORD_H

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Word
{
  string name;
  string type;
  string definition;

 public:
  Word(const string& n, const string& t, const string& d) : name(n), type(t), definition(d)
  {
  }

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

  void printDefinition() const
  {
    cout << name << "\n";

    string full = "(" + type + ")";
    if (type == "n")
      full = "(noun)";
    else if (type == "v")
      full = "(verb)";
    else if (type == "adv")
      full = "(adverb)";
    else if (type == "adj")
      full = "(adjective)";
    else if (type == "prep")
      full = "(preposition)";
    else if (type == "pn")
      full = "(proper noun)";
    else if (type == "n_and_v")
      full = "(noun and verb)";

    cout << full << "\n";

    string def = definition;
    size_t pos = 0;
    while ((pos = def.find(";  ")) != string::npos)
    {
      cout << def.substr(0, pos) << "\n";
      def = def.substr(pos + 3);
    }
    if (!def.empty())
      cout << def << "\n";
  }

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
      {
        return false;
      }
    }
    return true;
  }
};

#endif
