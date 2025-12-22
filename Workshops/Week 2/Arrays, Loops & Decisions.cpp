#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int maxRand = 10;
    const int arraySize = 20;

    // Seed the random number generator
    srand(1); // using same seed will result in same sequence each time

    int someNumbers[arraySize];

    // Fill the array with random numbers between 0 and maxRand
    for (int i = 0; i < arraySize; ++i)
    {
        someNumbers[i] = static_cast<int>(maxRand * (static_cast<double>(rand()) / RAND_MAX));
    }

    bool exitRequested = false;
    while (!exitRequested)
    {
        // Print the numbers
        for (int i = 0; i < arraySize; ++i)
        {
            cout << someNumbers[i] << " ";
        }
        cout << "\n\n";

        cout << "Replace numbers higher than X with Y\n";
        cout << "Enter X (or enter 999 to exit): ";
        int X = 0, Y = 0;
        cin >> X;

        if (X == 999)
        {
            exitRequested = true;
        }
        else
        {
            cout << "\nEnter Y: ";
            cin >> Y;

            // Replace numbers greater than X with Y
            for (int i = 0; i < arraySize; ++i)
            {
                if (someNumbers[i] > X)
                {
                    someNumbers[i] = Y;
                }
            }
        }
    }

    return 0;
}