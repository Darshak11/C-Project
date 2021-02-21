#include "BmpHeaderreader.h"
struct BMPData readbmp(FILE *ifile)
{
	struct BMPData Data;
	
	//set default values
	Data.intHeader = 0;// 2);
	Data.intFileSize = 0;// 4);
	Data.temp = 0;// 2);
	Data.intOffset = 0;// 4);
	Data.intBitmapheadersize = 0;// 2);
	Data.intWidth = 0;// 2);
	Data.intheight = 0;// 2);
	Data.intColorPlane = 0;// 2);
	Data.intbitperpixel = 0;// 2);
	Data.intcompression = 0;// 2);
	Data.intBitMapSize = 0;// 4);
	Data.inthresolution = 0;// 2);
	Data.intvresolution = 0;// 2);

	fread(&Data.intBitmapheadersize,4,1,ifile);		
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