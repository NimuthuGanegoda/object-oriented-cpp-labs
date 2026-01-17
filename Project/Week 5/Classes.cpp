#include <iostream>
using namespace std;

class Person
{
    public:
        Person()
        ~Person()

    private:
}

Person:Person()
{
    cout << "I'm the constructor !" << endl;
}

Person:~Person()
{
    cout << "I'm the distructor !" << endl;
}

int main()
{
    Person FirstPerson;
}

