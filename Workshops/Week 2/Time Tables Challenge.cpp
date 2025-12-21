#include<iostream>
using namespace std;

void main()
{
   //times tables
   const int max = 10;

   int times = 0;
   cout << "Enter an integer to see its times tables: ";
    cin >> times;

    cout << "The " << times << " times table is:\n";
    for (int i = 0, answer = i * times; i <= max; i++, answer = i * times)
    {
        cout << times << " x " << i << " = " << answer << "\n";
    }
}