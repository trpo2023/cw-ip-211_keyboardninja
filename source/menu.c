#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <menu.h>

void PrintMenu()
{
    clear();
    printf("Choose your option:\n");
    printf("1. Start game\n");
    printf("2. Difficulty\n");
    printf("3. Leaderboard\n");
    printf("4. Quit\n");
    printf("> ");
}

void PrintDifficulty()
{
    clear();
    printf("Choose difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("> ");
}

void PrintCountdown()
{
    printf("3");
    fflush(stdout);
    usleep(123333);
    printf(".");
    fflush(stdout);
    usleep(123333);
    printf(".\n");
    fflush(stdout);
    usleep(123333);
    printf("2");
    fflush(stdout);
    usleep(123333);
    printf(".");
    fflush(stdout);
    usleep(123333);
    printf(".\n");
    fflush(stdout);
    usleep(123333);
    printf("1");
    fflush(stdout);
    usleep(123333);
    printf(".");
    fflush(stdout);
    usleep(123333);
    printf(".\n");
    fflush(stdout);
    usleep(123333);
    printf("GO!\n\n");
    fflush(stdout);
    usleep(123333);
    clear();
}

void SelectDifficulty(
        char* level, char str_level[], char** file_path, char** leader_path)
{
    switch (*level) {
    case '1':
        *file_path = "../res/levels/lvl_easy.txt";
        *leader_path = "../res/leaders/leaders_easy.txt";
        strcpy(str_level, "EASY");
        break;
    case '2':
        *file_path = "../res/levels/lvl_medium.txt";
        *leader_path = "../res/leaders/leaders_medium.txt";
        strcpy(str_level, "MEDIUM");
        break;
    case '3':
        *file_path = "../res/levels/lvl_hard.txt";
        *leader_path = "../res/leaders/leaders_hard.txt";
        strcpy(str_level, "HARD");
        break;
    default:
        printf("Wrong difficulty level!\n");
        fflush(stdout);
        usleep(666666);
        printf("Set default difficulty (medium)..\n\n");
        fflush(stdout);
        usleep(666666);
        *file_path = "../res/levels/lvl_medium.txt";
        *leader_path = "../res/leaders/leaders_medium.txt";
        strcpy(str_level, "MEDIUM");
        *level = '2';
        break;
    }
    printf("Chosen %s level of difficulty!", str_level);
    fflush(stdout);
    usleep(999999);
}