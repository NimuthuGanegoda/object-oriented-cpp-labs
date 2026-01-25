#include "Tiger.h"

Tiger::Tiger(string n) : Mammal(n) {}

void Tiger::speak() const {
    cout << "Grrr! I am a Tiger named " << name << endl;
}
