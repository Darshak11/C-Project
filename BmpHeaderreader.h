#include <stdio.h>
struct BMPData 
{
	short int intHeader, intColorPlane, intbitperpixel;
	int intheight, intWidth;
	unsigned int intImageSize, intBitmapheadersize;
	unsigned int intcompression, inthresolution, intvresolution;
	unsigned long intBitMapSize;
	unsigned long intOffset, intFileSize;

	unsigned int temp;
	unsigned char maxValue;
	unsigned char ch;
	long totalImagepixels;
	unsigned int XpixelPerM;
	unsigned int YpixelPerM;
	unsigned int ColorsUsed;
	unsigned int colorsImportant;
};
struct BMPData readbmp(FILE *);