#pragma once
#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame()
{
	Reset();
}

bool TicTacToeGame::CheckCoordinate(int Coordx, int Coordy)
{
	switch (Coordx)
	{
	case 1:
		switch (Coordy)
		{
		case 1:
			if (Coords[0] == " ")
			{
				if (Player) { Coords[0] = "x"; }
				else { Coords[0] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			if (Coords[3] == " ")
			{
				if (Player) { Coords[3] = "x"; }
				else { Coords[3] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			if (Coords[6] == " ")
			{
				if (Player) { Coords[6] = "x"; }
				else { Coords[6] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		break;
	case 2:
		switch (Coordy)
		{
		case 1:
			if (Coords[1] == " ")
			{
				if (Player) { Coords[1] = "x"; }
				else { Coords[1] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			if (Coords[4] == " ")
			{
				if (Player) { Coords[4] = "x"; }
				else { Coords[4] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			if (Coords[7] == " ")
			{
				if (Player) { Coords[7] = "x"; }
				else { Coords[7] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		break;
	case 3:
		switch (Coordy)
		{
		case 1:
			if (Coords[2] == " ")
			{
				if (Player) { Coords[2] = "x"; }
				else { Coords[2] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			if (Coords[5] == " ")
			{
				if (Player) { Coords[5] = "x"; }
				else { Coords[5] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			if (Coords[8] == " ")
			{
				if (Player) { Coords[8] = "x"; }
				else { Coords[8] = "o"; }
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
	}
	return false;
}

std::string TicTacToeGame::GameWinner()
{
	std::string Winner = "";
	if (((Coords[0] == "x") && (Coords[1] == "x") && (Coords[2] == "x")) || 
		((Coords[3] == "x") && (Coords[4] == "x") && (Coords[5] == "x")) || 
		((Coords[6] == "x") && (Coords[7] == "x") && (Coords[8] == "x")) ||
		((Coords[0] == "x") && (Coords[3] == "x") && (Coords[6] == "x")) ||
		((Coords[1] == "x") && (Coords[4] == "x") && (Coords[7] == "x")) ||
		((Coords[2] == "x") && (Coords[5] == "x") && (Coords[8] == "x")) ||
		((Coords[0] == "x") && (Coords[4] == "x") && (Coords[8] == "x")) ||
		((Coords[2] == "x") && (Coords[4] == "x") && (Coords[6] == "x")))
	{
		Winner = "x";
		return Winner;
	}
	else if (((Coords[0] == "o") && (Coords[1] == "o") && (Coords[2] == "o")) ||
		((Coords[3] == "o") && (Coords[4] == "o") && (Coords[5] == "o")) ||
		((Coords[6] == "o") && (Coords[7] == "o") && (Coords[8] == "o")) ||
		((Coords[0] == "o") && (Coords[3] == "o") && (Coords[6] == "o")) ||
		((Coords[1] == "o") && (Coords[4] == "o") && (Coords[7] == "o")) ||
		((Coords[2] == "o") && (Coords[5] == "o") && (Coords[8] == "o")) ||
		((Coords[0] == "o") && (Coords[4] == "o") && (Coords[8] == "o")) ||
		((Coords[2] == "o") && (Coords[4] == "o") && (Coords[6] == "o")))
	{
		Winner = "o";
		return Winner;
	}
	else if (Moves == 9)
	{
		Winner = "tie";
		return Winner;
	}
	else
	{
		return Winner;
	}
	return Winner;
}

void TicTacToeGame::Reset()
{
	Player = true;
	for (int i = 0; i <= 8; i++)
	{
		Coords[i] = " ";
	}
}