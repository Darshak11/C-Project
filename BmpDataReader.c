#include "BmpDataReader.h"
#include <stdlib.h>
struct pic bmp32reader(FILE *fp,unsigned int height,unsigned int width)
{
	struct pic img;
	
	img.height=height;	
	if(img.height==0)
		img.height=256;
	img.width=width;
	if(img.width==0)
		img.width=256;
	img.rgba=(struct RGBA**) malloc(img.height*sizeof(void*));
	for(int i=img.height-1;i>=0;i--)
	{
		img.rgba[i]=(struct RGBA*)malloc(img.width*sizeof(struct RGBA));
		for(int j=0;j<img.width;j++)
		{
			fread(&img.rgba[i][j],4,1,fp);
		}
	}
	return img; 
}
void freeImage(struct pic img)
{
	for(int i=img.height-1;i>=0;i--)
	{
		free(img.rgba[i]);
	}
	free(img.rgba);	
}