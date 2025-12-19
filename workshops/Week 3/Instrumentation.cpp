#include<iostream>
#include<chrono>
#include<cstdlib>

using namespace std;

int main()
{
	int arraySize = 10;
	int numberOfTimes = 100;
	int printIterations = 1;

	cout << "What size arrays do you want to use? ";
	cin >> arraySize;

	// create three double arrays A, B and C
	double* A = new double[arraySize];
	double* B = new double[arraySize];
	double* C = new double[arraySize];

	bool stop = false;
	while (!stop)
	{
		cout << "Enter iterations: "; cin >> numberOfTimes;
		cout << "Enter iterations between printing: "; cin >> printIterations;

		// get the start time
		auto start = chrono::high_resolution_clock::now();
		for (int j = 0; j < numberOfTimes; j++)
		{
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
			if (j % printIterations == 0)
			{
				cout << total << "\n";
			}
		}
		// get the stop time
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
		cout << "That took: " << duration.count() << " milliseconds\n";
	}
	delete[] A; delete[] B; delete[] C;
	return 0;
}
