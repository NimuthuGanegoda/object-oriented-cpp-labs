#include <iostream>
using namespace std;

int main (){
    // Inutualize variable
    int User_Input;
    int i;
    cout << "Enter a integer: ";

    // Gets the user input

    cin >> User_Input;

    for (i = User_Input; i >= 0; i--){
        cout << i << endl;
    }
    cout << "Blast off!" << endl;
}