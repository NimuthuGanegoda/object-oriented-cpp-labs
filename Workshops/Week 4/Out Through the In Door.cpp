#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;
void sinAndCos(double input, double& sinInput, double& cosInput)
{
// since sinInput and cosInput are passed by reference, the results will be availabe in the
// function that call this function in the variable whose references were passed into
// sinInput and cosInput
sinInput = sin(input);
cosInput = cos(input);
}
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