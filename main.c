#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

#define SIZE 4

int main() {
    int board[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    shuffle(board);

    time_t startTime = time(NULL);
    time_t currentTime;
    int minutes = 0;
    int hours = 0;
    int moves = 0;

    while (1) {
        currentTime = time(NULL);
        int elapsedTime = (int)(currentTime - startTime);
        int seconds = elapsedTime % 60;

        if (seconds == 0 && elapsedTime > 0) {
            minutes++;
            if (minutes == 60) {
                hours++;
                minutes = 0;
            }
        }

        system("clear");
        printBoard(board);
        printf("'w' - вверх\n's' - вниз\n'a' - влево\n'd' - вправо\n'q' - выход\n");

        if (checkWin(board)) {
            printf("Поздравляем! Вы выиграли!\n");
            printf("Время: %02d:%02d:%02d\n", hours, minutes, seconds);
            printf("Количество ходов: %d\n", moves);
            break;
        }

        char command;
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Выход из игры.\n");
            currentTime = time(NULL);
            elapsedTime = (int)(currentTime - startTime);
            seconds = elapsedTime % 60;
            minutes = (int)((elapsedTime / 60) % 60);
            hours = (int)(elapsedTime / 3600);
            printf("Время: %02d:%02d:%02d\n", hours, minutes, seconds);
            printf("Количество ходов: %d\n", moves);
            break;
        }

        if (command == 'w' || command == 'a' || command == 's' || command == 'd') {
            move(board, command);
            moves++;
        }
    }

    return 0;
}
