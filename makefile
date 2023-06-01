CC = gcc
CFLAGS = -I. -Wall -Wextra -pedantic
DEPS = unity.h game.h
OBJ_MAIN = main.o game.o
OBJ_TESTS = unity.o game.o game_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ_MAIN)
	$(CC) -o $@ $^ $(CFLAGS)

game_test: $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o main game_test
