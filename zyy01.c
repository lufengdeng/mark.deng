#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funca.h"

/*
 * static存储类只能是局部变量或全局变量，而不能是函数形参及
 * 构造类型中的变量类型
 * */

//auto xxxx; // error: file-scope declaration of 'xxxx' specifies 'auto'
static int xxxx, xxx;
int yyyy;
static int xx, x2;
float zzzz;
static int x3, x4;
double z2;

static int count_n;

/* 静态结构声明及定义, 如指明了变量名但在整个程序中未使用则警告 */
static struct tagRect {
	int buttom, top;
	int width, height; // static结构所有元素自动初始化为0
} Rect;

// typedef static struct tagRect RECT;  // error
typedef struct tagRect RECT;

/* 静态全局变量 声明及初始化 */
static int numa, numb = 1982;
/* 外部全局变量 只表示引用其它库中声明或定义的全局变量,防止文件间声明冲突,
 * 且不再重新分配内存空间, 便在使用时如没有链接外部库或外部库存未声明及定义
 * 此变量时,将在链接过程中出错 */
extern int width, height;
int width, height;  // 自动初始化为0, 可以跟外部变量生名, 编译能通过

#ifdef _FUNCA_H
/* 引用外部函数声明, 也可与文件内部函数同名同参, 但链接外部函数时将出错 */
extern void Swap(int *a, int *b);

#else
/* 静态函数定义 (并不是什么返回静态值的函数, 而是声明为内部函数) */
static void Swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
#endif

static int Count(void)
{
	/* 静态局部变量声明 */
	static int c; // 函数内部可见,但有固定的内存位置, 其值生命周期同全局变量
	return ++c;
}

void CountEx(void)
{
	count_n++;
}

static float GetMaxEx(float a, float b)
{
	return a<b ? b : a;
}

// 内存模型函数
int 
PtrInfo(void *ptr)
{
	//char *ptr = (char *)PTR;
	if (ptr == NULL)
		return -1;
	
	printf("\n");
	printf(" *Ptr Memory Infomation\n");
	printf("          +------------------------------+\n");
	printf("          |  %24s    |\n", " ");
	printf(" Value:   |  %p  ---> %-10d   |  ( %-x ) ( %-o )\n", 
		&ptr, *(int *)ptr, *(int *)ptr, *(int *)ptr);
	printf("          |  %24s    |\n", " ");
	printf("          +------------------------------+\n");
	
	printf(" Ptr addr:   %p\n", ptr);
	//printf("\n");
	
	return 0;
}

int 
PtrInfoEx(void *ptr, char *title)
{
	//char *ptr = (char *)PTR;
	if (ptr == NULL)
		return -1;
	
	printf("\n");
	printf(" %s Memory Infomation\n", title);
	printf("          +------------------------------+\n");
	printf("          |  %24s    |\n", " ");
	printf(" Value:   |  %p  ---> %-10d   |  ( %-x ) ( %-o )\n", 
		&ptr, *(int *)ptr, *(int *)ptr, *(int *)ptr);
	printf("          |  %24s    |\n", " ");
	printf("          +------------------------------+\n");
	
	printf(" Ptr addr:   %p\n", ptr);
	//printf("\n");
	
	return 0;
}

void Test1(void)
{
	Bool view = False;
	printf("view: %s\n", view == 0 ? "False" : "True");
	view = True;
	printf("view: %s\n", view == 0 ? "False" : "True");
	view = !True;
	printf("view: %s\n", view == 0 ? "False" : "True");
	//auto int a = 1982; // or:
	auto a = 1982;
	int b = 2008;
	printf("a = %d [%p]\n", a, &a);
	printf("b = %d [%p]\n", b, &b); // 内存是紧挨着的
	register i = 100, j = 200;
	//printf("i = %d [%p]\tj = %d\n", i, j, &i); 
	//error: address of register variable 'i' requested
	printf("i = %d\tj = %d\n", i, j); 
	printf("xxxx = %d [%p]\n", xxxx, &xxxx);
	printf("xxx = %d [%p]\n", xxx, &xxx);
	printf("yyyy = %d [%p]\n", yyyy, &yyyy);
	printf("xx = %d [%p]\n", xx, &xx);
	printf("x2 = %d [%p]\n", x2, &x2);
	printf("zzzz = %f [%p]\n", zzzz, &zzzz);
	printf("x3 = %d [%p]\n", x3, &x3);
	printf("x4 = %d [%p]\n", x4, &x4);
	printf("z2 = %llf [%p]\n", z2, &z2);
}

