C=gcc
CFLAGS=-I.
DEPS = icoheaderreader.h ICOIMDTREADER.h BmpHeaderreader.h BmpDataReader.h writetag.h
OBJ = icoheaderreader.o ICOIMDTREADER.o BmpHeaderreader.o BmpDataReader.o writetag.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

my_project: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o proj_make

