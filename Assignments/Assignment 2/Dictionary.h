#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

#include "Word.h"
using namespace std;

class Dictionary
{
 protected:
  vector<Word> dictionary;
  string filename;

 public:
  Dictionary();

  bool loadDictionary();
  void searchWord();
  void displayRandomWord();
  virtual void programMenu();
};

#endif