#include <iostream>
using namespace std;

struct Words {
    string name;
    string type;
    string Definition;
};

int main()
{
    Words word1;

    word1.name = "Nima";
    word1.type = "Noun";
    word1.Definition = "Goes to the same university";

    Words word2;

    word2.name = "Nima";
    word2.type = "Noun";
    word2.Definition = "Maneat";

    Words word3;

    word3.name = "Neo";
    word3.type = "Noun";
    word3.Definition = "The One";

    cout << "The name "
}