#include <iostream>
using namespace std;

int printHello()
{
    cout << "Hello !" << endl;
    return 0;
}

int main()
{
    int nooftimes;
    cout << "Please enter the number of times to print Hello: ";
    cin >> nooftimes;

    for (int i = 0; i < nooftimes; i++)
    {
        printHello();
    }
    return 0;
}