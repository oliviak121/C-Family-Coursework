#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piggy.h"

int main() {
    char* words[] = {"happy", "duck", "glove", "evil", "eight", "yowler", "crystal"};
    int num_words = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        char* pig_latin = pig(word);
        printf("%s => %s\n", word, pig_latin);
        free(pig_latin);
    }

    return 0;
}
