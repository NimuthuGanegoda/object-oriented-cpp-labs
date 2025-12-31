#include <iostream>
#include <csdlib>
using namespace std;

int main (){
    const int size = 10;
    int x;
    double A[size];
    double B[size];
    double C[size];

    for (int x =0; x< size; x++) {
        A[x] = rand();
        B[x] = rand();
        C[x] = rand();
    }
    cout << "Array A: ";

    for (x = 0; x < size -1 ; x++) {
        A[x] = static_cast<float>(rand()) / RAND_MAX;
        B[x] = static_cast<float>(rand()) / RAND_MAX;
        C[x] = static_cast<float>(rand()) / RAND_MAX;
    }

    // A
    cout << "Array A before sorting: [*";
    for (x = 0; x < size - 1; x++) {
        cout << A[x] << " ";
    }
    cout << endl;
    // B
    cout << "Array B before sorting: [*";
    for (x = 0; x < size - 1; x++) {
        cout << B[x] << " ";
    }
    cout << endl;
    // C
    cout << "Array C before sorting: [*";
    for (x = 0; x < size - 1; x++) {
        cout << C[x] << " ";
    }

    // Mulitplication

    for ( x = 0; x < size - 1; x++) {
        C[x] = A[x] * B[x];
    }

    cout << "Array C after multiplication: [*";
    for (x = 0; x < size - 1; x++) {
        cout << C[x] << " ";
    }
}
