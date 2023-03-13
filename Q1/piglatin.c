#include <string.h>
#include <ctype.h>
#include "pig.h" 

char* processSentence(char*);

int main() {
    while (1) {
        char input[1000];

        printf("Enter a sentence: ");
        fgets(input, sizeof(input), stdin); //gets input from user

        // Removes the newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit loop if input is empty
        if (strlen(input) == 0) {
            break;
        }

        char* result = processSentence(input);
        printf("In Pig Latin: %s\n\n", result);
        free(result); // frees the memeory where the word is stored after program is run
    }

    return 0;
}

char* processSentence(char* sentence) {
    char* copy = strdup(sentence); //copy so dont mess with original

    //split into individual words
    char* individual_word;
    char* processed_words[100]; 
    int num_words = 0;
    individual_word = strtok(copy, " ");

    while (individual_word != NULL) {
        processed_words[num_words++] = pig(individual_word);
        individual_word = strtok(NULL, " ");
        //free(individual_word);
    }

    //combine back into one sentence
    char* result_sentence = malloc(strlen(sentence) + 1);
    result_sentence[0] = '\0'; 
    for(int i = 0; i < num_words; i++) {
        strcat(result_sentence, processed_words[i]);
        if (i < num_words - 1) {
            strcat(result_sentence, " "); //adding space between words
        }
    }
    free(copy);
    return result_sentence;
}
