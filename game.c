#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void printBoard(int board[SIZE][SIZE]) {
    printf("┌─────┬─────┬─────┬─────┐\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("│%4c ", ' ');
            } else {
                printf("│%4d ", board[i][j]);
            }
        }
        printf("│\n");
        if (i != SIZE - 1) {
            printf("├─────┼─────┼─────┼─────┤\n");
        }
    }
    printf("└─────┴─────┴─────┴─────┘\n\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void shuffle(int board[SIZE][SIZE]) {
    srand(time(0));
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&board[0][i], &board[0][j]);
    }
}

int checkWin(int board[SIZE][SIZE]) {
    int count = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != count) {
                return 0;
            }
            count++;
            if (count == SIZE * SIZE) {
                count = 0;
            }
        }
    }
    return 1;
}

void move(int board[SIZE][SIZE], char command) {
    int x, y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                x = i, y = j;
            }
        }
    }

    if (command == 'w' && x < SIZE - 1) {
        swap(&board[x][y], &board[x + 1][y]);
    }
    if (command == 's' && x > 0) {
        swap(&board[x][y], &board[x - 1][y]);
    }
    if (command == 'a' && y < SIZE - 1) {
        swap(&board[x][y], &board[x][y + 1]);
    }
    if (command == 'd' && y > 0) {
        swap(&board[x][y], &board[x][y - 1]);
    }
}

void displayTimeAndMoves(time_t startTime, int moves) {
    time_t currentTime = time(NULL);
    int elapsedTime = (int)(currentTime - startTime);
    int seconds = elapsedTime % 60;
    int minutes = (int)((elapsedTime / 60) % 60);
    int hours = (int)(elapsedTime / 3600);

    printf("Время: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("Количество ходов: %d\n", moves);
}