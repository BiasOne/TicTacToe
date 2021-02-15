#include <iostream>
#include <sstream>
//Joseph Morales
//This program is a console version of TIC TAC TOE
//SORRY CODE IS A BIT SLOPPY
//ALOT OF THE REDUNDANT PRINT METHODS CAN BE MOVED INTO A SEPERATE FUNCTION 
//WILL CLEAN THEM UP AT SOME POINT

//calling functions 
bool checkWin(char ticTacBoard[3][3], int count);
void clearBoard(char ticTacToe[3][3]);
void printBoard(char ticTacBoard[3][3]);
void playingGame(char ticTacToe[3][3]);

using namespace std;
bool win;

int main()
{	
	char ticTacBoard[3][3];	
	clearBoard(ticTacBoard);
	playingGame(ticTacBoard);		
	
	return 0;
}
//this function fills the 2d array with X and 0
void playingGame(char ticTacToe[3][3]) 
{
	//initializing/declaring variables w/default values
	string userInput = " ";
	stringstream iss(userInput);
	bool playing = true;
	bool playerOne = true;
	bool playerTwo = true;
	win = false;

	int userRow;
	int userColumn;	
	//using count to keep tack of hos many times a vector space has been filled.
	//if count ==8(index starts at 0- size =9) and win is still false its a draw.
	int count = 0;

	//Anytime a fresh game is starting it will begin here
	cout << "New Game : X goes first. " << endl;
	cout << endl;
	printBoard(ticTacToe);

	//boolean keeps track of the whether or not the game is still going on
	while (playing)
	{		
		//it will be playerOnes turn until you break out of the loop
		while (playerOne)
		{
			cout << "X's turn." << endl;
			cout << "Where do you want your X placed ?" << endl << "Please enter row number and column number separated by a space. " << endl;
			
			getline(cin, userInput);
			
			//splitstring and seperate them into 2 variables row/columns
			if (userInput.find(' ') == string::npos)
			{				
				cout << "Invalid entry: try again. " << endl << "Row & column numbers must be either 0, 1, or 2. " << endl;
				cout << endl;
				continue;
			}

			int found = userInput.find(' ');
			userRow = stoi(userInput.substr(0, found));
			userColumn = stoi(userInput.substr(found + 1));
			cout << "You have entered row #" << userRow << endl;
			cout << "	  and column #" << userColumn << endl;
			
			//if appropriate conditions are met the point in the 2d array will be replaced with X
			if ((ticTacToe[userRow][userColumn] != 'X' && ticTacToe[userRow][userColumn] != 'O') && (userColumn <= 2 && userRow <= 2))
			{				
				count++;
				ticTacToe[userRow][userColumn] = 'X';
				cout << "Thank you for your selection." << endl;
				checkWin(ticTacToe, count);
				printBoard(ticTacToe);
							
				break;
			}
			else if ((userColumn > 2 || userRow > 2))
			{
				cout << "Invalid entry: try again. " << endl << "Row & column numbers must be either 0, 1, or 2. " << endl;
				cout << endl;
			}
			else
			{
				cout << "That cell is already taken." << endl << "Please make another selection. " << endl;
				cout << endl;
			}
		}
		//checks for win condition(redundant can be removed will clean up at some point)
		if (win == true)		
		{			
				break;
		}
		//it will be playerTwos turn until you break out of the loop	
		while (playerTwo)
		{
			cout << "O's turn." << endl;
			cout << "Where do you want your O placed ?" << endl << "Please enter row number and column number separated by a space. " << endl;
			getline(cin, userInput);

			//splitstring and seperate them into 2 variables row/columns
			if (userInput.find(' ') == string::npos)
			{
				
				cout << endl;
				continue;
			}

			int found = userInput.find(' ');
			userRow = stoi(userInput.substr(0, found));
			userColumn = stoi(userInput.substr(found + 1));
			cout << "You have entered row #" << userRow << endl;
			cout << "	  and column #" << userColumn << endl;
			
			//if appropriate conditions are met the point in the 2d array will be replaced with O
			if ((ticTacToe[userRow][userColumn] != 'X' && ticTacToe[userRow][userColumn] != 'O') && (userColumn <= 2 && userRow <= 2))
			{
				count++;				
				ticTacToe[userRow][userColumn] = 'O';
				cout << "Thank you for your selection." << endl;
				checkWin(ticTacToe, count);
				printBoard(ticTacToe);
							
				break;
			}
			else if((userColumn > 2 || userRow > 2))
			{
				cout << "Invalid entry: try again. " << endl << "Row & column numbers must be either 0, 1, or 2. " << endl;
				cout << endl;
			}
			else
			{
				cout << "That cell is already taken." << endl << "Please make another selection. " << endl;
				cout << endl;
			}
		}
		//checks for win condition(redundant can be removed will clean up at some point)
		if (win == true)
		{
			break;
		}
	}
}
// function that checks for all win conditions
bool checkWin(char ticTacBoard[3][3], int count)
{
	char quitOrCont= NULL;

	for (int i = 0; i <= 2; i++)
	{
		//horizontal
		if (ticTacBoard[i][0] == ticTacBoard[i][1] && ticTacBoard[i][1] == ticTacBoard[i][2] && ticTacBoard[i][0] != NULL)
		{			
			win = true;
			cout << endl;
			//prints who the winner is and asks the user if they want to continue playing
			if (ticTacBoard[i][0] == 'X')
			{
				cout << "X IS THE WINNER!!!" << endl;
			}
			else if (ticTacBoard[i][0] == 'O')
			{
				cout << "O IS THE WINNER!!!" << endl;
			}		
			printBoard(ticTacBoard);
			cout << "Another game ? Enter Y or y for yes. " << endl;
			cin >> quitOrCont;

			if (quitOrCont == 'y' || quitOrCont == 'Y')
			{
				//clearing the board and starting a new game ignoring the current cin cache
				clearBoard(ticTacBoard);
				cin.ignore();
				playingGame(ticTacBoard);
			}
			else
			{
				cout << "Thank you for playing!" << endl;
				exit(1);
			}
		}

		//vertical
		else if (ticTacBoard[0][i] == ticTacBoard[1][i] && ticTacBoard[1][i] == ticTacBoard[2][i] && ticTacBoard[0][i] != NULL)
		{			
			win = true;
			cout << endl;
			//prints who the winner is and asks the user if they want to continue playing
			if (ticTacBoard[0][i] == 'X')
			{
				cout << "X IS THE WINNER!!!" << endl;
			}
			else if (ticTacBoard[0][i] == 'O')
			{
				cout << "O IS THE WINNER!!!" << endl;
			}
			printBoard(ticTacBoard);
			cout << "Another game ? Enter Y or y for yes. " << endl;
			cin >> quitOrCont;
			if (quitOrCont == 'y' || quitOrCont == 'Y')
			{
				//clearing the board and starting a new game ignoring the current cin cache
				clearBoard(ticTacBoard);
				cin.ignore();
				playingGame(ticTacBoard);
			}
			else
			{
				cout << "Thank you for playing!" << endl;
				exit(1);
			}
		}
	}
	//diagnal
	if (ticTacBoard[0][0] == ticTacBoard[1][1] && ticTacBoard[1][1] == ticTacBoard[2][2] && ticTacBoard[0][0] != NULL)
	{		
		win = true;
		cout << endl;
		//prints who the winner is and asks the user if they want to continue playing
		if (ticTacBoard[0][0] == 'X')
		{
			cout << "X IS THE WINNER!!!" << endl;
		}
		else if (ticTacBoard[0][0] == 'O')
		{
			cout << "O IS THE WINNER!!!" << endl;
		}		
		printBoard(ticTacBoard);
		cout << "Another game ? Enter Y or y for yes. " << endl;
		cin >> quitOrCont;
		if (quitOrCont == 'y' || quitOrCont == 'Y')
		{
			//clearing the board and starting a new game ignoring the current cin cache
			clearBoard(ticTacBoard);
			cin.ignore();
			playingGame(ticTacBoard);
		}

		else
		{
			cout << "Thank you for playing!" << endl;
			exit(1);
		}
	}
	//diagnal
	else if (ticTacBoard[2][0] == ticTacBoard[1][1] && ticTacBoard[1][1] == ticTacBoard[0][2] && ticTacBoard[2][0] != NULL)
	{		
		win = true;
		cout << endl;
		//prints who the winner is and asks the user if they want to continue playing
		if (ticTacBoard[2][0] == 'X')
		{
			cout << "X IS THE WINNER!!!" << endl;
		}
		else if (ticTacBoard[2][0] == 'O')
		{
			cout << "O IS THE WINNER!!!" << endl;
		}
		
		printBoard(ticTacBoard);
		cout << "Another game ? Enter Y or y for yes. " << endl;
		cin >> quitOrCont;

		if (quitOrCont == 'y' || quitOrCont == 'Y')
		{
			//clearing the board and starting a new game ignoring the current cin cache
			clearBoard(ticTacBoard);
			cin.ignore();
			playingGame(ticTacBoard);
		}
		else
		{
			cout << "Thank you for playing!" << endl;
			exit(1);
		}		
	}
	//draw conditions
	else if (count == 9 && win == false)
	{
		cout << endl;
		//prints who the winner is and asks the user if they want to continue playing
		cout << "DRAW! NOBODY WINS! " << endl;
		printBoard(ticTacBoard);
		cout << "Another game ? Enter Y or y for yes. " << endl;
		cin >> quitOrCont;

		if (quitOrCont == 'y' || quitOrCont == 'Y')
		{
			clearBoard(ticTacBoard);
			cin.ignore();
			playingGame(ticTacBoard);
		}
		else
		{
			cout << "Thank you for playing!" << endl;
			exit(1);
		}
	}
	//else the game continues
	else
	{
		win = false;
	}
	return win;
}


void printBoard(char ticTacBoard[3][3])
{	
	//prints the tic tac toe board
	cout << "-----------------" << endl;
	cout << "|R/C| 0 | 1 | 2 | " << endl;
	cout << "-----------------" << endl;
	cout << "| 0 | " << ticTacBoard[0][0] << " | " << ticTacBoard[0][1] << " | " << ticTacBoard[0][2] << " | " << endl;
	cout << "-----------------" << endl;
	cout << "| 1 | " << ticTacBoard[1][0] << " | " << ticTacBoard[1][1] << " | " << ticTacBoard[1][2] << " | " << endl;
	cout << "-----------------" << endl;
	cout << "| 2 | " << ticTacBoard[2][0] << " | " << ticTacBoard[2][1] << " | " << ticTacBoard[2][2] << " | " << endl;
	cout << "----------------- " << endl;
	cout << endl;
}
 
void clearBoard(char ticTacToe[3][3])
{
	//reinitiaize board with empty characters
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			ticTacToe[i][j] = NULL;
		}
	}
}

