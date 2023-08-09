CC=gcc
CFLAGS=-Werror -Wpedantic
LDFLAGS=-lm
PROJECT_NAME=linked_lists

build: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROJECT_NAME) main.c

clean:
	rm -f $(PROJECT_NAME)
