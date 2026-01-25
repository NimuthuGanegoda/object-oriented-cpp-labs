#include <iostream>
using namespace std;

int main()
{
    int value = 5;
    int* ptr = &value;

    cout << "Value: " << value << endl;
    cout << "Address: " << &value << endl;
    cout << "Pointer value: " << ptr << endl;
    cout << "Pointer dereference: " << *ptr << endl;

    *ptr = 10;
    cout << "New Value: " << value << endl;

    return 0;
}
