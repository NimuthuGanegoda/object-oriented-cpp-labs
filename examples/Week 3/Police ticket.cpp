#include <iostream>

using namespace std;

int main() 
{
    int driverAge, numTickets;
    double premiumDue = 75.32;
    cout << "Enter driver’s age: ";
    cin >> driverAge;
    cout << "Enter traffic tickets issued: ";
    cin >> numTickets;
    if (driverAge < 26)
    premiumDue += 100; // premiumDue = premiumDue + 100
    if (driverAge > 50)
        premiumDue -= 50; // premiumDue = premiumDue - 50
    if (numTickets == 2)
        premiumDue += 60.25; // premiumDue = premiumDue + 60.25
    cout << "Premium due is: " << premiumDue << endl;
    system("pause"); // This command is for Windows only. On Linux/Mac, it fails.
    return 0;
}