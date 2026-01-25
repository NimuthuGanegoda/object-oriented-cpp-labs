#include <iostream>
using namespace std;

int main() {
    int max = 10;
    int first = 0;
    int second = 1;
    int temp = 0;

    cout << first << ", " << second << ", ";
    for (int j = 0; j < max; j++) {
        temp = second;
        second = first + second;
        first = temp;
        cout << second;
        if (j < max - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}
