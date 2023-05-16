#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
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
    int num_words;
    char *file_path, *leader_path;
    char str_level[10];
    char option, level = '2';

    SelectDifficulty(
            &level,
            str_level,
            &file_path,
            &leader_path); // Стандартный уровень сложности
    LoadLeaders(records, &num_records, leader_path);

    // сохраняем текущие настройки терминала
    struct termios oldattr, newattr;
    tcgetattr(STDIN_FILENO, &oldattr);

    // копируем их для изменения
    newattr = oldattr;

    // выключаем канонический режим ввода и отображение вводимых символов
    newattr.c_lflag &= ~(ICANON | ECHO);

    // устанавливаем новые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    printf("\033]0;Keyboard Ninja\007");

    do {
        PrintMenu();
        tcflush(STDIN_FILENO, TCIFLUSH);
        option = get_input_char();
        printf("%c", option);

        switch (option) {
        case '1':
            num_words = 0;
            file = fopen(file_path, "r");
            if (file == NULL) {
                printf("Could not open file\n");
                return 1;
            }
            words = NULL;
            words = word_lexer(file, &num_words);
            fclose(file);
            char restart;
            do {
                int score = start_game(words, num_words);
                if (score != -1) {
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
                    printf("\nYour score: %d !\n", score);
                    printf("Enter your name: ");
                    scanf("%s", name);
                    name[MAX_NAME_LENGTH - 1] = '\0';
                    getchar();
                    AddLeader(records, &num_records, name, score);
                    puts("Restart? (y/n)");
                    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
                    do {
                        restart = get_input_char();
                    } while (restart != 'n' && restart != 'y');
                } else
                    restart = 'n';
            } while (restart == 'y');

            SaveLeaders(records, num_records, leader_path);
            for (int i = 0; i < num_words; i++)
                free(words[i]); // освободить память, выделенную для каждого
                                // слова
            free(words);
            break;
        case '2':
            PrintDifficulty();
            tcflush(STDIN_FILENO, TCIFLUSH);
            level = get_input_char();
            if (!SelectDifficulty(
                        &level, str_level, &file_path, &leader_path)) {
                printf("Chosen %s level of difficulty!", str_level);
                fflush(stdout);
                usleep(999999);
            } else {
                printf("Wrong difficulty level!\n");
                fflush(stdout);
                usleep(666666);
                printf("Set default difficulty (medium)..\n\n");
                fflush(stdout);
                usleep(666666);
            }
            LoadLeaders(records, &num_records, leader_path);
            break;
        case '3':
            clear();
            printf("Leaderboard of %s level players:\n", str_level);
            PrintLeaderboard(records, num_records);
            printf("Press any key to return..");
            getchar();
            break;
        case '4':
            // возвращаем старые настройки терминала
            tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
            clear();
            exit(1);
            break;
        default:
            PrintMenu();
        }
    } while (option != 4);
    // возвращаем старые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return 0;
}