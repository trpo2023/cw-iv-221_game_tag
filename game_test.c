#include "unity.h"
#include "game.h"

void test_swap(void) {
    int a = 5;
    int b = 10;
    swap(&a, &b);
    TEST_ASSERT_EQUAL_INT(10, a);
    TEST_ASSERT_EQUAL_INT(5, b);
}

void test_checkWin(void) {
    int board1[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    TEST_ASSERT_EQUAL_INT(1, checkWin(board1));

    int board2[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 0, 15}};
    TEST_ASSERT_EQUAL_INT(0, checkWin(board2));
}

void test_shuffle(void) {
    int board[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    shuffle(board);

    int seen[SIZE * SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int number = board[i][j];
            TEST_ASSERT(number >= 0 && number < SIZE * SIZE);
            TEST_ASSERT(seen[number] == 0);
            seen[number] = 1;
        }
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        TEST_ASSERT(seen[i] == 1);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    RUN_TEST(test_checkWin);
    RUN_TEST(test_shuffle);
    UNITY_END();

    return 0;
}
