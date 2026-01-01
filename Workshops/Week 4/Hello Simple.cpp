#include <iostream>
using namespace std;

void main() {

    int loop_amount; 
    int x;
    cout << "Enter the number of times to print Hello: ";
    cin >> loop_amount;

    for (x = 0; x < loop_amount; x++){
        cout << "Hello" << endl;
    }
}