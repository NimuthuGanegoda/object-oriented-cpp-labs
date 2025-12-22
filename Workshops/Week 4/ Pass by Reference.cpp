include<iostream>
#include<vector>
#include<chrono>
using namespace std;
void printByCopy(vector<int> numbers)
{
cout << "Hello from printByCopy\n";
if (numbers.size() > 0)
{
cout << "First element is: " << numbers[0] << "\n\n";
}
}
void printByReference(vector<int> &numbers)
{
cout << "Hello from printByReference\n";
if (numbers.size() > 0)
{
cout << "First element is: " << numbers[0] << "\n\n";
}
}
void main()
{
Page 5 of 6
// vector of integers
vector<int> num;
// fill the vector
const int size = 99999999;
for (int i = 0; i < size; i++)
{
num.push_back(rand());
}
// get start time
auto start = chrono::high_resolution_clock::now();
printByCopy(num);
// get stop time and work out duration
auto stop = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
//auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
cout << "That took: " << duration.count() << " nanoseconds\n";
// get start time
auto start2 = chrono::high_resolution_clock::now();
printByReference(num);
// get stop time and work out duration
auto stop2 = chrono::high_resolution_clock::now();
auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);
cout << "That took: " << duration2.count() << " nanoseconds\n";
}