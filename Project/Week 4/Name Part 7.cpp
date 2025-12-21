#include<iostream>
using namespace std;

int adder(int _a, int _b) 
{
    int result;
    result = _a + _b;
    return result;
}

void main() 
{
    int a, b;
    cout << "Please enter a number: ";
    cin >> a;
    cout << "Please enter another number: ";
    cin >> b;

    //call the adder
    cout << adder(a, b) << endl;
}