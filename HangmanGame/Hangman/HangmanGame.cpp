#pragma once
#include "HangmanGame.h"
#include <ctime>
#include <cstdlib>

HangmanGame::HangmanGame()
{
	Reset();
}

void HangmanGame::Reset()
{
	IncorrectGuesses = 0;
	CorrectGuesses = 0;
	GuessedLetters.clear();
	bGameOver = false;
	bGameWinLoss = NULL;
	WinCheck = 0;

	srand(time(NULL));
	WordNumber = rand() % 1000 + 1; // range 1-1000 (number of words in array)
	WordNumber = WordNumber - 1;
	ChoosenWord = PossibleWords[WordNumber];
}