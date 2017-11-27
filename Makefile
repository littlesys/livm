CC=gcc
CFLAGS=-g

HEADERS=linst.h lstk.h lheap.h lloader.h livm.h
OBJ=linst.o lstk.o lheap.o lloader.o livm.o

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

livm: $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	del *.exe *.o
