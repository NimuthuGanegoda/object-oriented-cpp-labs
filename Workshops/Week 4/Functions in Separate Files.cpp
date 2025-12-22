#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
// .h files that are part of your project are included with "" rather than <>
#include"helperFunctions.h"
using namespace std;
void main()
{
// define a double precision floating point variable, and set it.
double a = M_PI;
// define variables to store the answer.
double sinA;
double cosA;
// pass sinA and cosA by reference to a function that will calculate their values
sinAndCos(a, sinA, cosA);
// print the values
cout << "The number is: " << a << "\n";
cout << "The Sin of that number is: " << sinA << "\n";
cout << "The Cos of that number is: " << cosA << "\n";
}