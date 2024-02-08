#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addInputIntoGuessedArray(int* correctGuess, int* hasBeenGuessedAlready, char* guessedLetter, char* guessedLetters, char* correctLetters, int* guessedLettersLength, int* correctLettersLength)
{
	
	//printf("%c guessed\n", *guessedLetter);
	//printf("%d num\n", *guessedLettersLength);
	if (*guessedLettersLength < 1) {
		//printf("currentUsedLength is 0 so adding\n");
		//printf("f\n");

		//add letter to array
		int e = *guessedLettersLength;
		//printf("%c A\n", *(guessedLetters + (*guessedLettersLength)));

		*(guessedLetters + (*guessedLettersLength)) = *guessedLetter;
		*(guessedLetters + (*guessedLettersLength+1)) = '\0';

		//printf("%c B\n", *(guessedLetters + (*guessedLettersLength)));

		//printf("added: %c\n", guessedLetter[0]);
		*guessedLettersLength = *guessedLettersLength+1;
		

		//check if this is a correct letter
		for (int j = 0; j < *correctLettersLength; j++) {
			if (*(correctLetters+j) == *guessedLetter) {
				*correctGuess = 1;
			}
		}
		//printf("[ %s ]\n", guessedLetters);


	}
	else {
		//printf("s\n");

		//check every letter in the guessed array. if this letter is not already in this array, add it.
		for (int i = 0; i < (*guessedLettersLength); i++) {
			//printf("[  %d  ] [ %c ] \n", i, guessedLetters[i]);

			if (*(guessedLetters+i) == *guessedLetter) {
				//printf("%c already guessed!\n", *guessedLetter);
				*hasBeenGuessedAlready = 1;
			}
		}

		if (*hasBeenGuessedAlready == 0) {
			*(guessedLetters + *guessedLettersLength) = *guessedLetter;
			*(guessedLetters + (*guessedLettersLength + 1)) = '\0';
			//printf("added: %c\n", guessedLetter[0]);

			*guessedLettersLength = *guessedLettersLength +1;

			for (int j = 0; j < *correctLettersLength; j++) {
				if (*(correctLetters+j) == *guessedLetter) {
					*correctGuess = 1;
				}
			}
		}


		//printf("[ %s ]\n", guessedLetters);
	}
	printf("\n");
	//printf("%d num2\n", *guessedLettersLength);

}