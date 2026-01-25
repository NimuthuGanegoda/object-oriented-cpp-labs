#pragma once
#include "Mammal.h"

class Lion : virtual public Mammal {
public:
    Lion(string n);
    void speak() const override;
};
