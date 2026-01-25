#include<iostream>
#include<vector>
using namespace std;

const string error = "Negative Number";

int getUserNumber() {
    int userEntry;
    cout << "Enter a positive number: ";
    cin >> userEntry;
    if (userEntry < 0)
        //cout << "You have entered a negative number!" << endl;
        throw(error);
        exit(1);
    return userEntry;
}

int main()
{
    try
    {
        cout << getUserNumber() << endl;
    }
    catch(string msg)
    {
       cout << "Unexpected input!" << endl;
       cout << msg << endl;
    }
}