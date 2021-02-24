#include "ICOIMDTREADER.h"
struct imagedirectory Imagedirectoryreader(FILE *fp)
{
	struct imagedirectory img;			//making a varible of imagedirectory structure
	fread(&img.width,1,1,fp);			// fread( ptr, size_bytes, n_members, FilePtr);		
	fread(&img.height,1,1,fp);			// ptr = "pointer to a block of memory" 
	fread(&img.cc,1,1,fp);				// size_bytes = "size in bytes of each element to be read"
	fread(&img.reserve,1,1,fp);			// n_members = "number of elements, with size mentioned before"
	fread(&img.cp,2,1,fp);				// FilePtr = "pointer to a FILE object that specifies an input"
	fread(&img.bpp,2,1,fp);
	fread(&img.bmpsize,4,1,fp);
	fread(&img.offset,4,1,fp);
	fseek(fp,img.offset,SEEK_SET);		// fseek("pointer to a file", "no. of byte to offset", "Beginning of file")
	return img;
}