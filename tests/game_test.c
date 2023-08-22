#include "unity.h"
#include "game.h"
#include <assert.h>

void setUp(void) { /* Ничего не делаем */ }
void tearDown(void) { /* Ничего не делаем */ }

void test_swap(void) {
    int a = 5;
    int b = 10;
    swap(&a, &b);
    TEST_ASSERT_EQUAL_INT(10, a);
    TEST_ASSERT_EQUAL_INT(5, b);
}

/*
  Тестирование функции checkWin() для проверки условия победы на начальном поле.
  Начальное поле содержит числа от 1 до SIZE*SIZE-1 и 0 в последней ячейке.
  Ожидается, что функция вернет 1 (успешную победу).
*/
void test_checkWin(void) {
    int board1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };
    TEST_ASSERT_EQUAL_INT(1, checkWin(board1));

    int board2[SIZE][SIZE] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 0, 15}
    };
    TEST_ASSERT_EQUAL_INT(0, checkWin(board2));
}

void test_shuffle(void) {
    int board[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

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

    TEST_ASSERT_FALSE(same);
}

void test_move_up() {
    int board[SIZE][SIZE] = {{1, 2, 3, 4},
                             {5, 0, 6, 7},
                             {8, 9, 10, 11},
                             {12, 13, 14, 15}};
    
    // Проверка движения вверх
    move(board, 'w');
    assert(board[1][1] == 9);  // Проверяем, что элемент переместился вверх
    assert(board[2][1] == 0);  // Проверяем, что пустая ячейка заняла место элемента
}

void test_move_down() {
    int board[SIZE][SIZE] = {{1, 2, 3, 4},
                             {5, 0, 6, 7},
                             {8, 9, 10, 11},
                             {12, 13, 14, 15}};
    
    // Проверка движения вниз
    move(board, 's');
    assert(board[0][1] == 0);  // Проверяем, что пустая ячейка заняла место элемента
    assert(board[1][1] == 2);  // Проверяем, что элемент переместился вниз
}

void test_move_left() {
    int board[SIZE][SIZE] = {{1, 2, 3, 4},
                             {5, 0, 6, 7},
                             {8, 9, 10, 11},
                             {12, 13, 14, 15}};
    
    // Проверка движения влево
    move(board, 'a');
    assert(board[1][2] == 0);  // Проверяем, что пустая ячейка заняла место элемента
    assert(board[1][1] == 6);  // Проверяем, что элемент переместился влево
}

void test_move_right() {
    int board[SIZE][SIZE] = {{1, 2, 3, 4},
                             {5, 0, 6, 7},
                             {8, 9, 10, 11},
                             {12, 13, 14, 15}};
    
    // Проверка движения вправо
    move(board, 'd');
    assert(board[1][1] == 5);  // Проверяем, что элемент переместился вправо
    assert(board[1][0] == 0);  // Проверяем, что пустая ячейка заняла место элемента
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    RUN_TEST(test_checkWin);
    RUN_TEST(test_shuffle);
    RUN_TEST(test_move_up);
    RUN_TEST(test_move_down);
    RUN_TEST(test_move_left);
    RUN_TEST(test_move_right);
    UNITY_END();

    return 0;
}
