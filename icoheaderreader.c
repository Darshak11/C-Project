#include "icoheaderreader.h"
struct ICO_header Icoheaderreader(FILE *fp)
{
	struct ICO_header header;
	fread(&header,6,1,fp);
	return header;
}