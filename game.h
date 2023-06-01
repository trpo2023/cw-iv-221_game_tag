#ifndef GAME_H
#define GAME_H

#include <time.h>

#define SIZE 4

void printBoard(int board[SIZE][SIZE]);
void swap(int* a, int* b);
void shuffle(int board[SIZE][SIZE]);
int checkWin(int board[SIZE][SIZE]);
void move(int board[SIZE][SIZE], char command);
void displayTimeAndMoves(time_t startTime, int moves);

#endif
