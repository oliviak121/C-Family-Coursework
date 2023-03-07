#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* pig(char* word);

int main() {
    while (1) {
        char input[50];

        printf("Enter a word: ");
        fgets(input, sizeof(input), stdin); //gets input from user

        // Removes the newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit loop if input is empty
        if (strlen(input) == 0) {
            break;
        }

        char* pig_latin = pig(input);
        printf("In Pig Latin: %s\n", pig_latin);
        free(pig_latin); // frees the memeory where the word is stored after program is run
    }

    return 0;
}

char* pig(char* word) {
    char* pig_latin = (char*) malloc(strlen(word) + 3); //allocates word to memory plus 3 extra spaces for the 2 possible extra characters and the null terminator

    int first_vowel_idx = -1; //initially set to -1 to indicate no vowels found
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

    if (first_vowel_idx == -1) {
        strcpy(pig_latin, word);
        strcat(pig_latin, "ay");
    } else if (first_vowel_idx == 0) {
        strcpy(pig_latin, word);
        strcat(pig_latin, "way");
    } else {
        strncpy(pig_latin, word + first_vowel_idx, strlen(word) - first_vowel_idx);
        strncat(pig_latin, word, first_vowel_idx);
        strcat(pig_latin, "ay");
    }

    return pig_latin;
}