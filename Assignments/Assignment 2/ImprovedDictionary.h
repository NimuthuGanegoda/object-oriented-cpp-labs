// Prologue: Subclass for extended menu and Wordle cheat. Purpose: Inherit Dictionary and add cheat feature. Author: Nimuthu Ganegoda. Date: February 2026.
#pragma once
#include "Dictionary.h"

class ImprovedDictionary : public Dictionary {
public:
    ImprovedDictionary();
    void programMenu() override;
    void cheatAtWordle();
};