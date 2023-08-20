#include "game.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

// Функция для вывода игровой доски на экран
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

// Функция для обмена значениями двух переменных
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция для перемешивания игровой доски
void shuffle(int board[SIZE][SIZE]) {
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Преобразование индекса i в строку и столбец
        int row_i = i / SIZE; // Получаем номер строки, где находится элемент с индексом i                               
        int col_i = i % SIZE; // Получаем номер столбца, где находится элемент с индексом i

        // Преобразование индекса j в строку и столбец
        int row_j = j / SIZE; // Получаем номер строки, где находится элемент с индексом j
        int col_j = j % SIZE; // Получаем номер столбца, где находится элемент с индексом j

        // Обмен элементов в позициях (row_i, col_i) и (row_j, col_j)
        swap(&board[row_i][col_i], &board[row_j][col_j]);
    }
}

// Функция для проверки победы в игре
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

// Функция для выполнения хода в игре
void move(int board[SIZE][SIZE], char command) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y] == 0) {
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
                return; // Выход из функции после хода
            }
        }
    }
}

// Функция для вывода количества ходов
void displayMoves(int moves) {
    printf("Количество ходов: %d\n", moves);
}
