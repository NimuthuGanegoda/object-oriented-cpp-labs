#include <iostream>
using namespace std;


static int printHi(int n)
{
    for (int i = 0; i < nooftimes; i++)
    {
        cout << "Hi !" << endl;
    }
    return 0;
}

int main()
{
    int nooftimes;
    cout << "Please enter the number of times to print Hello: ";
    cin >> nooftimes;

    printHi(nooftimes);

    return 0;
}
