#include <reg51.h>
void main()
{ 
	unsigned char xdata *ptr=0x4000;
  unsigned char xdata *ptr1=0x401a;
	int i;
	for(i=0;i<5;i++)
	{
		*ptr1=*ptr;
		ptr++;
		ptr1++;
	}
}
