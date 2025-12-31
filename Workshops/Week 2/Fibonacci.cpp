#include <iostream>
using namespace std;

int main (){
    
    // Initialize variables 

    int const array_size = 20;
    int array[array_size];
    array [0] = 0;
    array [1] = 1;
    int i;

    for (i = 2; i < array_size; i++){
        array[i]} = array[i-1] + array[i-2];
    }
    cout << "The fibancachi Array [ 0 1]";
    
    // Display the fibancachi sequence
    for (i = 0; i < array_size - 2; i++){
        cout << array[i] << "";
    }
    cout << ""
}