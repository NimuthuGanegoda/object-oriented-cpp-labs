#include <iostream>
using namespace std;

int main()
{
    int* a = new int;
    int b = 5;
    *a = b;
    cout << a << endl;
    cout << &a << endl;
    delete a;
    return 0;
}