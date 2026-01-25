#include <iostream>
using namespace std;

class Person
{
public:
    Person();
    ~Person();

private:
    // empty
};

Person::Person()
{
    cout << "I'm the constructor !" << endl;
}

Person::~Person()
{
    cout << "I'm the destructor !" << endl;
}

int main()
{
    Person FirstPerson;
    return 0;
}
