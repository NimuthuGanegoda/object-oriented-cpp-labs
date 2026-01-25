#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void sinAndCos(double input, double &sinInput, double &cosInput)
{
    sinInput = sin(input);
    cosInput = cos(input);
}
