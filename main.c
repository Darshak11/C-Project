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
	fo=fopen("product.tiff","wb");
	FILE *fp;	
	printf("Enter name of ico file with extension: ");
	scanf("%s",filename);		
	fp=fopen(filename,"rb");
	fwrite("II",2,1,fo);
	int b=42;
	fwrite(&b,2,1,fo);
	b=8;
	fwrite(&b,4,1,fo);
	int a=13;
	fwrite(&a,2,1,fo);	
	struct ICO_header icoheader=Icoheaderreader(fp);
	struct imagedirectory icoimd=Imagedirectoryreader(fp);	
	struct BMPData Data=readbmp(fp);
	int height=(short)icoimd.height;
	int width=(short)icoimd.width;
	if(height==0)
		height=256;
	if(width==0)
		width=256;
	WriteTag(fo,256,4,1,width);
	WriteTag(fo,257,4,1,height);	
	WriteTag(fo,258,3,1,8);
	WriteTag(fo,259,3,1,1);
	WriteTag(fo,262,3,1,2);	
	WriteTag(fo,273,4,height,170);
	int nwp=170+(4*height);
	WriteTag(fo,277,3,1,4);
	WriteTag(fo,278,3,1,1);
	WriteTag(fo,279,4,height,nwp);
	WriteTag(fo,282,5,1,Data.inthresolution);
	WriteTag(fo,283,5,1,Data.intvresolution);
	WriteTag(fo,296,3,1,2);	
	WriteTag(fo,338,3,1,1);
    a=0;
    fwrite(&a,4,1,fo);
	int fstroffset=170+(height*8);
	int stroffset=fstroffset;
	for(int i=0;i<height;i++)
	{
		fwrite(&stroffset,4,1,fo);
		stroffset+=width*4;
	}
	for(int i=0;i<height;i++)
	{
		int m=width*4;		
		fwrite(&m,4,1,fo);
	}	
	struct pic imgdata=bmp32reader(fp,height,width);
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
}