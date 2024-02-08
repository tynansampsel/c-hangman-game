#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayCorrectLetters(char* guessedLetters, char* answer, int guessedLettersLength, int answerLength)
{
	//printf("ee%d", answerLength);

	for (int i = 0; i < answerLength; i++) {
		int hasLetter = 0;
		for (int j = 0; j < guessedLettersLength; j++) {
			if (*(answer+i) == *(guessedLetters+j)) {
				hasLetter = 1;
			}
		}
		if (hasLetter == 0) {
			printf("_ ");
		}
		else {
			printf("%c ", *(answer + i));
		}
	}

	printf("\n");
}