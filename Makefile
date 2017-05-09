CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -DUNIX
LDFLAGS=
LIBS=
OBJ=norcow.o

all: test_api.exe test_random.exe

%.exe: %.o $(OBJ)
	$(CC) $(LDFLAGS) $(LIBS) $(OBJ) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) *.exe
