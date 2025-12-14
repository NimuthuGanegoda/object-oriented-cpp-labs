#include <iostream>
using namespace std;

int main()
{
    int b = 5;
    int *a = &b;
    cout << b << endl;
    cout << &b << endl;
    cout << a << endl;
    cout << *a << endl;
    cout << &a << endl;
    return 0;
}
