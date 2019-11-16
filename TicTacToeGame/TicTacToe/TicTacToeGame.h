#pragma once
#include <string>

class TicTacToeGame 
{
public:
	TicTacToeGame();

	std::string Coords[9] = { " " };

	bool CheckCoordinate(int, int);

	bool Player;

	int Moves = 0;

	std::string GameWinner();

	void Reset();
};