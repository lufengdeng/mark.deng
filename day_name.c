#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct student {
		int id;
		char name[16];
		char sex;
		float math;
		float english;
};

typedef struct student Stu;

void ShowRecord(Stu s)
{
	printf("%d\t%s\t%c\t%.2f\t%.2f\n", s.id, s.name, 
		s.sex, s.math, s.english);
}

void HelloWorld(void)
{
	puts("Hello, world!");
}

void HelloChina(void)
{
	puts("Hello, china!");
}

char* day_name(int n)
{
	static char* name[] = {
		"Illegal day",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday",
	};
	return (n<1 || n>7) ? name[0] : name[n];
}

// 任何两种对象交换位置
void SwapEx(void *a, void *b, int len)
{
	char p, *pa, *pb;
	int i;
	pa = (char *)a;
	pb = (char *)b;
	for (i=0; i<len; i++) {
		p = *pa;
		*pa = *pb;
		*pb = p;
		pa++;
		pb++;
	}
}

int main(void)
{
	int i;
	char* day_name(int n);
	
	int a, b;
	a = 1982, b = 2008;
	printf("a = %d\tb = %d\n", a, b);
	SwapEx(&a, &b, sizeof(int));
	printf("a = %d\tb = %d\n", a, b);
	
	char c1, c2;
	c1 = 'A', c2 = 'a';
	printf("c1 = %c\tc2 = %c\n", c1, c2);
	SwapEx(&c1, &c2, sizeof(char));
	printf("c1 = %c\tc2 = %c\n", c1, c2);
	
	float f1, f2;
	f1 = 3.14, f2 = 6.;
	printf("f1 = %f\tf2 = %f\n", f1, f2);
	SwapEx(&f1, &f2, sizeof(float));
	printf("f1 = %f\tf2 = %f\n", f1, f2);
	
	int *pa, *pb;
	pa = &a, pb = &b;
	printf("pa = %p\tpb = %p\t%d  %d\n", pa, pb, *pa, *pb);
	SwapEx(&pa, &pb, sizeof(int *));
	printf("pa = %p\tpb = %p\t%d  %d\n", pa, pb, *pa, *pb);
	
	printf("sizeof(int): %d\tsizeof(long int): %d\n",
		sizeof(int), sizeof(long int));
	printf("sizeof(long long int): %d\n", sizeof(long long int));
	long long l1, l2;
	l1 = 198219831984;
	l2 = 200720082009;
	printf("l1 = %lld\tl2 = %lld\n", l1, l2);
	SwapEx(&l1, &l2, sizeof(long long));
	printf("l1 = %lld\tl2 = %lld\n", l1, l2);
	
	HelloWorld();
	HelloChina();
	//SwapEx(&HelloWorld, &HelloChina, sizeof(HelloWorld));
	//SwapEx(&HelloWorld, &HelloChina, sizeof(void *));
	// printf("sizeof(void *): %d\n", sizeof(void *));  // 4
	void *p1, *p2;
	p1 = HelloWorld;
	p2 = HelloChina;
	SwapEx(&p1, &p2, sizeof(void *));	// not swap
	HelloWorld();
	HelloChina();
	
	puts("----------------------------");
	typedef void (*Call)();
	Call fn1, fn2;
	fn1 = HelloWorld;
	fn2 = HelloChina;
	fn1();
	fn2();
	SwapEx(&fn1, &fn2, sizeof(Call)); // swap ok
	fn1();
	fn2();
		
	Stu sa, sb;
	sa.id = 1;
	strcpy(sa.name, "XQY");
	sa.sex = 'F';
	sa.math = 93.5f;
	sa.english = 91.f;
	
	sb.id = 8;
	strcpy(sb.name, "DMH");
	sb.sex = 'T';
	sb.math = 99.f;
	sb.english = 85.5f;
	
	puts("Source Data: ");
	ShowRecord(sa);
	ShowRecord(sb);
	SwapEx(&sa, &sb, sizeof(Stu));
	puts("Swap Data: ");
	ShowRecord(sa);
	ShowRecord(sb);
	
	printf("Input day No:\n");
	//i = 7;
	srand((unsigned int)time(NULL));
	i = rand()%7;
	//scanf("%d", &i);
	if (i<0)
		exit(-1);
	
	printf("Day No: %2d --> %s\n", i, day_name(i));
	
	return 0;
}
