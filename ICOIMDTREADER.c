#include "ICOIMDTREADER.h"
struct imagedirectory Imagedirectoryreader(FILE *fp)
{
	struct imagedirectory img;
	fread(&img.width,1,1,fp);
	fread(&img.height,1,1,fp);
	fread(&img.cc,1,1,fp);
	fread(&img.reserve,1,1,fp);
	fread(&img.cp,2,1,fp);			//fread(&img.cp,4,1,fp);
	fread(&img.bpp,2,1,fp);
	fread(&img.bmpsize,4,1,fp);
	fread(&img.offset,4,1,fp);
	fseek(fp,img.offset,SEEK_SET);
	return img;
}