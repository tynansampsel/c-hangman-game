#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_correct_letters_array(char* inP, char* outP, int* length)
{
    int l = 0;
    while (*inP) {
        int hasLetter = 0;
        int c = 0;


        while (*(outP + c)) {
            if (*inP == *(outP + c)) {
                hasLetter = 1;
            }
            c++;
        }

        if (hasLetter == 0) {
            *(outP + l) = *inP;

            l++;
        }

        inP++;
    }

    *length = (l);
    *(outP + l) = '\0';
}