#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayGuessedLetters(char* guessedLetters, char* answer, char* correctLetters, int guessedLettersLength, int answerLength, int correctLettersLength)
{
	printf("      |       |  ");

	int notCorrectlyGuessedLetters = 0;
	//display guessed letters
	for (int i = 0; i < guessedLettersLength; i++) {
		int isCorrect = 0;

		for (int j = 0; j < correctLettersLength; j++) {
			if (guessedLetters[i] == correctLetters[j]) {
				isCorrect = 1;
			}

		}

		if (isCorrect == 0) {
			printf("%c ", guessedLetters[i]);

			notCorrectlyGuessedLetters++;
			//printf("%", notCorrectlyGuessedLetters);

			if (notCorrectlyGuessedLetters > 5) {
				//printf("      |       |  ");

			}
		}
	}
	printf("\n");
}