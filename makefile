CC = gcc
CFLAGS = -I. -I./src -Wall -Wextra
DEPS = src/game.h
OBJ_MAIN = src/main.o src/game.o
OBJ_TESTS = tests/game_test.o src/game.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ_MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

main_test.o: tests/main_test.c
	$(CC) -c -o $@ $< $(CFLAGS)

game_test: $(OBJ_TESTS) main_test.o
	$(CC) -o $@ $^ $(CFLAGS)
	./game_test

.PHONY: clean

clean:
	rm -f *.o main game_test
