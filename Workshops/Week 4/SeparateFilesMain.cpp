#include <iostream>
#include "helperFunctions.h"

using namespace std;

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
