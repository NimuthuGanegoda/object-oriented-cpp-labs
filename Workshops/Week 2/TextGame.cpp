#include <iostream>
#include <algorithm>

using namespace std;

const int worldMaxRow = 10, worldMaxCol = 10;
char world[worldMaxRow][worldMaxCol];
char screen[worldMaxRow][worldMaxCol];
char playerIcon = 'P';

int main() {
    int playerRow = 5, playerCol = 5;
    char movement = 0;

    // initialise world
    for (int i = 0; i < worldMaxRow; i++) {
        for (int j = 0; j < worldMaxCol; j++) {
            world[i][j] = '.';
        }
    }

    // Game loop
    while (true) {
        // 1 - copy world to screen
        for (int i = 0; i < worldMaxRow; i++) {
            for (int j = 0; j < worldMaxCol; j++) {
                screen[i][j] = world[i][j];
            }
        }

        // 2 - draw player
        screen[playerRow][playerCol] = playerIcon;

        // 3 - print screen
        cout << "\033[2J\033[1;1H"; // ANSI clear screen

        for (int i = 0; i < worldMaxRow; i++) {
            for (int j = 0; j < worldMaxCol; j++) {
                cout << screen[i][j];
            }
            cout << "\n";
        }

        cout << "Enter w,a,s or d to move (q to quit): ";
        cin >> movement;

        if (movement == 'q') break;

        if (movement == 'w') playerRow = max(0, playerRow - 1);
        if (movement == 's') playerRow = min(worldMaxRow - 1, playerRow + 1);
        if (movement == 'a') playerCol = max(0, playerCol - 1);
        if (movement == 'd') playerCol = min(worldMaxCol - 1, playerCol + 1);
    }
    return 0;
}
