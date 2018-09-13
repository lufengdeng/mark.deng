#include <stdio.h>

void GetPtrCode(void)
{
	unsigned char *ptr = (unsigned char *)0x4011a0;
	int i;
	for (i=0; i<40; i++)
		printf(" %02X ", *ptr++);	
}

void GetPtrCodeEx(void *addr, int s)
{
	unsigned char *ptr = addr;
	int i;
	for (i=0; i<s; i++)
		printf(" %02X ", *ptr++&0xff);
	puts("");	
}

int main(void)
{
	GetPtrCode();
	puts("");
	GetPtrCodeEx((void *)0x4011a0, 40);
	// GetPtrCodeEx((void *)0xa0000000, 32);
	return 0;
}
