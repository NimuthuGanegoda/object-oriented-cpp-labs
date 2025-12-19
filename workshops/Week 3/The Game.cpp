#include<iostream>
#include<fstream> // to read files
#include<string> // for working with strings (eg. getline)
#include<math.h>
#include<algorithm>
#include<cstdlib>
using namespace std;

string fileName = "map.txt";
int worldMaxRow = 10, worldMaxCol = 10; // no longer need to be const
char** world = NULL;
char** screen = NULL;

//char world[worldMaxRow][worldMaxCol];
//char screen[worldMaxRow][worldMaxCol];
char playerIcon = 'P';

int main()
{
	int score = 0;
	int playerRow = 5, playerCol = 5;
	char movement = 0;

	// get the rows and columns from the file
	worldMaxRow = 0;
	worldMaxCol = 0;
	ifstream mapFile(fileName);
	if (mapFile.is_open())
	{
		string lineBuffer;
		while (!mapFile.eof())
		{
			worldMaxRow++; // for each line in the file, add a row
			getline(mapFile, lineBuffer);
			if (worldMaxCol == 0)
			{
				worldMaxCol = lineBuffer.size(); // initialise maxCol
			}
			else
			{
				// this will make maxCol based on the shortest row in the file
				worldMaxCol = min(worldMaxCol, (int)lineBuffer.size());
			}
		}
		mapFile.close();
	}
	else
	{
		cout << "File not found!";
		return 1; // exit the program before all hell breaks loose!
	}

	// Now we know the size, we can allocate memory, and read the file in again.
	
	// allocate the memory for the arrays
	world = new char* [worldMaxRow];
	screen = new char* [worldMaxRow];
	for (int i = 0; i < worldMaxRow; i++)
	{
		world[i] = new char[worldMaxCol];
		screen[i] = new char[worldMaxCol];
	}

	// load the world map
	mapFile.open(fileName);
	if (mapFile.is_open())
	{
		string lineBuffer;
		for (int i = 0; i < worldMaxRow; i++)
		{
			getline(mapFile, lineBuffer);
			for (int j = 0; j < worldMaxCol; j++)
			{
				world[i][j] = lineBuffer[j];
			}
		}
		mapFile.close();
	}
	else
	{
		// unlikely, since we just read it to find the size - but possible
		cout << "the file dissapeared!\n"; return 1;
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
		if (movement == 'w') playerRow = max(0, playerRow - 1);
		if (movement == 's') playerRow = min(worldMaxRow - 1, playerRow + 1);
		if (movement == 'a') playerCol = max(0, playerCol - 1);
		if (movement == 'd') playerCol = min(worldMaxCol - 1, playerCol + 1);
	}

	// delete the arrays
	for (int i = 0; i < worldMaxRow; i++)
	{
		delete[] world[i];
		delete[] screen[i];
	}
	delete[] world;
	delete[] screen;
	return 0;
}

