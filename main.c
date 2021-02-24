#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BmpDataReader.h"
#include "BmpHeaderreader.h"
#include "icoheaderreader.h"
#include "ICOIMDTREADER.h"
#include "writetag.h"
int main()
{
	char ch;FILE *fo;
	char filename[30];
	fo=fopen("b1.tiff","wb");		// Opening tiff file in wb mode
	FILE *fp;
	
	printf("Enter name of ico file with extension: ");
	scanf("%s",filename);	
		
	fp=fopen(filename,"rb");
	
	/* Reading Ico header and directory */
	struct ICO_header icoheader=Icoheaderreader(fp);
	struct imagedirectory icoimd=Imagedirectoryreader(fp);
	
	
	/* Header*/
	fwrite("II",2,1,fo);	//First two bytes of the header is occupied by the endian byte order
	
	int b=42;		//Number that represents TIFF file. It occupies 2 bytes	
	fwrite(&b,2,1,fo);
	
	b=8;		//Offset of the first IFD. It occupies 4 bytes
	fwrite(&b,4,1,fo);

	/* First IFD*/
	int a=13;		//Number of Directory entries. It occupies 2 bytes
	fwrite(&a,2,1,fo);
	
	int height=(short)icoimd.height;
	int width=(short)icoimd.width;

	/* Since width and height occupies 1 byte, the values they store is 0-255. So, the value 0 indicates 256*/
	if(height==0)
		height=256;
	if(width==0)
		width=256;
	struct BMPData Data=readbmp(fp);
	struct pic imgdata=bmp32reader(fp,height,width);		// Reading all the bmp image data


	/* Syntax of WriteTag() : WriteTag(file pointer, Decimal value of the tag, Tag type, Count, Value)*/
	/* Tags are written in the ascending order*/

	WriteTag(fo,256,4,1,width);		//Tag that represents the image width.
	WriteTag(fo,257,4,1,height);		//Tag that represents the image height.

	WriteTag(fo,258,3,1,8);		//Tag that represents the Bits per Sample. It has a fixed value of 8 in this case.
	WriteTag(fo,259,3,1,1);		//Tag that represents the Compression. It has a fixed value of 1 in this case (No compression).
	WriteTag(fo,262,3,1,2);		//Tag that represent photometricInterpretation. its value is 2 for RGB images

	WriteTag(fo,273,4,height,170);	//Tag that represents the Stripoffsets.

/* Since the stripoffsets occupy more than 4 bytes of memory, they are written after the completion of all tags. This location is 170 [8(bytes of header) + 2(bytes of no. of directory entries) + 13*12(directory entries * bytes of each entry) + 4(for putting 0 at last of our IFD)]. Each stripoffset occupies 4 bytes of memory and the number of stripoffsets is equal to the height. So, the stripoffsets occupy (height*4) bytes of memory */

	int nwp=170+(4*height);

	WriteTag(fo,277,3,1,4);		//Tag that represents the Samples per Pixel. It has a fixed value of 4(R,G,B,ALPHA) in this case.
	WriteTag(fo,278,3,1,1);		//Tag that represents the Rows per Strip. In our case we have 1 row per strip.
	WriteTag(fo,279,4,height,nwp);	//Tag that represents the StripByteCount.

/* Since the StripByteCount of all the strips occupy more than 4 bytes of memory, they are written after the completion of stripoffsets. This location is 170 + (height*4). Each stripbytecount data occupies 4 bytes of memory and the number of stripbytecounts to be written is equal to the height. So, the stripbytecount occupies (height*4) bytes of memory. */
	
	WriteTag(fo,282,5,1,Data.inthresolution);	//Tag that represents the XResolution.
	WriteTag(fo,283,5,1,Data.intvresolution);	//Tag that represents the YResolution.
	WriteTag(fo,296,3,1,2);			//Tag that represents the ResolutionUnit.
	WriteTag(fo,338,3,1,1);			//Tag that represents the extra Sample data.(ALPHA)

    	a=0;
    	fwrite(&a,4,1,fo);				//The offset of the second IFD is set to 0 because there is only one IFD.

	/* IFD COMPLETED */

	int stroffset=170+(height*8);			//Address of the first strip is stored in stroffset.

	for(int i=0;i<height;i++)
	{
		fwrite(&stroffset,4,1,fo);		// Our fo pointer is at offset 170 now
		stroffset += width*4;		//Each strip occupies width*4 bytes of memory. Every strip starts after (width*4) of the previous strip. So, the stroffset is continuously incremented by width*4.
	}

	for(int i=0;i<height;i++)
	{
		int m=width*4;			// Each strip occupies (width*4) bytes	(Because each pixel takes 4 bytes)	
		fwrite(&m,4,1,fo);		// writing that value height no. of times.
	}

	
	

	/* Now we will write all the pixel data in our tiff file*/
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			fwrite(&imgdata.rgba[i][j].red,1,1,fo);
			fwrite(&imgdata.rgba[i][j].green,1,1,fo);
			fwrite(&imgdata.rgba[i][j].blue,1,1,fo);
			fwrite(&imgdata.rgba[i][j].alpha,1,1,fo);
		}
	}
 
	freeImage(imgdata);
	fclose(fp);
	fclose(fo);

	/* Now reached the end of the program*/

	printf("*************************************\n");
	printf("** Program successfully Terminated **\n");
	printf("*************************************\n");

	return 0;
	
}