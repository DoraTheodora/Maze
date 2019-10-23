// Theodora Tataru
// C00231174
#include <iostream>
#include <ctime>
using namespace std;

void drawMaze(char maze[10][10], int numRows, int numCols)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cout << maze[row][col] << " ";
		}
		cout<<endl;
	}
}
void placeWalkers(char maze[10][10], int walkers)
{
	srand(time(NULL));
	int w = 0;
	while(w < walkers)
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if (maze[i][j] != '*' && (maze[i][j] < 'A' && maze[i][j] < 'Y'))
		{
			maze[i][j] = '2';
			w++;
		}
	}
}
void placePlants(char maze[10][10], int plants, char namePlant)
{
	srand(time(NULL));
	int p = 0;
	while(p < plants)
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if (maze[i][j] != '*' && maze[i][j] != '2')
		{
			maze[i][j] = namePlant;
			p++;
		}
	}
}
bool checkForWalkers(int row, int col, char maze[10][10])
{
	int rowCheck;
	int colCheck;
	bool walkerFound = false;

	rowCheck = row;
	colCheck = col;

	while (rowCheck > 0 && maze[rowCheck][col] != '*')
	{
		rowCheck--;
		if (maze[rowCheck][col] == '2')
		{
			walkerFound = true;
			break;
		}
	}	
	if (!walkerFound)
	{
		rowCheck = row;
		while (rowCheck < 9 && maze[rowCheck][col] != '*')
		{
			rowCheck++;
			if (maze[rowCheck][col] == '2')
			{
				walkerFound = true;
				break;
			}
		}
	}
	if (!walkerFound)
	{
		colCheck = col;
		while (colCheck < 9 && maze[row][colCheck] != '*')
		{
			colCheck++;
			if (maze[row][colCheck] == '2')
			{
				walkerFound = true;
				break;
			}
		}
	}
	if (!walkerFound)
	{
		colCheck = col;
		while (colCheck > 0 && maze[row][colCheck] != '*')
		{
			colCheck--;
			if (maze[row][colCheck] == '2')
			{
				walkerFound = true;
				break;
			}
		}
	}
	return walkerFound;
}
void changePlants(int numRows, int numCols, char maze[10][10])
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] >= 'A' && maze[i][j] <= 'Y')
			{
				if (!checkForWalkers(i, j, maze))
				{
					maze[i][j]--;
				}
			}
			if (maze[i][j] == int('A') - 1)
			{
				if (!checkForWalkers(i, j, maze))
				{
					maze[i][j] = 'Y';
				}
			}
		}
	}
}
void moveWalkers(int numRows, int numCols, char maze[10][10])
{
	bool placesAvaialable = false;
	srand(time(NULL));

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] == '2')
			{
				//maze[i][j] = '3';
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	const int numRows = 10;
	const int numCols = 10;
	char  maze[numRows][numCols] = {{'*','*','*','*','*','*','*','*','*','*'},
									{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ',' ',' ','*',' ','*','*','*'},
									{'*','*',' ','*',' ','*',' ','*','*','*'},
									{'*','*',' ','*','*','*',' ',' ','*','*'},
									{'*','*',' ',' ',' ','*','*',' ','*','*'},
									{'*','*','*','*','*','*','*','*','*','*'} };
	char c = 'a';
	bool postWalkersPlants = true;
	/////////////////// WALKERS
	int numOfWalkers = rand() % 10 + 2;
	/////////////////// END WALKERS

	/////////////////// PLANTS
	char namePlant = rand() % 23 + 65;
	int numOfPlants = rand() % 10 + 2;
	////////////// END PLANTS


	while (c != 'x')
	{
		if (postWalkersPlants)
		{
			drawMaze(maze, numRows, numCols);
			placeWalkers(maze, numOfWalkers);
			placePlants(maze, numOfPlants, namePlant);
			postWalkersPlants = false;
		}

		system("CLS"); // clear screen
		drawMaze(maze, numRows, numCols);
		cin >> c;
		changePlants(numRows, numCols, maze);
		moveWalkers(numRows, numCols, maze);
	}
		
}