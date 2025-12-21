#include <iostream>
#include "Name_Part_3.2.h"
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