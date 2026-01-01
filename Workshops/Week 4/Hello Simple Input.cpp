#include <iostream>
using namespace std;

void printHI(int num);

int main() {

    int loop_amount; 
    int x;
    int num;
    cout << "Enter the number of times to print Hello: ";
    cin >> loop_amount;

    int printHI(loop_amount);

}
void printHI(int num) {
    int x;
    for (x = 0; x < num; x++){
        cout << "Hello" << endl;
    };
}