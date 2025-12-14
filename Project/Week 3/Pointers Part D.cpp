#include <iostream>
using namespace std;

int main()
{
    int b = 10;
    int *a = &b;
    *a = 5;
    cout << b << endl;
    cout << &b << endl;
    cout << a << endl;
    cout << *a << endl;
    cout << &a << endl;
    return 0;
}