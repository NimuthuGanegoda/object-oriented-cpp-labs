#include <iostream>

using namespace std;

struct Student {
    int creditHours;
    double gradePointAverage;
};

int main() {
    // Activity 1: Evaluate expressions
    {
        int a = 0, b = 1, c = 5;
        cout << "--- Activity 1 ---" << endl;
        // Evaluate each expression using original values (resetting where needed)
        cout << "a + b = " << (a + b) << endl;
        cout << "a > b = " << (a > b) << endl;
        cout << "3 + b * c = " << (3 + b * c) << endl;

        // ++b
        int b_copy = b;
        cout << "++b = " << (++b_copy) << endl;

        // b++
        b_copy = b;
        cout << "b++ = " << (b_copy++) << endl;

        cout << "b <= c = " << (b <= c) << endl;
        cout << "a > 5 = " << (a > 5) << endl;

        // ++a == b
        int a_copy = a;
        cout << "++a == b = " << (++a_copy == b) << endl;

        cout << "b != c = " << (b != c) << endl;
        cout << "b == c = " << (b == c) << endl;

        // b = c
        b_copy = b;
        cout << "b = c evaluates to " << (b_copy = c) << endl;

        cout << "b / c = " << (b / c) << endl;
        cout << "b % c = " << (b % c) << endl;
        cout << "b + c * 4 / 3 = " << (b + c * 4 / 3) << endl;
        cout << "22 / (c + 3) = " << (22 / (c + 3)) << endl;
        cout << endl;
    }

    // Activity 2: Console application
    {
        cout << "--- Activity 2 ---" << endl;
        int a, b, c;
        double x, y, z;
        a = 13;
        b = 4;
        x = 3.3;
        y = 15.78;
        c = a + b;
        cout << "a + b is " << c << endl;
        z = x + y;
        cout << "x + y is " << z << endl;
        c = a / b;
        cout << "a / b is " << c << endl;
        c = a % b;
        cout << "a % b is " << c << endl;

        // Activity 3: Prefix/Postfix
        cout << "--- Activity 3 ---" << endl;
        a = 2;
        c = ++a;
        cout << "a is " << a << " and c is " << c << endl;
        a = 2;
        c = a++;
        cout << "a is " << a << " and c is " << c << endl;
        cout << endl;
    }

    // Activity 4: Student struct
    {
        cout << "--- Activity 4 ---" << endl;
        Student oneStudent;
        const int HOURS_REQUIRED_TO_GRADUATE = 120;

        cout << "Please enter a student's credit hours: ";
        if (!(cin >> oneStudent.creditHours)) return 0; // Guard against bad input if running non-interactively
        cout << "Please enter the student's grade point average: ";
        cin >> oneStudent.gradePointAverage;

        cout << "The number of credit hours is " << oneStudent.creditHours << endl;
        cout << "The grade point average is " << oneStudent.gradePointAverage << endl;

        int hoursRemaining = HOURS_REQUIRED_TO_GRADUATE - oneStudent.creditHours;
        cout << "This student needs " << hoursRemaining << " more credit hours to graduate" << endl;

        const double PASSING_GPA = 3.2;
        bool isPassing = oneStudent.gradePointAverage >= PASSING_GPA;
        bool hasGraduated = hoursRemaining <= 0;

        cout << "Is passing? " << isPassing << endl;
        cout << "Has graduated? " << hasGraduated << endl;
    }

    return 0;
}
