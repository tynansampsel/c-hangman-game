#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getRandomWord(char* outP, int* length)
{
    char words[10][5] = {
        "snake",
        "tiger",
        "river",
        "ocean",
        "mango",

        "happy",
        "brave",
        "ghost",
        "mouse",
        "plant",
    };


    int chosenWord = 2;

    int ran = rand() % 10;
    chosenWord = ran;
    int l = 0;

    for (int i = 0; i < 5; i++) {
        //printf("[ %c ]\n", words[chosenWord][i]);

        *outP = words[chosenWord][i];

        outP++;
    }

    while (*outP) {
        
    }

    *length = 5;
    *outP = '\0';
}