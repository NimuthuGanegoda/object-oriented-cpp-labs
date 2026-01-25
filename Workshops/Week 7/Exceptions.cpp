#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

// a simple class to add exception handling to
class BaldysBasics
{
    string fileName;
    int numberArray[10] = { 0,0,0,0,0,0,0,0,0,0 };

    // divides 2 by a user provided denominator
    void divideTwoBy()
    {
        int denominator;
        cout << "Enter denominator: ";
        cin >> denominator;

        // check for error
        if (denominator == 0) throw (string("denominator is zero"));

        double x = 2.0 / denominator;
        cout << "2 / " << denominator << " = " << x << "\n\n";
    }

    // changing an element of an array
    void numberBetween0And9()
    {
        int enteredNumber;
        cout << "Enter a number between 0 and 9: ";
        cin >> enteredNumber;

        // check for validity
        if (enteredNumber < 0) throw (string("number too low"));
        if (enteredNumber > 9) throw (string("number too high"));

        numberArray[enteredNumber] = 1;
        cout << "Array element " << enteredNumber << " set to " << numberArray[enteredNumber] << "\n";
    }

    // lets the user enter a file name for 'later'
    void enterFileName()
    {
        cout << "Enter name of file to read: ";
        cin >> fileName;

        // check the file exists and throw exception if it doesnt
        ifstream fileCheck(fileName);
        if (!fileCheck.is_open())
        {
            throw (string("File could not be opened!"));
        }
        else
        {
            cout << "file exists!\n";
        }
        fileCheck.close();
    }

public:
    void menu()
    {
        while (true)
        {
            string choice;
            cout << "Baldy's Basics in Exception Handling\n";
            cout << "----------------------\n";
            cout << "1. Divide Two by\n";
            cout << "2. Number between 1 and 10\n";
            cout << "3. Enter file name\n";
            cout << "----------------------\n";
            cout << "enter choice (q to quit): ";
            cin >> choice;

            if (choice == "q") break;

            try
            {
                if (choice == "1")
                {
                    divideTwoBy();
                }
                else if (choice == "2")
                {
                    numberBetween0And9();
                }
                else if (choice == "3")
                {
                    enterFileName();
                }
            }
            catch (string exc)
            {
                cout << "\nError: " << exc << "!!\n\n";
            }
        }
    }
};

// test bed for the class
int main()
{
    BaldysBasics a;
    a.menu();
    return 0;
}
