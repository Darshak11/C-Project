#include <stdio.h>
struct ICO_header   //ICO file consists of an Icon header and an Icon Directory 

//Icon Header stores general information about the ICO file
//This is the Header
{ 
	unsigned short constant; //this constant is Reserved and is of size 2 bytes and must be 0 always
	unsigned short imgt;     //this imgt is Type, specifies the image type, 1 for icon (.ICO) image
	unsigned short nimages;  //this is the Count, specifies the number of images in the file
};
struct ICO_header Icoheaderreader(FILE *);//prototype declairation
