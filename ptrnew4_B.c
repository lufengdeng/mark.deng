// cmd /k gcc -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(FULL_CURRENT_PATH)" && CLS && "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" & ECHO. & ECHO ---------------- & echo return %ERRORLEVEL% & PAUSE & EXIT
// cmd /T:0B /k  gcc -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(FULL_CURRENT_PATH)" && CLS && "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" & ECHO. & ECHO ---------------- & echo return %ERRORLEVEL% & echo 程序执行完毕, 任意键返回.. & PAUSE>nul & EXIT

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

typedef struct Fun_head {
		void (*CALL)();
		int (*iCALL)();
		float (*fCALL)();
		char (*cCALL)();
		char* (*strCALL)();
		void *FirstAddr;
		int size;
		void *codes;
} Func;

struct{}h;
struct head{};

void AddTen(int *n)
{
	*n += 10;
}

void StepTen(int *n, char x)
{
	const int STEP = 10;
	switch(x) {
		case '+': *n+=STEP; break;
		case '-': *n-=STEP; break;
		case '*': *n*=STEP; break;
		case '/': *n/=STEP; break;
		case '&': *n&=STEP; break;
		case '|': *n|=STEP; break;
		case '^': *n^=STEP; break;
		default: return;
	}
}

void RandInitChar(char buf[], int n)
{	
	char tmp[] = "+-*/&|^";
	int r;
	// srand((unsigned int)time(NULL)); // 不要将srand函数放在此, 否则每次结果相同
	while (n--) {
		r = rand()%7;
		buf[n] = tmp[r];
	}
}

int RetTwoVal(int a, int b)
{
	return (a+b) *65535 + (a-b);
}

void Test1(void)
{
	char ipt[16] = "";
	char *p = ipt;
	short int age, *siP;
	
	puts("Enter name:");
	gets(p);
	
	printf("sizeof ipt: %d\n", sizeof ipt);
	printf("Name is %s\n", p);
	
	puts("Enter new name:");
	scanf("%s", ipt);
	printf("New name is %s\n", ipt);
	puts("Enter old name:");
	scanf("%s", p);
	printf("Old name is %s\n", p);
	
	puts("Enter age:");
	scanf("%hd", &age);  // short int use %hd format
	printf("Age is %hd\n", age);
	siP = &age;
	puts("Enter new age:");
	scanf("%hd", siP);
	printf("New age is %d\n", age);
}

void Test2(void)
{
	int a, i, *s;
	a = 10;
	s = &a;
	for (i=0; i<10; i++) {
		AddTen(&a);
		*s = a;
		// or: 	AddTen(s);
		printf("s = %d\n", *s);
	}	
	
	a = 30;
	i = 10;
	*s = RetTwoVal(a, i);
	printf("value is %d\n", *s);
	int v, w;
	v = *s/65535;
	w = v-*s;
	printf("ret a+b: %d\n", v);
	printf("ret a-b: %d\n", w);
	
	char opt[16];
	srand((unsigned int)time(NULL)); // 将srand函数放在这里才行
	RandInitChar(opt, 16);
	printf("随机运算符的顺序为: ");
	puts(opt);
	for (i=0; i<16; i++) {		
		StepTen(s, opt[i]);
		printf("操作符是: %c , 当前值为: %d\n", opt[i], *s);
	}
	
	printf("value: %d\n", *s);
	printf("sizeof h : %d\n", sizeof h);
	printf("sizeof struct head : %d\n", sizeof( struct head ));
}

void Test3(void)
{
	puts("Function Test3 runing..");
}

void Test4(void)
{
	int i = NULL;
	int arrs[][2] = {
		{1982, 36},
		{2007, 12},
		{1984, 34},
		{2019, 0}
	};
	
	int (*ptr)[2];
	ptr = arrs;
	printf("ptr: %p , arrs[0][0]: %p  %p  %p  %p\n", 
		ptr, &arrs[0][0], arrs, &arrs[0], arrs[0]);
	printf("i init is %d\n", i);
	/*
	for (i=0; i<sizeof(arrs[i][0]); i++)
		printf("%d, %d\n", *arrs[i], arrs[0][i]);
	*/
	puts("------------------------------------");
	for (i=0; i<8; i++)
		 printf("%d%s", (*ptr)[i], (i+1)%2==0 ? "\n" : ",");  
	
	puts("------------------------------------");
	for (i=0; i<4; i++) {
		printf("%d \n", *(*ptr));		
		ptr++;
	}
	for (i=0; i<4; i++)
		ptr--;
	puts("------------------------------------");
	for (i=0; i<4; i++) {
		printf("%d\t%d\n", (*ptr)[i], (*ptr)[i+1]);				
	}
	
}

