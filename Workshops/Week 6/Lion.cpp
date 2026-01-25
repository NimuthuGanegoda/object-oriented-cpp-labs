#include "Lion.h"

Lion::Lion(string n) : Mammal(n) {}

void Lion::speak() const {
    cout << "Roar! I am a Lion named " << name << endl;
}
