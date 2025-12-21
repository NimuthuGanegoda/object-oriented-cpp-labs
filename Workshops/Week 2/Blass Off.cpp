#include<iostream>>
using namespace std;

void main ()
{
    int i;
    cout << "Enter an integer: ";
    cin >> i;
    for (int j = i; j >= 0; j--)
    {
        cout << j << "\n";
    }
    cout << "Blast off!\n";
}