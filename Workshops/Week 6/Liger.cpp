#include "Liger.h"

// Note: Because of virtual inheritance, Mammal constructor is called by Liger, not Lion or Tiger.
Liger::Liger(string n) : Mammal(n), Lion(n), Tiger(n) {}

void Liger::speak() const {
    cout << "RoarGrrr! I am a Liger named " << name << endl;
}
