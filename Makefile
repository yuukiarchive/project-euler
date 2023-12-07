CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror

SRC=src
BIN=bin
SOURCE_FILES=$(wildcard $(SRC)/*.c)
PROBLEM_NUMBERS=$(basename $(notdir $(SOURCE_FILES)))

.PHONY: all
all:
	$(error Please specify the problem number, like `make 0001`)

.PHONY: $(PROBLEM_NUMBERS)
$(PROBLEM_NUMBERS):
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(SRC)/$@.c

.PHONY: clean
clean:
	rm -r $(BIN)
