#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lexer.h>
#include <record.h>

// #define TIME_FOR_WORD 1

int main()
{
    srand(time(NULL));
    FILE *file;
    Record records[MAX_NUM_RECORDS];
    int num_records = 0;
    char **words = NULL;
    char name[50];
    int num_words = 0, level;
    char *file_path, *leader_path;

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
        file_path = "../res/levels/lvl_easy.txt";
        leader_path = "../res/leaders/leaders_easy.txt";
        break;
    case 2:
        file_path = "../res/levels/lvl_medium.txt";
        leader_path = "../res/leaders/leaders_medium.txt";
        break;
    case 3:
        file_path = "../res/levels/lvl_hard.txt";
        leader_path = "../res/leaders/leaders_hard.txt";
        break;
    default:
        printf("wrong difficulty level\n");
        return 1;
    }

    file = fopen(file_path, "r");
    LoadLeaders(records, &num_records, leader_path);

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    words = word_lexer(file, &num_words);

    fclose(file);

    PrintLeaderboard(records, num_records);

    printf("Type your name (max 7 symbols): ");
    scanf("%s", name);
    name[MAX_NAME_LENGTH - 1] = '\0';

    AddLeader(records, &num_records, name, rand() % 100);
    SaveLeaders(records, num_records, leader_path);
    PrintLeaderboard(records, num_records);

    for (int i = 0; i < num_words; i++)
    {
        free(words[i]); // освободить память, выделенную для каждого слова
    }
    free(words);

    return 0;
}