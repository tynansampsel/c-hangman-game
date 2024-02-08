#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void is_all_letters_found(int* allCorrect,char* guessedLetters, char* correctLetters, int guessedLettersLength, int correctLettersLength)
{
	for (int i = 0; i < correctLettersLength; i++) {

		int hasLetter = 0;
		for (int j = 0; j < guessedLettersLength; j++) {
			
			if (*(correctLetters+i) == *(guessedLetters+j)) {
				hasLetter = 1;
			}
		}

		if (hasLetter == 0) {
			*allCorrect = 0;
		}
	}

}