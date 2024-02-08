#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isAllLettersFound(int* allCorrect,char* guessedLetters, char* correctLetters, int guessedLettersLength, int correctLettersLength)
{
	for (int i = 0; i < correctLettersLength; i++) {

		int hasLetter = 0;
		//printf("<%c>\n", *(correctLetters + i));

		for (int j = 0; j < guessedLettersLength; j++) {
			

			if (*(correctLetters+i) == *(guessedLetters+j)) {
				//printf("correct:%c %c \n", *(correctLetters + i), *(guessedLetters + j));

				hasLetter = 1;
			}
		}

		if (hasLetter == 0) {
			//printf("problem\n");

			*allCorrect = 0;
		}
	}

}