#include<iostream>
using namespace std;

void namePrinter();
void agePrinter();

int main()
{
    cout << "Call from main" << endl;
    //call the namePrinter function
    namePrinter();
    agePrinter();
    return 0;
}
void namePrinter()
{
    cout << "Nimuthu Ganegoda" << endl;
    return;
}

void agePrinter()
{
    cout << "25" << endl;
    return;
}