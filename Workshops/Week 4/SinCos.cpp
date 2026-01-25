#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void sinAndCos(double input, double &sinInput, double &cosInput)
{
    sinInput = sin(input);
    cosInput = cos(input);
}

int main()
{
    double a = M_PI;
    double sinA;
    double cosA;

    sinAndCos(a, sinA, cosA);

    cout << "The number is: " << a << "\n";
    cout << "The Sin of that number is: " << sinA << "\n";
    cout << "The Cos of that number is: " << cosA << "\n";

    return 0;
}
