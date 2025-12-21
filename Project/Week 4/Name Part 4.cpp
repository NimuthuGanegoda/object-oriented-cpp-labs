#include<iostream>
using namespace std;

inline  void namePrinter()
{
    cout << "Nimuthu Ganegoda" << endl;
    return;
}

inline void agePrinter()
{
    cout << "Age: 25" << endl;
}

int main()
{
    cout << "Call from main" << endl;
    //call the namePrinter function
    namePrinter();
    agePrinter();
    return 0;
}