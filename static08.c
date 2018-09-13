#include <stdio.h>
#include <stdlib.h>

void Test1(void);

void Swap(int a, int b)
{
	// static int sa = a, sb = b; // error
	static int sa, sb;
	sa = a, sb = b;
	a = sb;
	b = sa;
}

int
main(void)
{
	Test1();
	return 0;
}

void Test1(void)
{
	int a, b;
	a = 1982, b = 2008;
	printf("a, b: %d, %d\n", a, b);
	Swap(a, b);
	printf("a, b: %d, %d\n", a, b); // Can't to Swap
}
