#include <iostream>
using namespace std;

int main (){
    // Inutualize variable
    int User_Input;
    int i;
    int j;

    // Gets the user input
    cout << "Enter a the number for the times table: ";

    

    cin >> User_Input;

    for (i = 0; i < User_Input; i++){
        cout << i << "x" << User_Input << "=" << i * User_Input << endl;
    }
}