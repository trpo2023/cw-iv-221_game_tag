#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <time.h>

#define SIZE 4

int main() {
    // Создание начальной раскладки доски
    int board[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    // Инициализация генератора случайных чисел на основе текущего времени
    srand(time(NULL));

    // Перемешивание начальной раскладки доски перед началом игры
    shuffle(board);

    int moves = 0; // Инициализация счетчика ходов

    while (1) {
        system("clear"); // Очистка экрана (для UNIX-подобных систем)
        printBoard(board); // Вывод текущей раскладки доски
        printf("'w' - вверх\n's' - вниз\n'a' - влево\n'd' - вправо\n'q' - выход\n");

        if (checkWin(board)) {
            printf("Поздравляем! Вы выиграли!\n");
            displayMoves(moves); // Вывод количества ходов
            break;
        }

        char command;
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Выход из игры.\n");
            displayMoves(moves); // Вывод количества ходов
            break;
        }

        if (command == 'w' || command == 'a' || command == 's' || command == 'd') {
            move(board, command); // Выполнение хода
            moves++; // Увеличение счетчика ходов
        }
    }

    return 0;
}
