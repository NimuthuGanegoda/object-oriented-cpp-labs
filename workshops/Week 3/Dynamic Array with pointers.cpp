#include <iostream>
#include <cstdlib>  // for rand() and RAND_MAX
using namespace std;

int main()  // Changed from void main() - C++ standard requires int main()
{
    int noofinteractions = 0;
    cout << "How many times you need to run this program?";
    cin >> noofinteractions;

    for (int j = 1; j <= noofinteractions; j++)
    {
        int no;
        cout << " Enter the number of elements : ";
        cin >> no;
    }
    
    // Creating the array
    double* A = new double[no];
    double* B = new double[no];
    double* C = new double[no];

    // The array holder is filled with numbers
    for (int i = 0; i < no; i++)
     {
        A[i] = static_cast<double>(rand()) / RAND_MAX;  // Fixed: cast rand(), not the division result
        B[i] = static_cast<double>(rand()) / RAND_MAX;
     }

     // Multiply the arrays and assign the values to the array c
     for (int i = 0; i < no; i++)
        {
            C[i] = A[i] * B[i];
        }

        // All the elements to the array C
        double total = 0.0;
        for (int i = 0; i < no; i++)
        {
            total += C[i];  // Fixed: removed redundant "total = total +="
        }
        cout << " Total is : " << total << endl;
        
        delete [] A;
        delete [] B;
        delete [] C;
    return 0;  // Added required return statement
}