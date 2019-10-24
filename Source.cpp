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
	bool placesAvaialable;
	srand(time(NULL));

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] == '2')
			{
				//maze[i][j] = '3'; // found them
				//check for avaialable places arround where the walker is
				placesAvaialable = false;
				for (int minRow = i - 1; minRow <= i + 1; minRow++)
				{
					for (int minCol = j - 1; minCol <= j + 1; minCol++)
					{
						if (maze[minRow][minCol] != '*' && maze[minRow][minCol] != '2')
						{
							placesAvaialable = true;
							break;
						}
					}

				}
				// generate random free space to move the walter
				if (placesAvaialable)
				{
					//std::cout << i << " " << j << std::endl;
					
					int randRow = rand() % 3 - 1;
					int randCol = rand() % 3 - 1;
					bool moving = true;
					while (moving)
					{
						//std::cout << "Entering while (moving)" << std::endl;
						if (maze[i+randRow][j+randCol] == ' ' || (maze[i + randRow][j + randCol] >= 'A' && maze[i + randRow][j + randCol] <= 'Y'))
						{
							maze[i+randRow][j+randCol] = '3'; // change walker symbol to don't try it again
							maze[i][j] = ' ';
							moving = false;
							break;
						}
						else
						{
							randRow = rand() % 3 - 1;
							randCol = rand() % 3 - 1;
						} 
					} 
					//std::cout << "--------------------------------Leaving while (moving)" << std::endl;
				}
			}
		}
	}
	// cheange all the players back to their original symbol
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] == '3')
			{
				maze[i][j] = '2';
			}
		}
	}
}
bool checkWin(int numRows, int numCols, char maze[10][10])
{
	int count = 0;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (maze[i][j] >= 'A' && maze[i][j] <= 'Y')
			{
				count++;
			}
		}
	}
	return(count == 0);
}
int main()
{
	srand(time(NULL));
	const int numRows = 10;
	const int numCols = 10;
	char  maze[numRows][numCols] = {{'*','*','*','*','*','*','*','*','*','*'},
									{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
									{'*',' ','*','*','*','*',' ','*',' ','*'},
									{'*',' ',' ',' ','*',' ',' ','*',' ','*'},
									{'*',' ',' ','*','*','*',' ','*',' ','*'},
									{'*','*',' ',' ',' ','*',' ','*','*','*'},
									{'*',' ',' ','*',' ','*',' ','*',' ','*'},
									{'*','*',' ','*','*','*',' ','*','*','*'},
									{'*',' ',' ',' ',' ','*',' ',' ',' ','*'},
									{'*','*','*','*','*','*','*','*','*','*'} };
	char c = ' ';
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
		//cin >> c;
		std::cout << "\nPress the RETURN key to continue OR 'x' to exit!" << std::endl;
		c = getchar();
		if (checkWin(numRows, numCols, maze))
		{
			std::cout << "No more plants! You Won!" << std::endl;
			break;
		}
		changePlants(numRows, numCols, maze);
		moveWalkers(numRows, numCols, maze);
	}	
}