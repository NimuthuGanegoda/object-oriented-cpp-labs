#include <iostream>
using namespace std;

int main()
{
// times tables
const int max = 10;
int times = 0;
cout << "Enter an integer to see its times tables: ";
cin >> times;
cout << "The " << times << " times table: \n";
for (int i = 0; i <= max; ++i)
{
    cout << i << " x " << times << " = " << (i * times) << "\n";
}

return 0;
}