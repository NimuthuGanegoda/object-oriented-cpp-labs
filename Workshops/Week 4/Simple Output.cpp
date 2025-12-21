#include <iostream>
using namespace std;

int PrintHelloAgain()
{
    int n = 0;
    string reply;
    cout << "Do you want to print Hello again? :";
    cin >> reply;
    while(reply == "yes")
    {
        cout << "Hello !" << endl;
        n++;
        cout << "Do you want to print Hello again? :";
        cin >> reply;
    }
    return n;
}

int main()
{
    int noforepetions = PrintHelloAgain();
    cout << "No of repetitions: " << noforepetions << endl;
}