#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <lexer.h>

char **word_lexer(FILE *file, int *num_words)
{
    char **words = NULL;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) == 1)
    {
        *num_words += 1;
        words = (char **)realloc(words, (*num_words) * sizeof(char *));
        words[*num_words - 1] = (char *)malloc(strlen(word) + 1);
        strcpy(words[*num_words - 1], word);
    }
    return words;
}