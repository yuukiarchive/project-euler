# FIXME: `make [XXXX]` and `make docs` recompile every time.

# CC=cc is set by default in GNU Make.
CFLAGS := -O3 -march=native -std=c89 -pedantic-errors -Wall -W -Werror $(CFLAGS)

SRC    := src
BUILD  := build

SOURCE_FILES    := $(wildcard $(SRC)/*.c)
PROBLEM_NUMBERS := $(patsubst $(SRC)/%.c,%,$(SOURCE_FILES))

.PHONY: all
all:
	$(error Please specify the problem number as: `make [XXXX]`)

.PHONY: $(PROBLEM_NUMBERS)
$(PROBLEM_NUMBERS): | $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $(SRC)/$@.c

$(BUILD):
	mkdir $(BUILD)

.PHONY: docs
docs:
	doxygen

.PHONY: clean
clean:
	rm -r $(BUILD)
