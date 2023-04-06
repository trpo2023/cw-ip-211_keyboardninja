#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <game.h>
#include <lexer.h>
#include <menu.h>

#define TIME_FOR_GAME 30

int start_game(char** words, int num_words)
{
    char input_word[MAX_WORD_LENGTH], *output_word;
    int score = 0;
    // int all_score = 0;
    clear();
    PrintCountdown();
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < TIME_FOR_GAME) {
        output_word = words[rand() % num_words];
        printf("> %s\n> ", output_word);
        scanf("%s", input_word);
        if (strcmp(input_word, output_word) == 0) {
            printf("%sCorrect!%s\n", GREEN, RESET);
            score++;
            // all_score++;
        } else {
            printf("%sIncorrect!%s\n", RED, RESET);
            // all_score++;
        }
    }
    return score;
}