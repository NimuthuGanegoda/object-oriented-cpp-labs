#include <iostream>
#include "Calc.h"

using namespace std;

int main() {
    // Int
    Calc<int> intCalc;
    cout << "Int: 4 * 3 = " << intCalc.multiply(4, 3) << endl;
    cout << "Int: 4 + 3 = " << intCalc.add(4, 3) << endl;

    // Double
    Calc<double> doubleCalc;
    cout << "Double: 8.2 * 1.7 = " << doubleCalc.multiply(8.2, 1.7) << endl;
    cout << "Double: 8.2 + 1.7 = " << doubleCalc.add(8.2, 1.7) << endl;

    // Float
    Calc<float> floatCalc;
    cout << "Float: 5.3 * 0.75 = " << floatCalc.multiply(5.3f, 0.75f) << endl;
    cout << "Float: 5.3 + 0.75 = " << floatCalc.add(5.3f, 0.75f) << endl;

    // Char
    Calc<char> charCalc;
    cout << "Char: 'Z' * 'A' = " << charCalc.multiply('Z', 'A') << endl;
    cout << "Char: 'Z' + 'A' = " << charCalc.add('Z', 'A') << endl;

    return 0;
}
