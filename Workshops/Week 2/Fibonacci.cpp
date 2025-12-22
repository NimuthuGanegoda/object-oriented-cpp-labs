#include <iostream>
using namespace std;

void main()
{
    // Length of sequence
    int max = 10;

    // Track two numbers
    int first = 0;
    int second = 1;
    int temp = 0;

    cout << first << ", " << second;

    for (int j = 0; j < max; ++j)
    {
        temp = second;
        second = first + second;
        first = temp;

        cout << ", " << second;
    }

    cout << "\n";
    return 0;
}