CC = gcc
CFLAGS = -I. -I./src -Wall -Wextra
DEPS = src/game.h
OBJ_MAIN = src/main.o src/game.o
OBJ_TESTS = src/game.o tests/game_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ_MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

test: $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o main test

