#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "piggy.h" 

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

        char* return_word = pig(input);
        printf("In Pig Latin: %s\n", return_word);
        free(return_word); // frees the memeory where the word is stored after program is run
    }

    return 0;
}
