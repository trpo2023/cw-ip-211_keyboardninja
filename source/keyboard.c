#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TIME_FOR_WORD 1
#define MAX_WORD_LENGTH 50

int main()
{
    srand(time(NULL));
    FILE *file;
    char **words = NULL;
    int num_words = 0, level;
    char word[MAX_WORD_LENGTH];
    long int begin = time(NULL);
    long int end = begin + TIME_FOR_WORD;

    printf("Choose difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("> ");
    scanf("%d", &level);

    switch (level)
    {
    case 1:
        file = fopen("../res/lvl_easy.txt", "r");
        break;
    case 2:
        file = fopen("../res/lvl_medium.txt", "r");
        break;
    case 3:
        file = fopen("../res/lvl_hard.txt", "r");
        break;
    default:
        printf("wrong difficulty level\n");
        return 1;
    }

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    while (fscanf(file, "%s", word) == 1)
    {
        num_words++;
        words = (char **)realloc(words, num_words * sizeof(char *));
        words[num_words - 1] = (char *)malloc(strlen(word) + 1);
        strcpy(words[num_words - 1], word);
    }

    fclose(file);

    // while (begin < end)
    // {
    //     begin = time(NULL);
    //     printf("a\n");
    // }

    for (int i = 0; i < num_words; i++)
    {
        free(words[i]); // освободить память, выделенную для каждого слова
    }
    free(words);

    return 0;
}