#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <record.h>

struct Record records[MAX_NUM_RECORDS + 1];
int num_records = 0;

void AddLeader(char *name, int score)
{
    strcpy(records[num_records].name, name);
    records[num_records].score = score;
    num_records++;
}

int CompareLeaders(int i, int j)
{
    if (records[i].score < records[j].score)
        return -1;
    if (records[i].score > records[j].score)
        return +1;

    if (strcmp(records[i].name, records[j].name) < 0)
        return -1;
    if (strcmp(records[i].name, records[j].name) > 0)
        return +1;

    return 0;
}

void InsertLeader(char *name, int score)
{
    strcpy(records[num_records].name, name);
    records[num_records].score = score;
    int i = num_records;

    while (i > 0)
    {
        if (CompareLeaders(i - 1, i) < 0)
        {
            struct Record tmp = records[i];
            records[i] = records[i - 1];
            records[i - 1] = tmp;
        }
        i--;
    }

    if (num_records < MAX_NUM_RECORDS)
        num_records++;
}

void PrintLeaderboard()
{
    char string_header[] = "|  No  |     Name     |     Score     |";
    int i;
    puts(string_header);
    for (i = 0; i < num_records; i++)
        printf("|  %2d  |   %8s   |     %5d     |\n", i + 1, records[i].name, records[i].score);
}