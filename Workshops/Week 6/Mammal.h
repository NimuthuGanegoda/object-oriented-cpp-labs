#pragma once
#include <iostream>
#include <string>
using namespace std;

class Mammal {
public:
    Mammal();
    Mammal(string n);
    virtual ~Mammal() = default;
    virtual void speak() const;
protected:
    string name;
};
