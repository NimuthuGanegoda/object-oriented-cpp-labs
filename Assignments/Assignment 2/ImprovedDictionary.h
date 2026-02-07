#ifndef IMPROVED_DICTIONARY_H
#define IMPROVED_DICTIONARY_H

#include "Dictionary.h"

class ImprovedDictionary : public Dictionary {
public:
  ImprovedDictionary();
  virtual void programMenu();
  void cheatAtWordle();
};

#endif