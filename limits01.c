#include <stdio.h>
#include <limits.h>

//#ifndef _W32API_H
//#define _W32API_H
//#pragma GCC	system_header
//#endif

#if defined(__GNUC__)
#define COMPILER	"gnu c"
#else
#define COMPILER	"other c"
#endif

#if defined(__STRICT_ANSI__)
#define STDCIS	"ANSI"
#else
#define STDCIS	"NO ANSI"
#endif

#if defined(__ANSI__)
#define STD_C_IS	"ANSI"
#else
#define STD_C_IS	"NO ANSI"
#endif

#if defined(__cdecl)
#define IS_CALL	"IS C CALL"
#else
#define IS_CALL "IS C++ CALL"
#endif

int Test1(void)
{
	printf("%d\n", CHAR_BIT);  //一个ASCII字符长度  8
	printf("%d\n", SCHAR_MIN); //字符型最小值      -128
	printf("%d\n", SCHAR_MAX); //字符型最大值       127     
	printf("%d\n", UCHAR_MAX); //无符号字符型最大值  255
	printf("%d\n", CHAR_MIN);  //                 -128
	printf("%d\n", CHAR_MAX);  //                  127
	// char 字符的最大最小值，如果char字符正被表示有符号整数。它们的值就跟有符号
	// 整数一样。 否则char字符的最小值就是0，最大值就是无符号char字符的最大值。
	
	printf("%d\n", MB_LEN_MAX); //一个字符所占最大字节数  8
	printf("%d\n", SHRT_MIN);   //最小短整型            -32768
	printf("%d\n", SHRT_MAX);   //最大短整形            32767
	printf("%d\n", USHRT_MAX);  //最大无符号短整型       65535
	printf("%d\n", INT_MIN);    //最小整型              -2147483648
	printf("%d\n", INT_MAX);    //最大整形              2147383647
	printf("%u\n", UINT_MAX);   //最大无符号整型         4294967295
	  
	printf("%ld\n", LONG_MIN);  //最小长整型            -2147483648
	printf("%ld\n", LONG_MAX);  //最大长整型             2147383647
	printf("%lu\n", ULONG_MAX); //无符号长整型           4294967295
	
	return 0;
}

int main(void)
{
	Test1();
	printf("%s\n", COMPILER);
	printf("%s\n", STDCIS);
	printf("%s\n", STD_C_IS);
	printf("%s\n", IS_CALL);
	//const void *p = (const void *)0x40184a80;
	//printf("p addr: %p  %d\n", (char *)p, *(char *)p);
	return 0;
}
