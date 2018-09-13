#include <stdio.h>
#include <ctype.h>
#include <time.h>

static unsigned long long int count;
// void move(); // 有些编译器可行, gcc 不行, 原型必须跟定义同参数个数及类型
void move (int, char, char, char);
void move_ex(int n, char a, char b, char c);

int main(int argc, char *argv[])
{
	int n;
	printf ("Enter num(1 ~ 64): ");
	scanf ("%d", &n);
	if (n >= 1 && n <= 64 && !isdigit(n)) {
		if (argc == 1)
			move (n, 'A', 'B', 'C');	
		else {
			
			puts("Now runing, please wait..");
			move_ex(n, 'a', 'b', 'c');
		}
		printf("  ::::: Total move %llu :::::\n", count);
		// n = 32, count = 4294967295; n = 64, count = 
	} else 
		puts("Enter error!!!");	
	fflush(stdin);
	getchar();
	return 0;
}

void move(int n, char a, char b, char c)
{	
	if (n == 1)
		printf ("\t%c ---> %c\n", a, c);
	else {
		move (n-1, a, c, b);
		printf ("\t%c ---> %c\n", a, c);
		move (n-1, b, a, c);
	}	
	count++;
}

void move_ex(int n, char a, char b, char c)
{	
	if (n == 1) {}
		//printf ("\t%c ---> %c\n", a, c);
	else {
		move_ex (n-1, a, c, b);
		//printf ("\t%c ---> %c\n", a, c);
		move_ex (n-1, b, a, c);
	}	
	count++;
}
