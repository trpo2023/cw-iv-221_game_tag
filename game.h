#ifndef GAME_H
#define GAME_H

#define SIZE 4

// Вывод игровой доски на экран
void printBoard(int board[SIZE][SIZE]);

// Обмен значениями двух переменных
void swap(int* a, int* b);

// Перемешивание игровой доски
void shuffle(int board[SIZE][SIZE]);

// Проверка на победу
// Возвращает 1, если игрок выиграл, и 0 в противном случае
int checkWin(int board[SIZE][SIZE]);

// Движение элементов на игровой доске в указанном направлении
void move(int board[SIZE][SIZE], char command);

// Вывод количества ходов
void displayMoves(int moves);

#endif
