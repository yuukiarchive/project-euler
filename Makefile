CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror

all:
	$(error Please specify the problem number, like `make 0001`)

$(wildcard *.c):
	$(CC) $(CFLAGS) $@

.PHONY: clean
clean:
	find . -type f -perm -111 -exec rm '{}' \;
