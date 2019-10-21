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
	int w = 0;
	while(w < walkers)
	{
		srand(time(NULL));
		int i = rand() % 10;
		srand(time(NULL));
		int j = rand() % 10;
		if (maze[i][j] != '*' || (maze[i][j] < 'A' && maze[i][j] < 'Y'))
		{
			maze[i][j] = '2';
			w++;
		}
	}
}
void placePlants(char maze[10][10], int plants, char namePlant)
{
	//srand(time(NULL));
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
void changePlants(int numRows, int numCols, char maze[10][10])
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] >= 'A' && maze[i][j] <= 'Y')
			{
				maze[i][j]--;
			}
			if (maze[i][j] == int('A') - 1)
			{
				maze[i][j] = 'Y';
			}
		}

	}
}

int main()
{
	const int numRows = 10;
	const int numCols = 10;
	char  maze[numRows][numCols] = {{'*',' ','*','*',' ','*','*','*',' ','*'},
									{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ','*','*','*',' ','*',' ',' '},
									{'*','*',' ',' ',' ','*',' ','*','*','*'},
									{'*','*',' ','*',' ','*',' ','*','*','*'},
									{'*','*',' ','*','*','*',' ',' ','*','*'},
									{'*','*',' ',' ',' ','*','*',' ','*','*'},
									{'*','*',' ','*',' ','*','*',' ','*','*'} };
	char c = 'a';
	bool postWalkersPlants = true;
	/////////////////// WALKERS
	srand(time(NULL));
	int numOfWalkers = rand() % 10 + 3;
	/////////////////// END WALKERS

	/////////////////// PLANTS
	srand(time(NULL));
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

		system("CLS");
		drawMaze(maze, numRows, numCols);
		cin >> c;
		changePlants(numRows, numCols, maze);
	}
		
}