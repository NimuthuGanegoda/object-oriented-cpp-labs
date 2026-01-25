#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Employee {
protected:
    int id;
    string name;
    double pay;
public:
    Employee(int id, string name, double pay) : id(id), name(name), pay(pay) {}
    virtual ~Employee() = default;

    virtual bool isManager() const { return false; }
    virtual bool isWorker() const { return false; }

    string getName() const { return name; }
    double getPay() const { return pay; }
    int getId() const { return id; }

    virtual void print() const {
        cout << "ID: " << id << ", Name: " << name << ", Pay: " << pay;
    }
};

class Manager : public Employee {
public:
    Manager(int id, string name, double pay) : Employee(id, name, pay) {}
    bool isManager() const override { return true; }
    void print() const override {
        cout << "[Manager] ";
        Employee::print();
        cout << endl;
    }
};

class Worker : public Employee {
public:
    Worker(int id, string name, double pay) : Employee(id, name, pay) {}
    bool isWorker() const override { return true; }
    void print() const override {
        cout << "[Worker] ";
        Employee::print();
        cout << endl;
    }
};

class HRSystem {
    vector<Employee*> employees;

public:
    ~HRSystem() {
        for (auto e : employees) {
            delete e;
        }
    }

    void load(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        int id;
        string name;
        string position;
        double pay;

        string line;

        while (file >> id) {
            file.ignore(); // newline after id
            getline(file, name);
            getline(file, position); // reads "manager" or "worker"

            // position might have trailing whitespace
            if (!position.empty() && position.back() == '\r') position.pop_back();
            if (!name.empty() && name.back() == '\r') name.pop_back();

            file >> pay;

            if (position.find("manager") != string::npos) {
                employees.push_back(new Manager(id, name, pay));
            } else if (position.find("worker") != string::npos) {
                employees.push_back(new Worker(id, name, pay));
            } else {
                employees.push_back(new Employee(id, name, pay));
            }
        }
        file.close();
    }

    void listEmployees() {
        cout << "--- All Employees ---" << endl;
        for (const auto& e : employees) {
            e->print();
        }
    }

    void listManagers() {
        cout << "--- Managers ---" << endl;
        for (const auto& e : employees) {
            if (e->isManager()) {
                cout << e->getName() << endl;
            }
        }
    }

    void listWorkers() {
        cout << "--- Workers ---" << endl;
        for (const auto& e : employees) {
            if (e->isWorker()) {
                cout << e->getName() << endl;
            }
        }
    }
};

int main() {
    HRSystem hr;
    hr.load("employees.txt");

    hr.listEmployees();
    cout << endl;
    hr.listManagers();
    cout << endl;
    hr.listWorkers();

    return 0;
}
