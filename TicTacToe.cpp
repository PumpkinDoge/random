#include <iostream>
const int SIZE = 3;


// Module checks to see if the board has a winning arrangement.
bool checkWin(char array[SIZE][SIZE], char player)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i][0] == player && array[i][1] == player && array[i][2] == player)
		{
			return true;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (array[0][i] == player && array[1][i] == player && array[2][i] == player)
		{
			return true;
		}
	}
	 
	if (array[0][0] == player && array[1][1] == player && array[2][2] == player)
	{
		return true;
	}
	else if (array[2][0] == player && array[1][1] == player && array[0][2] == player)
	{
		return true;
	}
}

// Module prints the board
void printBoard(char array[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << " | ";
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << array[i][j] << " | ";

		}
		std::cout << "\n";
	}
}

int main()
{
	int row;
	int col;
	
	char board[SIZE][SIZE] =
	{
		{'_','_','_'},
		{'_','_','_'},
		{'_','_','_'},
	};
	
	printBoard(board);

	while (true)
	{
		// This section of the code operates the turn of Player "X"
		std::cout << "(PLAYER X) Please pick your row and then column: " << std::endl;
		std::cin >> row >> col;
		std::cout << "\n";

		// Checks to see if the input is valid (e.g. column/row doesn't exist or spot has already been used.)
		while (board[row - 1][col - 1] != '_')
		{
			std::cout << "This spot is already taken or invalid. Please try again." << std::endl;
			std::cout << "(PLAYER X) Please pick your row and then column: " << std::endl;
			std::cin >> row >> col;
		}
		board[row - 1][col - 1] = 'X';
		
		printBoard(board);
		
		if (checkWin(board,'X') == true)
		{
			std::cout << "Game Over! Player X has won!";
			std::cout << "\n";
			break;
		}
		
		
		// This section of the code operates the turn of Player "O"
		std::cout << "(PLAYER O) Please pick your row and then column: " << std::endl;
		std::cin >> row >> col;
		std::cout << "\n";
		
		// Checks to see if the input is valid (e.g. column/row doesn't exist or spot has already been used.)
		while (board[row - 1][col - 1] != '_')
		{
			std::cout << "This spot is already taken or invalid. Please try again." << std::endl;
			std::cout << "(PLAYER O) Please pick your row and then column: " << std::endl;
			std::cin >> row >> col;
		}

		board[row - 1][col - 1] = 'O';
		printBoard(board);

		if (checkWin(board, 'O') == true)
		{
			std::cout << "Game Over! Player O has won!";
			std::cout << "\n";
			break;
		}
	}
	
}