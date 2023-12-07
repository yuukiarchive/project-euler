CC     ?= cc
CFLAGS := -std=c89 -pedantic-errors -Wall -W -Werror $(CFLAGS)

SRC    := src
BIN    := bin

SOURCE_FILES    := $(wildcard $(SRC)/*.c)
PROBLEM_NUMBERS := $(patsubst $(SRC)/%.c,%,$(SOURCE_FILES))

all:
	@echo Please specify the problem number, like \`make 0001\`.
	@exit 1

$(PROBLEM_NUMBERS):
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(SRC)/$@.c

docs:
	doxygen

clean:
	rm -r $(BIN)
