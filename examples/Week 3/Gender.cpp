#include <iostream>

using namespace std;

int main() 
{
    char genderCode;
    cout << "Enter F for female or M for male: ";
    cin >> genderCode;
    if (genderCode == 'F')
        cout << "Female" << endl;
    else
        cout << "Male" << endl;
    // system("pause");
    return 0;
}
