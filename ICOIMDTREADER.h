#include <stdio.h>
struct imagedirectory			//on a whole takes 16 bytes
{
	unsigned char width;		//takes 1 byte
	unsigned char height;		//takes 1 byte
	unsigned char cc;			//takes 1 byte
	unsigned char reserve;		//takes 1 byte
	unsigned short cp;			//takes 2 byte
	unsigned short bpp;			//takes 2 byte
	unsigned int bmpsize;		//takes 4 byte
	unsigned int offset;		//takes 4 byte
};
struct imagedirectory Imagedirectoryreader(FILE *);