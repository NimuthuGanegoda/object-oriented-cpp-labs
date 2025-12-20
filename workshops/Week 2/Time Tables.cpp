#include<iostream>
using namespace std;

void main ()
{
    // times tables 
    const int max = 10;

    int times = 0;
    cout << "Enter an integer to see it times tables: ";
    cin >> times;
    cout << "The" << times << " times table is:\n";

    for (int i = 1; i <= max; i++)
    {
        cout << times << " x " << i << " = " << times * i << "\n";
    }
}