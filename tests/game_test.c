#include <src/game.h>
#include <thirdparty/ctest.h>

CTEST(swap, swap_test)
{
    int a = 5, b = 10;
    swap(&a, &b);
    ASSERT_EQUAL(10, a);
    ASSERT_EQUAL(5, b);
}

CTEST(move, move_up)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 7, 12}, {13, 14, 11, 15}};

    move(board, 'w');

    ASSERT_EQUAL(0, board[2][2]);
    ASSERT_EQUAL(7, board[1][2]);
}

CTEST(move, move_down)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 7, 12}, {13, 14, 11, 15}};

    move(board, 's');

    ASSERT_EQUAL(0, board[0][2]);
    ASSERT_EQUAL(3, board[1][2]);
}

CTEST(move, move_left)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 7, 12}, {13, 14, 11, 15}};

    move(board, 'a');

    ASSERT_EQUAL(0, board[1][3]);
    ASSERT_EQUAL(8, board[1][2]);
}

CTEST(move, move_right)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 7, 12}, {13, 14, 11, 15}};

    move(board, 'd');

    ASSERT_EQUAL(0, board[1][1]);
    ASSERT_EQUAL(6, board[1][2]);
}

CTEST(checkWin, checkWin_test)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

    int result = checkWin(board);
    ASSERT_EQUAL(1, result);
}

CTEST(shuffle, board_is_shuffled)
{
    int board[SIZE][SIZE]
            = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

    int original_board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            original_board[i][j] = board[i][j];
        }
    }

    shuffle(board);

    int is_board_changed = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != original_board[i][j]) {
                is_board_changed = 1;
                break;
            }
        }
        if (is_board_changed) {
            break;
        }
    }

    ASSERT_TRUE(is_board_changed);
}
