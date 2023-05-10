#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctest.h>

#include <game.h>
#include <lexer.h>
#include <menu.h>

CTEST(lextest, data_test1)
{
    char* exp_words[5] = {"apple", "yummy", "zoo", "rocket", "high"};
    int num_words = 0;
    char** tmp_words;
    char* file_path = "../res/test/test1.txt";
    FILE* file = fopen(file_path, "r");
    tmp_words = word_lexer(file, &num_words);
    fclose(file);
    ASSERT_EQUAL(5, num_words);

    for (int i = 0; i < num_words; i++) {
        ASSERT_STR(exp_words[i], tmp_words[i]);
        free(tmp_words[i]);
    }
    free(tmp_words);
}

CTEST(lextest, data_test2)
{
    char* exp_words[0] = {};
    int num_words = 0;
    char** tmp_words;
    char* file_path = "../res/test/test2.txt";
    FILE* file = fopen(file_path, "r");
    tmp_words = word_lexer(file, &num_words);
    fclose(file);
    ASSERT_EQUAL(0, num_words);

    for (int i = 0; i < num_words; i++) {
        ASSERT_STR(exp_words[i], tmp_words[i]);
        free(tmp_words[i]);
    }
    free(tmp_words);
}

CTEST(difftest, dificulty_choice1)
{
    char *file_path, *leader_path;
    char str_level[10];
    char level = '1';
    SelectDifficulty(&level, str_level, &file_path, &leader_path);
    ASSERT_EQUAL(1, (int)(level - '0'));
    ASSERT_STR("EASY", str_level);
    ASSERT_STR("../res/levels/lvl_easy.txt", file_path);
    ASSERT_STR("../res/leaders/leaders_easy.txt", leader_path);
}

CTEST(difftest, dificulty_choice2)
{
    char *file_path, *leader_path;
    char str_level[10];
    char level = '2';
    SelectDifficulty(&level, str_level, &file_path, &leader_path);
    ASSERT_EQUAL(2, (int)(level - '0'));
    ASSERT_STR("MEDIUM", str_level);
    ASSERT_STR("../res/levels/lvl_medium.txt", file_path);
    ASSERT_STR("../res/leaders/leaders_medium.txt", leader_path);
}

CTEST(difftest, dificulty_choice3)
{
    char *file_path, *leader_path;
    char str_level[10];
    char level = '3';
    SelectDifficulty(&level, str_level, &file_path, &leader_path);
    ASSERT_EQUAL(3, (int)(level - '0'));
    ASSERT_STR("HARD", str_level);
    ASSERT_STR("../res/levels/lvl_hard.txt", file_path);
    ASSERT_STR("../res/leaders/leaders_hard.txt", leader_path);
}

CTEST(difftest, dificulty_choice4)
{
    char *file_path, *leader_path;
    char str_level[10];
    char level = 'a';
    SelectDifficulty(&level, str_level, &file_path, &leader_path);
    ASSERT_EQUAL(2, (int)(level - '0'));
    ASSERT_STR("MEDIUM", str_level);
    ASSERT_STR("../res/levels/lvl_medium.txt", file_path);
    ASSERT_STR("../res/leaders/leaders_medium.txt", leader_path);
}