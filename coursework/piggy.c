#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "piggy.h"

char* pig(char* word) {
    char* pig_latin = (char*) malloc(strlen(word) + 3); //allocates word to memory plus 3 extra spaces for the 2 possible extra characters and the null terminator

    int first_vowel_idx = -1; //initially set to -1 to indicate no vowels found
    //printf("word length: %lu\n", strlen(word));

    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        //sets the first vowel index to the first vowel or y if it comes before any of the vowels and isnt the first character in the word
        if ((c == 'y') && (i > 0)) {
            first_vowel_idx = i;
            break;
        } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            first_vowel_idx = i;
            break;
        }
    }
    //printf("first vowel index: %d\n", first_vowel_idx);
    //printf("%s\n", pig_latin);
    //*pig_latin = "\0";
    //printf("%s\n", pig_latin);
    if (first_vowel_idx == -1) {
        strcpy(pig_latin, word); //copies the conents of word into pig_latin in memeory
        strcat(pig_latin, "ay"); //appends 'ay' to the end of the word
    } else if (first_vowel_idx == 0) {
        strcpy(pig_latin, word);
        strcat(pig_latin, "way");
    } else {
        // coppies the substring of word - starting from the first vowel index into pig_latin in memeory
        strncpy(pig_latin, word + first_vowel_idx, strlen(word) - first_vowel_idx);
        pig_latin[strlen(word) -2 ] = '\0';
        //printf("%s\n", pig_latin);
        // appends the substring of word - that comes before the first vowel, to the end of pig_latin 
        strncat(pig_latin, word, first_vowel_idx);
       // printf("%s\n", pig_latin);
        //appends 'ay' to the end of the word to complete translation
        strcat(pig_latin, "ay");
    }

    return pig_latin;
}