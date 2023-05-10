#pragma once

#ifdef WINDOWS
#define clear() system("cls")
#else
#define clear() printf("\033[H\033[J")
#endif

#define RESET "\x1B[0m"
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"

void PrintMenu();
void PrintDifficulty();
void PrintCountdown();
int SelectDifficulty(
        char* level, char str_level[], char** file_path, char** leader_path);