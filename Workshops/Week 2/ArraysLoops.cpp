#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    const int maxRand = 10;
    const int arraySize = 20;
    srand(1);

    int someNumbers[arraySize];
    for (int i = 0; i < arraySize; i++) {
        // maxRand * rand() / RAND_MAX might be 0 to 10
        someNumbers[i] = (int)((double)maxRand * rand() / RAND_MAX);
    }

    bool exit = false;
    while (!exit) {
        for (int i = 0; i < arraySize; i++) {
            cout << someNumbers[i] << " ";
        }
        cout << "\n\n";

        cout << "Replace numbers higher than X with Y\n";
        cout << "Enter X (or enter 999 to exit): ";
        int X = 0, Y = 0;
        if (!(cin >> X)) { exit = true; break; }

        if (X == 999) {
            exit = true;
        } else {
            cout << "\nEnter Y: ";
            cin >> Y;
            for (int i = 0; i < arraySize; i++) {
                if (someNumbers[i] > X) {
                    someNumbers[i] = Y;
                }
            }
        }
    }
    return 0;
}
