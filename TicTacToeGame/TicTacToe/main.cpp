#include <iostream>
#include <string>
#include "TicTacToeGame.h"

std::string PlayerName1 = "";
std::string PlayerName2 = "";

void PrintIntro();
void PlayGame();
void GetPlayerNames();
void GetValidCoordinate();
void PrintBoard();
void PrintGameSummary();
bool AskToPlayAgain();

TicTacToeGame TTTGame;

int main()
{
	bool bPlayAgain = true;

	do
	{
		PrintIntro();
		GetPlayerNames();
		PrintBoard();
		PlayGame();
		PrintGameSummary();
		TTTGame.Reset();
	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;
	std::cout << "Enter coordinate pairs to make your move! Player 1 is always X." << std::endl << std::endl;

	return;
}

void PlayGame()
{
	TTTGame.Reset();
	do
	{
		GetValidCoordinate();
		PrintBoard();
		TTTGame.Player = !TTTGame.Player;
		TTTGame.Moves++;
	} while (TTTGame.GameWinner() == "");
	return;
}

void GetPlayerNames()
{
	std::cout << "Player 1's name: ";
	std::getline(std::cin, PlayerName1);
	std::cout << "Player 2's name: ";
	std::getline(std::cin, PlayerName2);

	system("cls");
	return;
}

void GetValidCoordinate()
{
	int Coordx = 0;
	int Coordy = 0;

	if (TTTGame.Player) 
	{
		std::cout << PlayerName1 << "'s turn." << std::endl;
	}
	else
	{
		std::cout << PlayerName2 << "'s turn." << std::endl;
	}

	do
	{
		while (true)
		{
			std::cout << "Please enter the x coordinate (1-3): " << std::endl;
			std::cin >> Coordx;

			if (Coordx >= 1 && Coordx <= 3)
			{
				break;
			}
			else
			{
				std::cout << "Invalid input." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		while (true)
		{
			std::cout << "Please enter the y coordinate (1-3): " << std::endl;
			std::cin >> Coordy;

			if (Coordy >= 1 && Coordy <= 3)
			{
				break;
			}
			else
			{
				std::cout << "Invalid input." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	} while (!TTTGame.CheckCoordinate(Coordx, Coordy));

	system("cls");
	return;
}

void PrintBoard()
{
	std::cout << "^ 1   " << TTTGame.Coords[0] << " | " << TTTGame.Coords[1] << " | " << TTTGame.Coords[2] << " " << std::endl;
	std::cout << "|    -----------" << std::endl;
	std::cout << "| 2   " << TTTGame.Coords[3] << " | " << TTTGame.Coords[4] << " | " << TTTGame.Coords[5] << " " << std::endl;
	std::cout << "|    -----------" << std::endl;
	std::cout << "Y 3   " << TTTGame.Coords[6] << " | " << TTTGame.Coords[7] << " | " << TTTGame.Coords[8] << " " << std::endl << std::endl;
	std::cout << "      1   2   3" << std::endl;
	std::cout << "      X ------->" << std::endl << std::endl;

	return;
}

void PrintGameSummary()
{
	if (TTTGame.GameWinner() == "x")
	{
		std::cout << PlayerName1 << " wins!" << std::endl;
	}
	else if (TTTGame.GameWinner() == "o")
	{
		std::cout << PlayerName2 << " wins!" << std::endl;
	}
	else if (TTTGame.GameWinner() == "tie")
	{
		std::cout << "It's a tie!" << std::endl;
	}

	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) " << std::endl;
	std::string Response = "";
	std::cin.ignore();
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}