#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    

    // Initialization
    int array_size; 
    // Let the user define the size of the array
    cout << "Enter the size of the array: ";
    cin >> array_size;

    int i;
    int* array = new int[array_size];

    srand(time(0));

    // Creating the random number generator
    for (i =0; i < array_size; i++){
        array[i] = rand() % 11; // Random numbers between 1 and 10
    }

    cout << "The random numbers are: " << endl;
    // For loop to display 
    for (i = 0; i < array_size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete[] array;
    return 0;
}