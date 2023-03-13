#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pig.h"

int main() {
    printf("happy => %s\n", pig("happy"));
    printf("duck => %s\n", pig("duck"));
    printf("glove => %s\n", pig("glove"));
    printf("evil => %s\n", pig("evil"));
    printf("eight => %s\n", pig("eight"));
    printf("yowler => %s\n", pig("yowler"));
    printf("crystal => %s\n", pig("crystal"));
    
    return 0;
}

