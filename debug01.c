#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 通过个个开关控制是否显示用户debug调试信息
// 开关1, 显示调试信息:
/*
#ifndef _MY_DEBUG
#define _MY_DEBUG
#endif
*/

// 开关2, 不显示调试信息:
#ifdef _MY_DEBUG
#undef _MY_DEBUG
#endif

#ifdef __cplusplus
#error "亲，您当前使用的是C++编译器噢！"
#endif

// Not use
/*#if defined(__cplusplus)
  puts("Now use C++ compiler");
#else
  //puts("C");
#endif*/

#if __cplusplus
  #define COMPILER	"C++"
#elif __STDC__
  #define COMPILER  "C"
#else
  #define COMPILER  "Other"
#endif

#define GetMaxEx(a, b) ( ( (a)>(b) ) ? (a) : (b) )

#undef GetMaxEx

#ifndef GetMaxEx
float GetMaxEx(float *a, float *b)
{
#ifdef _MY_DEBUG
	// Here input debug infomation
	puts("Tow number comp max:");
	printf("%f and %f max is %f\n", 
		*a, *b, *a > *b ? *a : *b);
#endif // end of ifdef _MY_DEBUG
	// Here is function return value, not debug infomation
	return *a > *b ? *a : *b;
}
#endif // end of ifndef GetMaxEx

const char* FuncA(void)
{
	puts("Hi, girl");
	//return (char *)__func__;
	return __func__;
}

int main(void)
{
	float ia, ib;
	ia = 1982, ib = 1983;
	float *pa, *pb;
	pa = &ia, pb = &ib;
	
	printf("Now use %s compiler.\n", COMPILER);

	// 通过个个开关控制是否显示用户debug调试信息
		
#ifdef _MY_DEBUG	
	printf("%d\n", (int)(GetMaxEx(pa, pb)));
	puts("\n\n");
#else
	printf("Max is %d\n", (int)(GetMaxEx(pa, pb)));
#endif	

#ifdef GetMaxEx
	puts("GetMaxEx function define");
#else
	puts(__func__);
#endif

	char buf[32];
	const char *func_name;
	func_name = buf;
	// buf = FuncA(); // error: assignment to expression with array type
	strcpy(buf, FuncA()); // or: func_name = FuncA();
	printf("\nCall function name is %s  [%s]\n", func_name, buf);
	const char *p = NULL;  // const指针不能动态分配内存
	char *Ptr = (char *)p; // 强转const char *指针为char *
	printf("p addr: %p\tPtr addr: %p\n", p, Ptr);
	Ptr = (char *)malloc(sizeof(char) * 32); // 通过malloc从系统自由存储区分配一块称为堆的空间
	if (!Ptr) { // or: if (Ptr == NULL) {
		puts("Out of memroy");
		return -1;
	}
	printf("p addr: %p\tPtr addr: %p\n", p, Ptr);
	strcpy(Ptr, FuncA());
	strcat(Ptr, "()");		
	printf("\n..Call function name is %s\n", Ptr);
	printf("p addr: %p\tPtr addr: %p\n", p, Ptr);
	free(Ptr);	// 将malloc申请的堆内存返还给系统自由存储区
	printf("p addr: %p\tPtr addr: %p\n", p, Ptr);
	
	return 0;
}
