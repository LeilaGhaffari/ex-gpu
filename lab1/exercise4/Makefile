
EXAMPLE=ex4

CC=gcc
CFLAGS= -O3 -Wextra
OBJ=$(EXAMPLE).o

%.o : %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXAMPLE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean
clean:
	rm -rf $(EXAMPLE) $(OBJ)
