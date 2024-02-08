#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//#include <is_all_letters_found.c>
//#include <get_random_word.c>
//#include <get_correct_letters_array.c>
//#include <display_hang_man.c>
//#include <display_guessed_letters.c>
//#include <display_correct_letters.c>
//#include <add_input_into_guessed_array.c>

void is_all_letters_found(int* allCorrect,char* guessedLetters, char* correctLetters, int guessedLettersLength, int correctLettersLength);
void get_random_word(char* outP, int* length);
void get_correct_letters_array(char* inP, char* outP, int* length);
void display_hang_man(int failures);
void display_guessed_letters(char* guessedLetters, char* answer, char* correctLetters, int guessedLettersLength, int answerLength, int correctLettersLength);
void display_correct_letters(char* guessedLetters, char* answer, int guessedLettersLength, int answerLength);
void add_input_into_guessed_array(int* correctGuess, int* hasBeenGuessedAlready, char* guessedLetter, char* guessedLetters, char* correctLetters, int* guessedLettersLength, int* correctLettersLength);
int game();

int main() {
	time_t currentTime;
	time(&currentTime);
	srand(currentTime);

	game();
	return 0;
}


int game() {
	int victory = 0;
	int gameOver = 0;
	char answer[10];
	int answerLength = 0;
	int failures = 0;

	int finalDisplay = 0;

	get_random_word(answer, &answerLength);

	//printf("[ %s ] %d answer\n", answer, answerLength);

	char guessedLetters[27];
	int guessedLettersLength = 0;

	char correctlyGuessedLetters[27];
	int correctlyGuessedLettersLength = 0;

	//this is an array of characters so i can get the /n and /0. otherwise they will be read in by the next fgets.
	char guessedLetter;
	char gotLetter[3];

	//build the correct letter array
	char correctLetters[27];
	int correctLettersLength = 0;

	get_correct_letters_array(answer, correctLetters, &correctLettersLength);

	//printf("[ %s ] %d correctLetters\n", correctLetters, correctLettersLength);


	do {
		// ----- [ DISPLAY HANGMAN ]
		printf("/////////////////////////////////////////\n");
		printf("      _________  ");

		//display correct letters
		printf("  ");
		printf("  \n");
		printf("      |       |  ");

		//display guessed letters
		display_correct_letters(guessedLetters, answer, guessedLettersLength, answerLength);
		printf("      |       |  \n");
		display_guessed_letters(guessedLetters, answer, correctLetters, guessedLettersLength, answerLength, correctLettersLength);
		display_hang_man(failures);
		// -


		// ----- [ GET INPUT ]
		
		if (finalDisplay == 0) { 
			printf("Guess a letter: ");
			fgets(gotLetter, 3, stdin);

			guessedLetter = tolower(gotLetter[0]);
		}
		// -


		// ----- [ ADD INPUT INTO GUESSED ARRAY ]
		int correctGuess = 0;
		int hasBeenGuessedAlready = 0;
		int allCorrect = 1;

		if (finalDisplay == 0) {
			add_input_into_guessed_array(&correctGuess, &hasBeenGuessedAlready, &guessedLetter, guessedLetters, correctLetters, &guessedLettersLength, &correctLettersLength);

			if (correctGuess == 1) {
				printf("%c is correct!\n", guessedLetter);
			}
			else if (hasBeenGuessedAlready == 0) {
				failures++;
				printf("%c is incorrect.\n", guessedLetter);
			}
			else {
				printf("%c already guessed!\n", guessedLetter);
			}

			is_all_letters_found(&allCorrect, guessedLetters, correctLetters, guessedLettersLength, correctLettersLength);
		}


		printf("\n");



		// ----- [ END GAME IF VICTORIOUS ]
		if (finalDisplay == 1) { 
			finalDisplay = 2;
		}

		if (allCorrect == 1 && finalDisplay == 0) {
			gameOver = 1;
			finalDisplay = 1;
			victory = 1;
		}
		if (failures == 6 && finalDisplay == 0) {
			gameOver = 1;
			finalDisplay = 1;
		}
		// ----- []

	} while (gameOver == 0 || finalDisplay == 1);


	if (victory == 1) {
		printf("\nWINNER!\n\n");
	}
	else {
		printf("LOSER!\n\n");
		printf("the word was %s. \n\n", answer);
	}

	printf("\n\n\n game over!");

	return 0;
}