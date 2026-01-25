#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    if (!(cin >> size)) return 0;

    int* arr = new int[size];
    for(int i=0; i<size; i++) {
        arr[i] = i * 2;
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
