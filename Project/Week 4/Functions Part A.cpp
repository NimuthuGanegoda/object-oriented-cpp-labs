#include<iostream>
using namespace std;

void agePrinter()
{
    cout << "25" << endl;
    return;
}

void namePrinter()
{
    cout << "Nimuthu Ganegoda" << endl;
    return;
}

int main()
{
    cout << "Call from main" << endl;
    //call the namePrinter function
    namePrinter();
    agePrinter();
    return 0;
}