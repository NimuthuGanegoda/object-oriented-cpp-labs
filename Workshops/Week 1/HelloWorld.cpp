#include <iostream>
#include <string>

using namespace std;

struct Person {
    string dateOfBirth;
};

int main() {
    Person person;
    cout << "What is your Date of Birth?" << endl;
    getline(cin, person.dateOfBirth);

    cout << "Hello, you are born on: " << person.dateOfBirth << endl;
    return 0;
}
