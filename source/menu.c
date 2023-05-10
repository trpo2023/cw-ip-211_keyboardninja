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
    printf("Blind typing, type /quit to return to main menu.\n\n");
    fflush(stdout);
    usleep(123333);
}