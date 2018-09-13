#include <stdio.h>
#include <string.h>
#include <complex.h>
#include <tgmath.h>
 
int main(void)
{
    double complex z1 = I * I;     // 虚数单位平方
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));
 
    double complex z2 = pow(I, 2); // 虚数单位平方
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));
 
    double PI = acos(-1);
    double complex z3 = exp(I * PI); // 欧拉公式
    printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));
 
    double complex z4 = 1+2*I, z5 = 1-2*I; // 共轭
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4*z5), cimag(z4*z5));
	
	printf("%f\t%f\n", 1.0 * -0.0, 1.0 * 0.0);
	
#if 0
	puts("this will not be compiled");
	/* c */
	// c++
#else
	puts("compiled ok");
#endif
	if(0) {
		puts("be compiled but not be executed");
	}
	int a, b, c, d;
	a = 100, b = 30, c = 10, d = 20;
	a = b // *除数: */ c
	+ d; /* c89 编译为 a=b/c+d;
			c99 编译为 a=b+d; */
	printf("a = %d\n", a); // 50 is c99
	//printf("true == %d\n", true);
#include <stdbool.h>
	printf("true == %d\n", true);
	printf("false == %d\n", false);
	printf("!true == %d\n", !true);
	printf("!false == %d\n", !false);
	printf("true + true = %d\n", true + true);
	//for (true = 0; true <10; true++)
	int i;
	for (i=0; i<10; i++)
		printf("true = %d\n", true+i);
	printf("sizeof(true): %d\n", sizeof(true));
	printf("sizeof(_Bool): %d\n", sizeof(_Bool));
	//printf("_Bool == bool ? %d\n", _Bool == bool);
	_Bool yes = true;
	bool no = yes;
	printf("Yes: %d\tno: %d\n", yes, no);
	//cons int n = 10;
	#define n	10
	#define m	3.0
	#define N	\n
	char str[n] = "Yes i do";
	puts(str);
	printf("sizeof(n): %d\n", sizeof(n)); // 4
	printf("sizeof(m): %d\n", sizeof(m)); // 8, 说明C中实型数默认为double 
	printf("sizeof(float): %d\n", sizeof(float));
	int num[sizeof(int)] = { 101, 202, 303, 404 };
	i = 4;
	while (i--)
		printf("%d ", num[3-i]);
	
	// 不赋值就不报错
	int n2[strlen("Have a good time")];/* = {
		1982, 2007, 1984, 2019
	};*/
	//i = 4;
	//while (i--)
	//	printf("%d ", n2[3-i]);
	static unsigned const const int *ptr;
	if (ptr == NULL)
		puts("ptr is NULL");
	else
		puts("ptr not NULL");
	ptr = /*&*/(void *)str;
	puts ("");
	puts(ptr);
}
