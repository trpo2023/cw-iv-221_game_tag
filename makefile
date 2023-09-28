CC = gcc
CFLAGS = -I. -Wall -Wextra -pedantic
DEPS = tests/unity.h tests/game.h
OBJ_MAIN = src/main.o src/game.o
OBJ_TESTS = tests/unity.o src/game.o tests/game_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ_MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

game_test: $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o main game_test
