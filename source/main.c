#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <game.h>
#include <lexer.h>
#include <menu.h>
#include <record.h>

// #define TIME_FOR_WORD 1

int main()
{
    srand(time(NULL));
    FILE* file;
    Record records[MAX_NUM_RECORDS];
    int num_records = 0;
    char** words = NULL;
    char name[30];
    int num_words = 0;
    char *file_path, *leader_path;
    char str_level[10];
    char option, level = '2';

    file_path = "../res/levels/lvl_medium.txt"; // default difficulty level
    leader_path = "../res/leaders/leaders_medium.txt";
    LoadLeaders(records, &num_records, leader_path);

    do {
        PrintMenu();
        scanf("%c", &option);
        switch (option) {
        case '1':
            file = fopen(file_path, "r");
            if (file == NULL) {
                printf("Could not open file\n");
                return 1;
            }
            words = word_lexer(file, &num_words);
            fclose(file);
            char restart;
            do {
                int score = start_game(words, num_words);
                printf("Your score: %d !\n", score);
                printf("Enter your name: ");
                scanf("%s", name);
                name[MAX_NAME_LENGTH - 1] = '\0';
                AddLeader(records, &num_records, name, score);
                printf("Restart? (y/n)");
                getchar();
                restart = getchar();
            } while (restart != 'n');

            SaveLeaders(records, num_records, leader_path);
            for (int i = 0; i < num_words; i++)
                free(words[i]); // освободить память, выделенную для каждого
                                // слова
            free(words);
            break;
        case '2':
            PrintDifficulty();
            getchar();
            scanf("%c", &level);
            switch (level) {
            case '1':
                file_path = "../res/levels/lvl_easy.txt";
                leader_path = "../res/leaders/leaders_easy.txt";
                strcpy(str_level, "EASY");
                break;
            case '2':
                file_path = "../res/levels/lvl_medium.txt";
                leader_path = "../res/leaders/leaders_medium.txt";
                strcpy(str_level, "MEDIUM");
                break;
            case '3':
                file_path = "../res/levels/lvl_hard.txt";
                leader_path = "../res/leaders/leaders_hard.txt";
                strcpy(str_level, "HARD");
                break;
            default:
                printf("Wrong difficulty level!\n");
                fflush(stdout);
                usleep(666666);
                printf("Set default difficulty (medium)..\n\n");
                fflush(stdout);
                usleep(666666);
                file_path = "../res/levels/lvl_medium.txt";
                leader_path = "../res/leaders/leaders_medium.txt";
                strcpy(str_level, "MEDIUM");
                level = 2;
                break;
            }
            printf("Chosen %s level of difficulty!", str_level);
            fflush(stdout);
            usleep(999999);
            LoadLeaders(records, &num_records, leader_path);
            break;
        case '3':
            clear();
            printf("Leaderboard of %s level players:\n", str_level);
            PrintLeaderboard(records, num_records);
            printf("Press any key to return..");
            getchar();
            getchar();
            break;
        case '4':
            exit(1);
            break;
        default:
            PrintMenu();
        }
    } while (option != 4);

    return 0;
}