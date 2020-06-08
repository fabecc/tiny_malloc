
EXEC = main

CFLAGS = -Wall -Werror -pedantic-errors
LDFLAGS =

SRC = \
	main.c \
	tm.c

OBJ= $(SRC:.c=.o)


all: $(EXEC)
	@echo "Compilation done"

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf *.o
	@rm -rf $(EXEC)
