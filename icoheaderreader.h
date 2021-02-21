#include <stdio.h>
struct ICO_header
{ 
	unsigned short constant;
	unsigned short imgt;
	unsigned short nimages;
};
struct ICO_header Icoheaderreader(FILE *);