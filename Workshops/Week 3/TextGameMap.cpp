#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    const int worldMaxRow = 10;
    const int worldMaxCol = 10;
    char** world = new char*[worldMaxRow];
    char** screen = new char*[worldMaxRow];

    for(int i=0; i<worldMaxRow; i++) {
        world[i] = new char[worldMaxCol];
        screen[i] = new char[worldMaxCol];
    }

    ifstream mapFile("map.txt");
    if(mapFile.is_open()) {
        string lineBuffer;
        for(int i=0; i<worldMaxRow; i++) {
            if(getline(mapFile, lineBuffer)) {
                for(int j=0; j<worldMaxCol; j++) {
                    if (j < lineBuffer.length())
                        world[i][j] = lineBuffer[j];
                    else
                        world[i][j] = '.';
                }
            }
        }
        mapFile.close();
    } else {
        cout << "Unable to open map.txt" << endl;
        return 1;
    }

    int playerRow = 5, playerCol = 5;
    char playerIcon = 'P';
    char movement = 0;
    char wall = '#';

    while(true) {
        // Copy world to screen
        for(int i=0; i<worldMaxRow; i++) {
            for(int j=0; j<worldMaxCol; j++) {
                screen[i][j] = world[i][j];
            }
        }

        // Draw player
        screen[playerRow][playerCol] = playerIcon;

        // Print screen
        cout << "\033[2J\033[1;1H"; // ANSI clear screen
        for(int i=0; i<worldMaxRow; i++) {
            for(int j=0; j<worldMaxCol; j++) {
                cout << screen[i][j];
            }
            cout << endl;
        }

        cout << "Enter w,a,s or d to move (q to quit): ";
        cin >> movement;
        if(movement == 'q') break;

        int potentialRow = playerRow;
        int potentialCol = playerCol;

        if (movement == 'w') potentialRow = max(0, playerRow - 1);
        if (movement == 's') potentialRow = min(worldMaxRow - 1, playerRow + 1);
        if (movement == 'a') potentialCol = max(0, playerCol - 1);
        if (movement == 'd') potentialCol = min(worldMaxCol - 1, playerCol + 1);

        if (world[potentialRow][potentialCol] != wall) {
            playerRow = potentialRow;
            playerCol = potentialCol;
        }
    }

    for(int i=0; i<worldMaxRow; i++) {
        delete[] world[i];
        delete[] screen[i];
    }
    delete[] world;
    delete[] screen;

    return 0;
}
