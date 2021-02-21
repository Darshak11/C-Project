#include <stdio.h>
struct RGBA
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char alpha;
};
struct pic
{
	unsigned int height;
	unsigned int width;
	struct RGBA **rgba;
};
struct pic bmp32reader(FILE* ,unsigned int ,unsigned int);
void freeImage(struct pic );