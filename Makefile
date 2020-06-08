
CC = gcc
CFLAGS = -Wall -Werror -pedantic-errors
LDFLAGS =

EXEC = main

SRC = \
	main.c \
	tm.c

OBJ= $(SRC:.c=.o)


all: $(EXEC)
	@echo "Compilation done"

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)

.PHONY: clean
