#include "game.h"
#include <stdio.h>

// Функция для проверки условия и вывода сообщения об ошибке
void assertEqualInt(int expected, int actual, const char *message) {
  if (expected == actual) {
    printf("PASS: %s\n", message);
  } else {
    printf("FAIL: %s (Expected: %d, Actual: %d)\n", message, expected, actual);
  }
}

void test_swap() {
  int a = 5;
  int b = 10;
  swap(&a, &b);
  assertEqualInt(10, a, "swap: a should be 10");
  assertEqualInt(5, b, "swap: b should be 5");
}

void test_checkWin() {
  int board1[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
  assertEqualInt(1, checkWin(board1),
                 "checkWin: should return 1 for a winning board");

  int board2[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 0, 15}};
  assertEqualInt(0, checkWin(board2),
                 "checkWin: should return 0 for a non-winning board");
}

void test_shuffle() {
  int board[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

  // Копируем оригинальное поле для сравнения после перемешивания
  int original_board[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      original_board[i][j] = board[i][j];
    }
  }

  shuffle(board);

  // Проверяем, что поле изменилось после перемешивания
  int same = 1;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != original_board[i][j]) {
        same = 0;
        break;
      }
    }
  }

  if (same == 0) {
    printf("PASS: shuffle: board was shuffled\n");
  } else {
    printf("FAIL: shuffle: board was not shuffled\n");
  }
}

void test_move_up() {
  int board[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 0, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  // Проверка движения вверх
  move(board, 'w');
  assertEqualInt(9, board[1][1], "move_up: element should move up");
  assertEqualInt(0, board[2][1],
                 "move_up: empty cell should take the place of the element");
}

void test_move_down() {
  int board[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 0, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  // Проверка движения вниз
  move(board, 's');
  assertEqualInt(0, board[0][1],
                 "move_down: empty cell should take the place of the element");
  assertEqualInt(2, board[1][1], "move_down: element should move down");
}

void test_move_left() {
  int board[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 0, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  // Проверка движения влево
  move(board, 'a');
  assertEqualInt(0, board[1][2],
                 "move_left: empty cell should take the place of the element");
  assertEqualInt(6, board[1][1], "move_left: element should move left");
}

void test_move_right() {
  int board[SIZE][SIZE] = {
      {1, 2, 3, 4}, {5, 0, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  // Проверка движения вправо
  move(board, 'd');
  assertEqualInt(5, board[1][1], "move_right: element should move right");
  assertEqualInt(0, board[1][0],
                 "move_right: empty cell should take the place of the element");
}

int main(void) {
  test_swap();
  test_checkWin();
  test_shuffle();
  test_move_up();
  test_move_down();
  test_move_left();
  test_move_right();

  return 0;
}
