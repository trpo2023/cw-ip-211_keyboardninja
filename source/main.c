#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lexer.h>

// #define TIME_FOR_WORD 1

int main()
{
    srand(time(NULL));
    FILE *file;
    char **words = NULL;
    int num_words = 0, level;
    char *file_path;
    // long int begin = time(NULL);
    // long int end = begin + TIME_FOR_WORD;

    printf("Choose difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("> ");
    scanf("%d", &level);

    switch (level)
    {
    case 1:
        file_path = "../res/lvl_easy.txt";
        break;
    case 2:
        file_path = "../res/lvl_medium.txt";
        break;
    case 3:
        file_path = "../res/lvl_hard.txt";
        break;
    default:
        printf("wrong difficulty level\n");
        return 1;
    }

    file = fopen(file_path, "r");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    words = word_lexer(file, &num_words);

    fclose(file);

    for (int i = 0; i < num_words; i++)
    {
        free(words[i]); // освободить память, выделенную для каждого слова
    }
    free(words);

    return 0;
}