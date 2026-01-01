#include<iostream>
#include <cstring>
using namespace std;

void printHI();

int main() {

    int x;
    string answer;
    cout << "Do you want to be greeted? (y/n): ";
    getline(cin, answer);
    
    if (answer == "y"){
        printHelloagain()
    else {
        if (answer == "n"){
            cout << "No greeting will be printed.";
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.";
        }
    }
    }

    return 0;


}
void printhelloagain() {
    int x;
    cout << "Hello";
    cout << "Do you want play again? (y/n): ";
   cin >> answer;
   if (answer == "y"){
       printhelloagain();
   };
}