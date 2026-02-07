// Dictionary class header (list of words)
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

#include "Word.h"
using namespace std;

// This class keeps all Word objects
class Dictionary
{
 protected:
  vector<Word> dictionary;  // list of words
  string filename;          // file name

 public:
  // Constructor
  Dictionary();

  // Load words from file
  bool loadDictionary();
  // Search for a word
  void searchWord();
  // Show a random word
  void displayRandomWord();
  // Menu
  virtual void programMenu();
};

#endif