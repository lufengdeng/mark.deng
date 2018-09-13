#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_INFO	"Out of memroy"

void Test1(void);

void Hello(void)
{
	puts("Hello");
}

int main(void)
{
	typedef void (*Call)();	
	Test1();
	Call fn = NULL;
	fn = Hello;
	fn();
	printf("function %s first addr: %p\n", __func__, fn);
	int i;
	char *p;
	p = (void *)fn;
	for (i=0; i<40; i++)
		printf(" %02X ", p[i]&0xff);
	getchar();
	return 0;
}

void Test1(void)
{
	int i;
	int *Ptr[5], *p, *pa;
	p = (int *)malloc(sizeof(int) * 64);
	if (!p) {
		puts(ERR_INFO);
		exit(-1);
	}
	
	pa = p;
	//p[0] = 1982; // 错
	//p[63] = 2007; // 错
	for (i=0; i<64; i++) {
		//printf(" %02X ", *p++); // p 变址了,所以出错
		//printf(" %02X ", p[i]); // 同上
		//printf(" %02X ", *pa++); // 错, 栈内存不能指向堆内存
		//printf(" %02X ", pa[i]); // 错, 栈内存不能指向堆内存
	}
	//printf("p[0]: %d\n", p[0]);
	//printf("p[63]: %d\n", p[63]);
	free(p);
	
	Ptr[0] = (int *)malloc(sizeof(int) * 64);
	if (!Ptr[0]) {
		puts(ERR_INFO);
		exit(-1);
	}
	for (i=0; i<64; i++) {
		//printf(" %02X ", *Ptr[0]++);
	}
	free(Ptr[0]);
}
