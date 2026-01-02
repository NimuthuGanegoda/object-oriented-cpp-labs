#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

// struct holds information for the name of the structure Word
struct Word {
    string name;
    string type;
    string definition;
};

// convert a string to lowercase
string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
