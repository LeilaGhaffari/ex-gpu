
EXAMPLE=ex2

CC=gcc
CFLAGS= -O3 -Wextra
OBJ=$(EXAMPLE).o random.o
DEPS=random.h

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXAMPLE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean
clean:
	rm -rf $(EXAMPLE) $(OBJ)
