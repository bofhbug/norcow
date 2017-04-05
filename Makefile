NAME=norcow_test
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -DUNIX
LDFLAGS=
LIBS=
OBJ=$(NAME).o norcow.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LIBS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)
