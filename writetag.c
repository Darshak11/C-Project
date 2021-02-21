#include "writetag.h"
void WriteTag(FILE *myfile, unsigned short int tagField, unsigned short int FieldType, unsigned int NoOfValues, unsigned int ValueOffset) 
{
	fwrite(&tagField,2,1,myfile);			
	fwrite(&FieldType,2,1,myfile);			
	fwrite(&NoOfValues,4,1,myfile);			
	fwrite(&ValueOffset,4,1,myfile);			
}