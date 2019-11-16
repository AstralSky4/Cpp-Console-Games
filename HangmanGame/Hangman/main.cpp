#include <iostream>
#include <string>
#include "HangmanGame.h"
#include <conio.h>


void PrintIntro();
void PrintBoard();
void PlayGame();
bool bPlayAgain();
char GetValidGuess();
void CheckGuess(char Guess);
void CheckGameOver();
void PrintGameSummary();

HangmanGame HGGame;

int main() 
{
	do
	{
		HGGame.Reset();
		PrintIntro();
		PrintBoard();
		PlayGame();
		PrintGameSummary();
	} while (bPlayAgain());

	return 0;
}

void PrintIntro()
{
	system("cls");
	std::cout << "Welcome to Hangman!" << std::endl;
	std::cout << "Enter in letters to guess the word!" << std::endl;
	do
	{
		std::cout << '\n' << "Press enter to start.";
	} while (std::cin.get() != '\n');

	return;
}

void PrintBoard()
{
	system("cls");

	// Hangman state
	switch (HGGame.IncorrectGuesses)
	{
	case 0:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 1:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 2:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|       |" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 3:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|      \\|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 4:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|      \\|/" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 5:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|      \\|/" << std::endl;
		std::cout << "|       |" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 6:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|      \\|/" << std::endl;
		std::cout << "|       |" << std::endl;
		std::cout << "|      /" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	case 7:
		std::cout << " _______" << std::endl;
		std::cout << "|/      |" << std::endl;
		std::cout << "|      (_)" << std::endl;
		std::cout << "|      \\|/" << std::endl;
		std::cout << "|       |" << std::endl;
		std::cout << "|      / \\ " << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|___" << std::endl;
		break;
	}

	// Word display
	
	int WordLength = HGGame.ChoosenWord.length();
	int Var = 0;
	int NumberOfGuessedLetters = HGGame.GuessedLetters.length();
	int LetterIteration = 0;
	HGGame.WinCheck = 0;

	std::cout << "\nWord to be guessed:" << std::endl << std::endl;

	for (int i = 0; i < WordLength; i++)
	{
		Var = 0;
		LetterIteration = i;

		for (int j = 0; j < NumberOfGuessedLetters; j++)
		{
			if (HGGame.ChoosenWord[LetterIteration] == HGGame.GuessedLetters[j])
			{
				std::cout << HGGame.ChoosenWord[LetterIteration] << " ";
				Var = 1;
			}
			else if (Var == 0 && j + 1 == NumberOfGuessedLetters)
			{
				std::cout << "_ ";
				Var = 1;
				HGGame.WinCheck = 1;
			}
		}
		
		if (Var == 0)
		{
			std::cout << "_ ";
			HGGame.WinCheck = 1;
		}
	}
	
	// Guessed letters
	
	std::cout << "\n\nLetters guessed:" << std::endl << std::endl;
	
	std::cout << HGGame.GuessedLetters << std::endl << std::endl;


	return;
}

void PlayGame()
{
	do
	{
		CheckGuess(GetValidGuess());
		PrintBoard();
		CheckGameOver();
	} while (HGGame.bGameOver == false);

	return;
}

 bool bPlayAgain()
{
	std::string Answer;
	bool bPlay;
	int CheckAnswer = 0;

	do
	{
		std::cout << "Would you like to play again? (y/n)" << std::endl;
		std::cin >> Answer;

		if (Answer == "y" || Answer == "Y")
		{
			bPlay = true;
			CheckAnswer = 0;
		}
		else if (Answer == "n" || Answer == "N")
		{
			bPlay = false;
			CheckAnswer = 0;
		}
		else
		{
			CheckAnswer = 1;
		}
	} while (CheckAnswer == 1);

	return bPlay;
}

char GetValidGuess()
 {
	 char Guess;

	 std::cout << "Enter a single letter:" << std::endl;
	 std::cin >> Guess;

	 int GuessedLetters = HGGame.GuessedLetters.length();
	 int InString = 0;

	 for (int i = 0; i < GuessedLetters; i++)
	 {
		 if (Guess == HGGame.GuessedLetters[i])
		 {
			 InString++;
		 }
	 }

	 if (InString == 0)
	 {
		 int Pos = HGGame.GuessedLetters.length();
		 HGGame.GuessedLetters.insert(Pos, 1, Guess);
		 return Guess;
	 }
	 else
	 {
		 std::cout << "You've already guessed " << Guess << "." << std::endl;
		 GetValidGuess();
	 }

	 return Guess;
 }

void CheckGuess(char Guess)
{
	int ChoosenWordLength = HGGame.ChoosenWord.length();
	int InWord = 0;

	for (int i = 0; i < ChoosenWordLength; i++)
	{
		if (Guess == HGGame.ChoosenWord[i])
		{
			InWord++;
		}
	}

	if (InWord == 0)
	{
		HGGame.IncorrectGuesses++;
	}
	else
	{
		HGGame.CorrectGuesses++;
	}

	return;
}

void CheckGameOver()
{
	if (HGGame.WinCheck == 0)
	{
		HGGame.bGameOver = true;
		HGGame.bGameWinLoss = true;
	}

	if (HGGame.IncorrectGuesses == 7)
	{
		HGGame.bGameOver = true;
	}
}

void PrintGameSummary()
{
	system("cls");
	if (HGGame.bGameWinLoss == true)
	{
		std::cout << "You won! The word was: " << HGGame.ChoosenWord << std::endl;
	}
	else
	{
		std::cout << "You lost! The word was: " << HGGame.ChoosenWord << std::endl;
	}
}