#include <stdio.h>
struct imagedirectory
{
	unsigned char width;
	unsigned char height;
	unsigned char cc;
	unsigned char reserve;
	unsigned short cp;
	unsigned short bpp;
	unsigned int bmpsize;
	unsigned int offset;
};
struct imagedirectory Imagedirectoryreader(FILE *);