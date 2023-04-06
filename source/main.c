#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lexer.h>

#define TIME_FOR_GAME 30

int main()
{
    srand(time(NULL));
    FILE *file;
    char **words = NULL;
    int num_words = 0, level, score = 0, all_score = 0;
    char *file_path;
    time_t start_time = time(NULL);
    char input_word[MAX_WORD_LENGTH], *output_word;

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

    score = 0;
    all_score = 0;
    while (time(NULL) - start_time < TIME_FOR_GAME)
    {
        output_word = words[rand() % num_words];
        printf("> %s\n> ", output_word);
        scanf("%s", input_word);
        if (strcmp(input_word, output_word) == 0)
        {
            printf("Correct!\n");
            score++;
            all_score++;
        }
        else
        {
            printf("Incorrect!\n");
            all_score++;
        }
    }
    printf("You scored %d/%d. Congratulations!\n", score, all_score);

    for (int i = 0; i < num_words; i++)
    {
        free(words[i]); // освободить память, выделенную для каждого слова
    }
    free(words);

    return 0;
}