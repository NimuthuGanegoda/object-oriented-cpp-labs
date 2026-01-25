#include <iostream>
#include <vector> 
#include <exception>
using namespace std;

int main()
{
    string number = "";
    cout << "Enter a 10-digit phone number: ";
    cin >> number;

    try 
    {
        string first = number.substr(0, 4);
        string second = number.substr(4, 3);
        string third = number.substr(7, 3);
        cout  << "Formatted Phone Number: " << first << "-" << second << "-" << third<< endl;
    }

    catch(out_of_range exc)
    {
        cout << "Exception found - Invalid Phone Number!" << endl;
        cout << exc.what() << endl;
    }
    catch(...)
    {
        cout << "I can catch anything !" << endl;
    }
}
