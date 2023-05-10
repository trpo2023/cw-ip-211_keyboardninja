#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include <game.h>
#include <lexer.h>
#include <menu.h>

#define TIME_FOR_GAME 30

char get_input_char()
{
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
}
void update_window(int time_left, int score)
{
    printf("\033]0;Time left: %d seconds | Score: %d\007", time_left, score);
}

int start_game(char** words, int num_words)
{
    char input_word[MAX_WORD_LENGTH], *output_word;
    int score = 0;

    // сохраняем текущие настройки терминала
    struct termios oldattr, newattr;
    tcgetattr(STDIN_FILENO, &oldattr);

    // копируем их для изменения
    newattr = oldattr;

    // выключаем канонический режим ввода и отображение вводимых символов
    newattr.c_lflag &= ~(ICANON | ECHO);

    // устанавливаем новые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    // выводим обратный отсчет перед началом игры
    clear();
    PrintCountdown();

    // начинаем игру
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < TIME_FOR_GAME) {
        output_word = words[rand() % num_words];

        for (int j = 0; j < MAX_WORD_LENGTH; j++)
            input_word[j] = '\0';
        // читаем вводимые символы в неканоническом режиме
        int i = 0;
        while (1) {
            puts("");
            printf("Type /quit to return to main menu.\n\nOutput "
                   "word:\n> ");
            puts(output_word);
            printf("\n> ");
            puts(input_word);
            char c = get_input_char();
            if (c == '\n') {
                input_word[i] = '\0';
                clear();
                break;
            }
            if (c == newattr.c_cc[VERASE]) {
                if (i == 0) {
                    input_word[0] = '\0';
                } else {
                    i--;
                    input_word[i] = '\0';
                }
                clear();
                continue;
            }
            input_word[i++] = c;
            clear();
        }

        // проверяем введенное слово на соответствие
        if (strcmp(input_word, output_word) == 0) {
            printf("%sCorrect!%s", GREEN, RESET);
            score++;
        } else if (strcmp(input_word, "/quit") == 0) {
            score = -1;
            break;
        } else {
            printf("%sIncorrect!%s", RED, RESET);
        }
        int time_left = TIME_FOR_GAME - (time(NULL) - start_time);
        update_window(time_left, score);
    }

    // возвращаем старые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return score;
}