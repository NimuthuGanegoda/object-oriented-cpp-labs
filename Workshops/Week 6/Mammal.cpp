#include "Mammal.h"

Mammal::Mammal() : name("Generic Mammal") {}
Mammal::Mammal(string n) : name(n) {}

void Mammal::speak() const {
    cout << "Mammal sound! My name is " << name << endl;
}
