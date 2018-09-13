#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*Call)(); 		// 括号内参数为可变个数
// typedef void (*Call)(void); 	// 括号指明无参数

void Test1(void)
{
	char *str;
	if((str = malloc(50)) == NULL) {
		puts("Not enough to allocate for the string");
		exit(1);
	}
	puts("Input the string:");
	gets(str);
	puts("You input string is ");
	puts(str);
	free(str);
}

void Test2(void)
{
	int *num[10]; // 指向10个元素的整型指针
	num[0] = calloc(sizeof(int), 100);
	if (!num[0]) {
		puts("out of memory");
		exit(2);
	}
	int i;
	puts("");
	for (i=0; i<10; i++)
		printf(" %02X ", *num[i]);
	free(num[0]);
}

static void ShowHex(char *p, int n)
{
	int i;
	puts("");
	for (i=0; i<n; i++) {
		printf(" %02X ", *p++);
		if ((i+1)%16==0) 
			puts("");
	}
	puts("");
}

static void SaveBuf(void *dest, const void *src, size_t n)
{
	memcpy(dest, src, n);
}

static void MoveBuf(void *dest, const void *src, size_t n)
{
	memmove(dest, src, n);
}

void Test3(void)
{
	char *ptr = NULL;	
	int s = 64;
	char sav[s];
	ptr = malloc(sizeof(char) * s);
	SaveBuf(sav, ptr, s);
	ShowHex(ptr, s);
	memset(ptr, '\0', s); // memset 只能用于 void 或 char 类型指针或数组
	ShowHex(ptr, s);
	ShowHex(sav, s);
	char sss[s];
	MoveBuf(sss, sav, s);
	ShowHex(sav, s);
	ShowHex(sss, s);
	free(ptr);
}

int main(void)
{
	Call Func = Test1;
	Func();
	printf("Func addr: %p\taddr: %p\n", Func, Test1);
	//Func(1999, 2008);
	Func = Test2;
	Func();
	Test3();
	return 0;
}
