#include<iostream>
using namespace std;

int a = 5;

int main()
{
     ::a = 10;
    cout << ::a << endl;
}