void MainCtrl(void)
{
	printf("static int numa = %d\taddr: %p\n", numa, &numa);
	printf("static int numb = %d\taddr: %p\n", numb, &numb);
	int ia = 1982, ib = 2008;
	printf("ia = %d\taddr: %p\n", ia, &ia);
	printf("ib = %d\taddr: %p\n", ib, &ib);
	Swap(&ia, &ib);
	printf("  ia = %d\taddr: %p\n", ia, &ia);
	printf("  ib = %d\taddr: %p\n", ib, &ib);
	int i, *p;
	p = (int *)Count;
	i = 10;
	while (i--) {
		printf("Count = %d\taddr: %p\n", Count(), &Count);
	}
	
	//*p = 1999; //  不能通过指针人为修改静态变量的内存数据
	i = 10;
	while (i--) {
		printf("  Count = %d\t  addr: %p\n", Count(), p);
	}
		
	printf("The %s program run in %d line\n", __FILE__, __LINE__);
	//printf("width: %d\theight: %d\n", width, height); // 链接时出错
	printf("Rect.buttom = %d  Rect.top = %d  Rect.width = %d  Rect.width\
		= %d\n", Rect.buttom, Rect.top, Rect.width, Rect.height);
		
	// 当字符串较长时, 可以使用n对双引号分行使用
	printf("Rect.buttom = %d  Rect.top = %d  Rect.width = %d  Rect.width"
		" = %d\n", Rect.buttom, Rect.top, Rect.width, Rect.height);
	RECT rc;
	rc.buttom = 100, rc.top = 50, rc.width = 300, rc.height = 260;
	printf("Rc.buttom = %d  Rc.top = %d  Rc.width = %d  Rc.width"
		"= %d\n", rc.buttom, rc.top, rc.width, rc.height);
		
	/* 当引用外部全局变量和文件内全局变量同名时, 若未链接外部那个obj或lib进
	 * 则文件内全局变量优先, 否则外部全局变量优先(实测)
	 * */
	printf("width: %d\theight: %d\n", width, height); // 640 480
	printf("Get W x H : %d, %d\n", GetWidth(), GetHeight());
	SetWidth(1024); SetHeight(768);
	printf("width: %d\theight: %d\n", width, height);
	printf("Get W x H : %d, %d\n", GetWidth(), GetHeight());
	//SwapEx(&GetWidth(), &GetHeight());  // error!!
	int w, h;
	GetWandH(&w, &h);
	printf("   width: %d\theight: %d\n", w, h);
	int *Pw, *Ph;		
	// w = GetWidth()/*,*/; h = GetHeight();
	w = GetWidth(), /*;*/ h = GetHeight();
	SwapEx(&w, &h);
	// SetWidth(w)/*,*/; SetHeight(h);
	SetWidth(w),/*;*/ SetHeight(h);
	printf("width: %d\theight: %d\n", width, height);
	printf("Get W x H : %d, %d\n", GetWidth(), GetHeight());
	Pw = &w, Ph = &h;
	GetWandH(Pw, Ph);
	printf("   width: %d [%p]\theight: %d [%p]\n", 
		*Pw, Pw, *Ph, Ph);	
	
#ifdef _DEBUG
	puts("DEBUG is define");
#else
	puts("Not define DEBUG");
#endif
	Test1();
	
	char c1 = 'a', c2 = 'A';
	printf("c1 and c2 max is %c\n", (char)GetMaxEx((char)c1, (char)c2));
	int i1 = 1982, i2 = 1983;
	printf("i1 and i2 max is %d\n", (int)GetMaxEx((int)i1, (int)i2));
	unsigned long long int l1 = 4219981234LLU, l2 = 4219981235LLU;
	printf("l1 and l2 max is %llu\n", (unsigned long long int)GetMaxEx((unsigned long long int)l1, 
		(unsigned long long int)l2));
	float f1 = 3.1415, f2 = 3.1416;
	printf("f1 and f2 max is %f\n", GetMaxEx(f1, f2));
	double d1 = 22/7.0, d2 = 22/6.9;
	printf("d1 and d2 max is %lf\n", (double)GetMaxEx((double)d1, (double)d2));		
	
	i = 10;
	while (i--) {
		CountEx();
		printf("Count n is %d\n", count_n);
	}
	printf("Count n is %d\n", count_n);
		
	printf("Count()++ : %d\n", Count());
	//int zoo = Count()++; // error: lvalue required as increment operand
	//printf("Count()++ : %d\n", zoo);
	
	// Block test1
	{
		int ret, numa = 1982;
		int *Ptr = &numa; //NULL;
	
		ret = PtrInfo((int *)Ptr);
		if (ret) {
			puts("Point is NULL");
			return;
		}
		int **P = &Ptr;
		PtrInfoEx((int *)*P, "*P");
		PtrInfoEx((int *)P, "P");
		PtrInfo((int *)&numa);
		/*printf("(int *)*P == *(int *)P ? %s\n",
			(int *)*P == *(int *)P, "True", "False");*/
		if ( (int)((int *)*P) == *(int *)P )
			puts("Equal");
		else
			puts("Not equal");			
	} // end block test1
	
	printf("sizeof(float): %d\n", sizeof(float));
	printf("sizeof(double): %d\n", sizeof(double));
	printf("sizeof(long double): %d\n", sizeof(long double));
	printf("sizeof(int): %d\n", sizeof(int));
	printf("sizeof(short int): %d\n", sizeof(short int));
	printf("sizeof(long int): %d\n", sizeof(long int));
	printf("sizeof(long lont int): %d\n", sizeof(long long int));
	float pi = 3.14;
	printf("pi: %f, sizeof(pi): %d\n", pi, sizeof(pi));
	double dpi = 3.14;
	printf("dpi: %lf, sizeof(dpi): %d\n", dpi, sizeof(dpi));
	long double ldpi = 3.14;
	printf("ldpi: %Lf, sizeof(ldpi): %d\n", ldpi, sizeof(ldpi));
	unsigned long long int lnum = 69LLU;
	// unsigned int a = 1982U;
	// U LU and LLU, f lf and LF
	printf("lnum: %llu, sizeof(lnum): %d\n", lnum, sizeof(lnum));
	// unsigned float ppp = 6.57; // error!!
	
}

int main(void)
{
	MainCtrl();
	return 0;
}
