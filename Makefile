# CC=cc is set by default in GNU `make`.
CFLAGS := -O3 -march=native -std=c89 -pedantic-errors -Wall -W -Werror $(CFLAGS)

all:
	$(CC) $(CFLAGS) src/0001.c
	@exit 0
