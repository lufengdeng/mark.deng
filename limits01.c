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
	printf("%d\n", CHAR_BIT);  //һ��ASCII�ַ�����  8
	printf("%d\n", SCHAR_MIN); //�ַ�����Сֵ      -128
	printf("%d\n", SCHAR_MAX); //�ַ������ֵ       127     
	printf("%d\n", UCHAR_MAX); //�޷����ַ������ֵ  255
	printf("%d\n", CHAR_MIN);  //                 -128
	printf("%d\n", CHAR_MAX);  //                  127
	// char �ַ��������Сֵ�����char�ַ�������ʾ�з������������ǵ�ֵ�͸��з���
	// ����һ���� ����char�ַ�����Сֵ����0�����ֵ�����޷���char�ַ������ֵ��
	
	printf("%d\n", MB_LEN_MAX); //һ���ַ���ռ����ֽ���  8
	printf("%d\n", SHRT_MIN);   //��С������            -32768
	printf("%d\n", SHRT_MAX);   //��������            32767
	printf("%d\n", USHRT_MAX);  //����޷��Ŷ�����       65535
	printf("%d\n", INT_MIN);    //��С����              -2147483648
	printf("%d\n", INT_MAX);    //�������              2147383647
	printf("%u\n", UINT_MAX);   //����޷�������         4294967295
	  
	printf("%ld\n", LONG_MIN);  //��С������            -2147483648
	printf("%ld\n", LONG_MAX);  //�������             2147383647
	printf("%lu\n", ULONG_MAX); //�޷��ų�����           4294967295
	
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
