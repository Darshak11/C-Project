#include "icoheaderreader.h"
struct ICO_header Icoheaderreader(FILE *fp)
{
	struct ICO_header header;// creating a variable named header of the user-defined data type, struct ICO_header
	fread(&header,6,1,fp);//this function fread has 4 parameters, (pointer,size in bytes of each element to be read,number of 
                              //elements,pointer to a FILE object that specifies an input stream)
	return header;//returning header variable with 3 elements of 2 byte size each
}
