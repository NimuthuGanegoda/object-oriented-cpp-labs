// Prologue: Subclass for Wordle cheat feature
// Purpose: Extend Dictionary with Wordle helper
// Author: Nimuthu Ganegoda
// Date: February 2026

#pragma once
#include "Dictionary.h"

class ImprovedDictionary : public Dictionary {
public:
    // Constructor
    ImprovedDictionary();

    // Override menu to add Wordle option
    void programMenu() override;

    // New function for Wordle
    void cheatAtWordle();
};