#include<iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;

// define the Employee struct
struct Employee
{
	string name;
};

int main()
{
	// a vector to hold all the employees from the file
	vector<Employee> employees;

	string filename = "names.txt";
	long begin, end, lineNumber;
	string record;
	cout << "Attempting to read text file...\n";
	ifstream myfile(filename);

	if (myfile.is_open())
	{
		// an Employee instance to store the currently read name
		Employee currentRecord;
		while (getline(myfile, record))
		{
			// check that the current line is not a comment and has content
			if (record.size() >= 2 && record.substr(0, 2) == "//")
			{
				continue;
			}
			if (record.empty())
			{
				continue;
			}
			// copy the read in line of text to the employee record
			currentRecord.name = record;
			// put the employee record into the vector employees
			employees.push_back(currentRecord);
		}
		myfile.close();
		// now print all the records
		for (Employee employee : employees)
		{
			cout << "Employee name: " << employee.name << endl;
		}

	}
	else cout << "Unable to open file";
	return 0;
}
