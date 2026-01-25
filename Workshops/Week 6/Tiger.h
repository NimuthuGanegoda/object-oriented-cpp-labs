#pragma once
#include "Mammal.h"

class Tiger : virtual public Mammal {
public:
    Tiger(string n);
    void speak() const override;
};
