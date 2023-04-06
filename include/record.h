#pragma once

#define MAX_NUM_RECORDS 10

struct Record
{
    char name[20];
    int score;
};

void AddLeader(char *name, int score);

int CompareLeaders(int i, int j);

void InsertLeader(char *name, int score);

void LoadLeaderboard();
