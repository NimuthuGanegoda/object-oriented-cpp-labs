#pragma once
#include "Lion.h"
#include "Tiger.h"

class Liger : public Lion, public Tiger {
public:
    Liger(string n);
    void speak() const override;
};
