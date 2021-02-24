#include "BmpDataReader.h"
#include <stdlib.h>
struct pic bmp32reader(FILE *fp,unsigned int height,unsigned int width)//Function returning the the full image data with the height and width of the image
{
	struct pic img;
	img.height=height;
	img.width=width;
	img.rgba=(struct RGBA**) malloc(img.height*sizeof(void*));//Dynamically assigning memory to pointer pointer from the structure of image, in simpler words assigning number of rows to the 2d dimensional picture array
	for(int i=img.height-1;i>=0;i--)
	{
		img.rgba[i]=(struct RGBA*)malloc(img.width*sizeof(struct RGBA));//Dynamically assigning memory to the pointer of the pointer pointer or assigning the memory for the width of the image data
		for(int j=0;j<img.width;j++)
		{
			fread(&img.rgba[i][j],4,1,fp);//Reading each pixel from the data
		}
	}
	return img; 
}
void freeImage(struct pic img)//Function to free the dynamically assigned memory
{
	for(int i=img.height-1;i>=0;i--)
	{
		free(img.rgba[i]);//Freeing each row of the 2d array at a time,freeing the columns
	}
	free(img.rgba);//freeing the complete allocated memory at last, freeing the rows
}