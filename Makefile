CC     ?= cc
CFLAGS := -O3 -march=native -std=c89 -pedantic-errors -Wall -W -Werror $(CFLAGS)

SRC    := src
BUILD  := build

SOURCE_FILES    := $(wildcard $(SRC)/*.c)
PROBLEM_NUMBERS := $(patsubst $(SRC)/%.c,%,$(SOURCE_FILES))

all:
	$(error Please specify the problem number as: `make [XXXX]`)

$(PROBLEM_NUMBERS): | $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $(SRC)/$@.c

$(BUILD):
	mkdir $(BUILD)

docs:
	doxygen

clean:
	rm -r $(BUILD)
