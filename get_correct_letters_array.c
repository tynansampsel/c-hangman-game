#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getCorrectLettersArray(char* inP, char* outP, int* length)
{
    int l = 0;
    while (*inP) {
        //printf("> %c\n", *inP);

        int hasLetter = 0;
        int c = 0;


        while (*(outP + c)) {
            //printf("[ %c  %c ]", *inP, *(outP + c));

            if (*inP == *(outP + c)) {
                //printf("!");

                hasLetter = 1;
            }

            c++;
        }
        //printf("\n");

        if (hasLetter == 0) {
            *(outP + l) = *inP;

            l++;
        }

        //*pointer = toupper(*pointer);




        inP++;
    }

    *length = (l);
    *(outP + l) = '\0';
}