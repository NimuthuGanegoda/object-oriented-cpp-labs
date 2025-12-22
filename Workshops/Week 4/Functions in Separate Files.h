#pragma once
// CSP2014 - Martin Mase, 2024
// Some helper function to go here
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