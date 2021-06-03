CC=gcc
CFLAGS=-Wall

all: reflect

reflect: reflect.c
	mkdir -p bin
	$(CC) $(CFLAGS) $(^) -o bin/$(@)

run: reflect
	./bin/reflect

clean:
	rm -f bin/*
	rmdir bin