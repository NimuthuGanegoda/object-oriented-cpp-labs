// ImprovedDictionary header (adds Wordle helper)
#ifndef IMPROVED_DICTIONARY_H
#define IMPROVED_DICTIONARY_H

#include "Dictionary.h"

// This class extends Dictionary
class ImprovedDictionary : public Dictionary
{
 public:
  // Constructor
  ImprovedDictionary();
  // Override menu
  virtual void programMenu();
  // Wordle helper
  void cheatAtWordle();
};

#endif