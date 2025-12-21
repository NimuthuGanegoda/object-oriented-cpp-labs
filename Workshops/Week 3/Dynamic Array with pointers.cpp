#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int arraySize = 10;

	cout << "What size arrays do you want to use? ";
	cin >> arraySize;

	// create three double arrays A, B and C
	double* A = new double[arraySize];
	double* B = new double[arraySize];
	double* C = new double[arraySize];

	// Fill A and B with random numbers
	for (int i = 0; i < arraySize; i++)
	{
		A[i] = (double)rand() / RAND_MAX;
		B[i] = (double)rand() / RAND_MAX;
	}

	// vector multiplication
	for (int i = 0; i < arraySize; i++)
	{
		C[i] = A[i] * B[i];
	}
	// vector sum
	double total = 0;
	for (int i = 0; i < arraySize; i++)
	{
		total += C[i];
	}
	// print total
	cout << total << "\n";
	
	delete[] A; delete[] B; delete[] C;
	return 0;
}
