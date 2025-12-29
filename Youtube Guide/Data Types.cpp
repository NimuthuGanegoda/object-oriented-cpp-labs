#include<iostream>

int main(){

    // Integer (whole numbers)
    int age = 21;
    int year = 2023;
    int days = 7;

    //double (number including decimal)
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 25.1;

    // single character
    char grade = 'A';
    char initial = 'B';
    char currency = '$';

    // boolean (true or false)
    bool student = true;
    bool power = false;
    bool forSale = false;

    // string (object that represents a sequence of text)
    std::string name = "Bro";
    std::string day = "Friday"; 
    std::string food = "Pizza";
    std::string address = "123 Main St";

    std::cout << "Hello " << name <<'\n';
    std::cout << "You are " << age << " years old" << '\n';
    return 0;
}