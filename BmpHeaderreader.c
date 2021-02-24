#include "BmpHeaderreader.h"
struct BMPData readbmp(FILE *ifile)//Function returning a structure which will have the BMPDIB header in it
{
	struct BMPData Data;

	fread(&Data.intBitmapheadersize,4,1,ifile);//Reading the data from the file into header data according to their size and the fixed structure of a BMPDIB header 	
	fread(&Data.intWidth,4,1,ifile);				
	if (Data.intWidth == 0)
		Data.intWidth = 256;

	fread(&Data.intheight,4,1,ifile);			
	if (Data.intheight == 0)
		Data.intheight = 256;

	fread(&Data.intColorPlane,2,1,ifile);			
	fread(&Data.intbitperpixel,2,1,ifile);			
	fread(&Data.intcompression,4,1,ifile);			
	fread(&Data.intFileSize,4,1,ifile);			
	fread(&Data.XpixelPerM,4,1,ifile);			
	fread(&Data.YpixelPerM,4,1,ifile);			
	fread(&Data.ColorsUsed,4,1,ifile);			
	fread(&Data.colorsImportant,4,1,ifile);	

	return(Data);
}