#include <iostream>
#include "Functions Part C.h"
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

void agePrinter()
{
    cout << "Age: 25" << endl;
}