int Sum(int a, int b)
{
	return a+b;
}

float GetPI(void)
{
	return 22./7;
}

char GetLittle(void)
{
	return 'R';
}

char* GetAuthor(void)
{
	return "by fengdos";
}

void Add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a+b);
}

void Dec(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a-b);
}

void Mul(int a, int b)
{
	printf("%d x %d = %d\n", a, b, a*b);
}

void Div(int a, int b)
{
	printf("%d / %d = %d\n", a, b, a/b);	
}

void Mod(int a, int b)
{
	printf("%d %% %d = %d\n", a, b, a%b);
}

void Calc(int a, int b, char opt)
{
	void (*Func)();
	switch (opt) {
		case '+': Func = Add; break;
		case '-': Func = Dec; break;
		case '*': Func = Mul; break;
		case '/': Func = Div; break;
		case '%': Func = Mod; break;		
		default: puts("Error: #1015 option wrong."); /*break;*/ return;
	}
	Func(a, b);
}

void AddrArrs(void)
{
	void *ptr[10] = {
		Add, Dec, Mul, Div, Mod
	};
	int i;
	for (i=0; i<5; i++)
		printf("Addr arrs: %p\n", ptr[i]);
	printf("Func addr %p ---> %p , size: %d bytes\n", 
		ptr[0], ptr[4], ptr[4]-ptr[0]);
}

char GetNeg(char n)
{
	if ( (n>>7)&1 )
		return '+';
	else 
		return '-';
}

char GetNegE(short int n)
{
	if ( (n>>15)&1 )
		return '+';
	else 
		return '-';
}

char GetNegEx(int n)
{
	if ( (n>>31)&1 )
		return '+';
	else 
		return '-';
}

int main(void)
{
	//Test1();
	Test2();
	
	Func fn;
	fn.CALL = Test3;
	fn.FirstAddr = fn.CALL;
	printf("Addr: %p\n", fn.FirstAddr);
	fn.CALL();
	fn.iCALL = Sum;	
	fn.FirstAddr = fn.iCALL;
	printf("Addr: %p\n", fn.FirstAddr);
	printf("Value : %d\n", fn.iCALL(1982, 2008));
	fn.fCALL = GetPI;
	fn.FirstAddr = fn.fCALL;
	printf("Addr: %p\n", fn.FirstAddr);
	printf("PI : %.6f\n", fn.fCALL());
	fn.cCALL = GetLittle;
	printf("Little: %c\n", fn.cCALL());
	fn.strCALL = GetAuthor;
	printf("Author: %s\n", fn.strCALL());
	
	Test4();
	int a, b;
	a = 22, b = 7;
	Calc(a, b, '+');
	Calc(a, b, '-');
	Calc(a, b, '*');
	Calc(a, b, '/');
	Calc(a, b, '%');
	Calc(a, b, '&');
	
	fn.CALL = AddrArrs;
	fn.CALL();
	printf("fn.CALL addr: %p, AddrArrs addr: %p\n", 
		fn.CALL, AddrArrs);
	int i, k = 0;
	char *opt[10] = {
		"Add", "Dec", "Mul", "Div", "Mod"
	};
	unsigned char *Ptr = (unsigned char *)Add;
	for (i=0; i<180+45+2; i++) {
		printf(" %02X ", *Ptr);		
		if (*Ptr == 0xC3) {			
			printf("\tfunction: %s(...) \n\n", opt[k]);
			k++;			
		}
		Ptr++;		
	}
	
	printf("%c\n", GetNeg(127));
	printf("%c\n", GetNeg(128));
	printf("%c\n", GetNegE(32767));
	printf("%c\n", GetNegE(32768));
	printf("%c\n", GetNegEx(pow(2, 30)));
	printf("%c\n", GetNegEx(pow(2, 30)+1));	
	//printf("%d\n", __EAX__);
	
	return 0;
}
