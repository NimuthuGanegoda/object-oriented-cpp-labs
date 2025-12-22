// CSP2104 - 2024 Semester 1, ECU - Martin Masek
#include <iostream>
#include <algorithm>
using namespace std;
using std::max;
using std::min;
const int worldMaxRow = 10, worldMaxCol = 10;
char world[worldMaxRow][worldMaxCol];
char screen[worldMaxRow][worldMaxCol];
char playerIcon = 'P';
int main()
{
    int score = 0;
int playerRow = 5, playerCol = 5;
char movement = 0;
// initialise world
for (int i = 0; i < worldMaxRow; i++)
{
for (int j = 0; j < worldMaxCol; j++)
{
world[i][j] = '.';
}
}
// Game loop
while (true) // yes, its infinite! (Ctrl-C to break from program)
{
// draw the world:
// 1 - first copy the world to the screen array
for (int i = 0; i < worldMaxRow; i++)
{
for (int j = 0; j < worldMaxCol; j++)
{
screen[i][j] = world[i][j];
}
}
// 2 - now draw the player position on the screen array
screen[playerRow][playerCol] = playerIcon;
// 3 - now print the screen array to the actual screen
#ifdef _WIN32
        system("CLS");
        #else
        system("clear");
        #endif
        for (int i = 0; i < worldMaxRow; i++)
        {
for (int j = 0; j < worldMaxCol; j++)
{
cout << screen[i][j];
}
cout << "\n";
}
// get player input & update position
cout << "Enter w,a,s or d to move: ";
cin >> movement;
if (movement == 'w') playerRow = max(0, playerRow-1);
if (movement == 's') playerRow = min(worldMaxRow-1, playerRow+1);
if (movement == 'a') playerCol = max(0, playerCol-1);
if (movement == 'd') playerCol = min(worldMaxCol - 1, playerCol+1);
    }

    return 0;
}