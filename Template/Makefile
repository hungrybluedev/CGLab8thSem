CC=gcc
CFLAGS=-Wall
NAME=sine

all: clean $(NAME)

$(NAME): $(NAME).c
mkdir -p bin
	$(CC) $(CFLAGS) $(^) -o bin/$(@) -lGL -lGLU -lglut

run: $(NAME)
	./bin/$(NAME)

clean:
	rm -f bin/*
	rm -rf bin