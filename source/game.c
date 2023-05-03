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
        printf("> %s\n", output_word);

        // читаем вводимые символы в неканоническом режиме
        int i = 0;
        while (1) {
            char c = get_input_char();
            if (c == '\n') {
                input_word[i] = '\0';
                break;
            }
            input_word[i++] = c;
        }

        // проверяем введенное слово на соответствие
        if (strcmp(input_word, output_word) == 0) {
            printf("%sCorrect!%s\n", GREEN, RESET);
            score++;
        } else {
            printf("%sIncorrect!%s\n", RED, RESET);
        }
    }

    // возвращаем старые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return score;
}