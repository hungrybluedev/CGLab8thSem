CC=gcc
CFLAGS=-Wall

all: test

test: test.c
	$(CC) $(CFLAGS) $(^) -o bin/$(@) -lGL -lGLU -lglut

run: test
	./bin/test

clean:
	rm bin/*