CC = gcc
CFLAGS = -O2

all: bincrc bin2uf2

bincrc: bincrc.c
	$(CC) $(CFLAGS) -o bincrc bincrc.c

bin2uf2: bin2uf2.c
	$(CC) $(CFLAGS) -o bin2uf2 bin2uf2.c

clean:
	rm -f bincrc bin2uf2
