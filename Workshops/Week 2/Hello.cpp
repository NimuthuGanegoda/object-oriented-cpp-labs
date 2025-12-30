#include <iostream>
using namespace std;

int main (){
    // Inutualize variable
    int User_Input;
    int i;
    cout << "Enter a integer: ";

    // Gets the user input

    cin >> User_Input;

    for (int i = 0; i < User_Input; i++){
        cout << "Hello World!" << endl;
    }
}