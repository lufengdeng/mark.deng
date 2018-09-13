#include <cstdio>

void _cdecl OutMsg(int a=10, int b=20, int c=30)
{
	puts("_cdecl call");
	printf("%d + %d = %d\n", a, b, c);
}

void _stdcall OutMsgA(int a, int b, int c)
{
	puts("_stdcall call");
	printf("%d + %d = %d\n", a, b, c);
}

void _fastcall OutMsgB(int a, int b, int c)
{
	puts("_fastcall call");
	printf("%d + %d = %d\n", a, b, c);
}

#define _pascal	_stdcall
void _pascal OutMsgC(int a, int b, int c)
{
	puts("_pascal call");
	printf("%d + %d = %d\n", a, b, c);
}

int main(void)
{
	int a, b, c;
	a = 100, b = 200, c = 300;
	OutMsg();
	OutMsgA(a, b, c);
	OutMsgB(a, b, c);
	OutMsgC(a, b, c);
	return 0;
}
