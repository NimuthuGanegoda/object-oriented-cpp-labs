#include <iostream>
using namespace std;

void main()
{
    const int maxRand = 10;
    const in arraySize = 20;
    // seed the random number generator
    srand(1); // using same seed will result in the same sequence each time

    int someNumbers[arraySize];
    // fill the array with random numbers between 0 to 10
    for (int i = 0; i < arraySize; i++)
    {
        someNumbers[i] = maxRand * rand() /RAND_MAX; //generate a random number betwwn 0 and maxRand
    }

    //print the numbers
    for (int: i: someNumbers)
    {
        cout << i << " ";
    }
    cout << "\n\n";
}