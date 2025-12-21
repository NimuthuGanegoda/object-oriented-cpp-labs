#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	const int arraySize = 10;

	// create three double arrays A, B and C
	double A[arraySize];
	double B[arraySize];
	double C[arraySize];

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
	cout << "Total: " << total << "\n";
	return 0;
}
