#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Employee {
    string name;
};

int main() {
    vector<Employee> employees;
    string filename = "names.txt";
    string record;

    cout << "Attempting to read text file..." << endl;
    ifstream myfile(filename);

    if (myfile.is_open()) {
        while (getline(myfile, record)) {
            // Check for empty lines
            if (record.empty()) continue;
             // check that the current line is not a comment
            if (record.length() < 2 || !(record.substr(0,2) == "//")) {
                Employee currentRecord;
                currentRecord.name = record;
                employees.push_back(currentRecord);
            }
        }
        myfile.close();

        for (const auto& employee : employees) {
            cout << "Employee name: " << employee.name << endl;
        }
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}
