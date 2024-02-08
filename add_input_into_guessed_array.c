#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_input_into_guessed_array(int* correctGuess, int* hasBeenGuessedAlready, char* guessedLetter, char* guessedLetters, char* correctLetters, int* guessedLettersLength, int* correctLettersLength)
{
	if (*guessedLettersLength < 1) {
		//add letter to array
		int e = *guessedLettersLength;
		*(guessedLetters + (*guessedLettersLength)) = *guessedLetter;
		*(guessedLetters + (*guessedLettersLength+1)) = '\0';

		*guessedLettersLength = *guessedLettersLength+1;
		
		for (int j = 0; j < *correctLettersLength; j++) {
			if (*(correctLetters+j) == *guessedLetter) {
				*correctGuess = 1;
			}
		}
	}
	else {
		//check every letter in the guessed array. if this letter is not already in this array, add it.
		for (int i = 0; i < (*guessedLettersLength); i++) {
			if (*(guessedLetters+i) == *guessedLetter) {
				*hasBeenGuessedAlready = 1;
			}
		}

		if (*hasBeenGuessedAlready == 0) {
			*(guessedLetters + *guessedLettersLength) = *guessedLetter;
			*(guessedLetters + (*guessedLettersLength + 1)) = '\0';

			*guessedLettersLength = *guessedLettersLength +1;

			for (int j = 0; j < *correctLettersLength; j++) {
				if (*(correctLetters+j) == *guessedLetter) {
					*correctGuess = 1;
				}
			}
		}
	}
	printf("\n");
}