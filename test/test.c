#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctest.h>

#include <lexer.h>

CTEST(lextest, data_test1)
{
    char* exp_words[5] = {"apple", "yummy", "zoo", "rocket", "high"};
    int num_words;
    char** tmp_words;
    char* file_path = "../res/test/test1.txt";
    FILE* file = fopen(file_path, "r");
    tmp_words = word_lexer(file, &num_words);
    fclose(file);
    ASSERT_EQUAL(5, num_words);

    for (int i = 0; i < 5; i++) {
        ASSERT_STR(exp_words[i], tmp_words[i]);
    }
}