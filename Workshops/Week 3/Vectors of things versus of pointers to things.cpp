#include<iostream>
#include<vector>
using namespace std;

struct Stuff
{
    int x;
};

void main()
{
    Stuff myStuff;
    vector<Stuff> someStuff;
    myStuff.x = 1;
    someStuff.push_back(myStuff);
    myStuff.x = 2;
    someStuff.push_back(myStuff);

    Stuff otherStuff;
    vector<Stuff*> collection;
    otherStuff.x = 3;
    collection.push
}