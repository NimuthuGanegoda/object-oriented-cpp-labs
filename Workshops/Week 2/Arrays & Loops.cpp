#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int maxRand = 10;
    const int arraySize = 20;

    // Seed the random number generator (fixed spelling)
    srand(1); // using the same seed will result in same sequence each time

    int someNumbers[arraySize];

    // Fill the array with numbers between 0 and maxRand
    for (int i = 0; i < arraySize; ++i)
    {
        someNumbers[i] = static_cast<int>(maxRand * (static_cast<double>(rand()) / RAND_MAX));
    }

    // Print the numbers
    for (int i = 0; i < arraySize; ++i)
    {
        cout << someNumbers[i] << " ";
    }
    cout << "\n\n";

    return 0;
}