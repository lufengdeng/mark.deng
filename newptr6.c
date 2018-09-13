#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define echo	printf
#define begin	{
#define end		}

typedef void (*Func)();

void Test1(void);
void Test2(void);
__cdecl static void Calln(void);

// _cdecl == __cdecl == _stdcall

int main(void)
begin
	echo("Hello c\n");
	Test1();
	Calln();
	Test2();
	return 0;
end

_cdecl static void Calln(void)
{
	static int count = 1;
	int *p = &count;
	printf("%p %s run %d count\n", p, __func__, *p);
	count++;
	if (count > 9) return;
	Calln();
}

void Test2(void)	
{
    int i, j;
    puts("Begin use");
    i = 100;
    printf("i = %d\n", i); // i��ʼֵΪ100
    printf("i++ = %d\n", i++); // ִ��i++��ʾ���i��ǰֵ��������1
    printf("i = %d\n", i); // �������1���ֵ
    j = 200;
    printf("++j = %d\n", ++j);
    printf("j = %d\n", j);
}

void Test1(void)
{
	int num = 1982;
	int *ptr, **p2, ***p3;
	ptr = NULL;
	ptr = &num;
	p2 = &ptr;
	p3 = &p2;
	printf("ptr: %p\t*ptr: %d\n", ptr, *ptr);
	printf("p2: %p\t**p2: %d\n", p2, **p2);
	printf("p3: %p\t***p3: %d\n", p3, ***p3);
	printf("&*ptr addr: %p\n", &*ptr);		// &*ptr  == ptr == &num
	                                        //  ----
	                                        //    1
	                                        // -----
	                                        //    2
	printf("&**p2 addr: %p\n", &**p2);		// &**p2  == p2 == &num
	printf("&****p3 addr: %p\n", &***p3);	// &***p3 == p3 == &num
	*ptr = num;
	p2 = (void *)ptr;  // ǿתΪͨ��ָ������(void *)��Ͳ���ʾ���棺
	p3 = (void *)p2;   // ���Ͳ�ƥ����, �κ����͵�ָ��תΪvoid *�;Ͳ��ᾯ����
	printf("ptr: %p\n", ptr);
	printf("p2: %p\n", p2);
	printf("p3: %p\n", p3);
	printf(" ptr == p2 ? %d\n", (void *)ptr == (void *)p2);
	printf(" ptr == p2 ? %d\n", (void *)p2 == (void *)p3);
	printf(" ptr == p2 ? %d\n", (void *)p3 == (void *)ptr);
	
	//printf(" *ptr == **p2 ? %d\n", *ptr == **p2);
	/*if (*ptr == **p2) 
		puts("Equal");
	else
		puts("Not equal");*/
	
	// ָ�����Ϳ��Ա�ַ�� ���Ǳ������������Ͳ����Ա�ַ�����ǳ���
	// const����ָ��Ͳ��ܱ�ַ��, ���ͱ���˳���
	//int ns[]; // ���������������ʱ��[]����ָ������Ԫ�ظ���
	//int ns[10];
	static int ns[10];  // �ĳ�static�͵��������Զ���ʼ�±��ֵȫΪ0
	int i;
	for (i=0; i<10; i++)
		printf("ns[%d] = %d\n", i, ns[i]); // ����û�г�ʼ����ֵ�������
	int *p ;//= (int *)0;
	if (p) 
		puts("p is not null");
	else
		puts("p is null");
	static int *pp;  // static��ָ���Զ���ʼֵΪNULL
	if (pp) 
		puts("p is not null");
	else
		puts("p is null");
		
	int numbers[10];
	int *ptr2 = numbers;
	if (numbers == ptr2) 
		puts("Equal");
	else
		puts("Not equal");
	
	char *str = NULL;
	printf("str addr: %p\n", str);
	str = "Hello World";
	printf("str addr: %p\n", str);
	puts(str);
	str = "The is demo";
	printf("str addr: %p\n", str);
	puts(str);
	str = "Have a good time";
	printf("str addr: %p\n", str);
	puts(str);
	const char *strA;
	strA = "This string not change";
	puts(strA);
	strA = "New string not use";
	puts(strA); // gcc ��Ȼ��ȷ���룬��㲻�� ����ָ��Ҳ���Ա�ַ???
	strA = "New 2";
	puts(strA);
	const char *strB = {"strB string define"}; // ����ʱ�Ͷ�����Լ�{}
	printf("strB addr: %p\n", strB);	// 403118
	puts(strB);	
	//strB = {"New string"};  // ��ʱ���ܼ�{}
	strB = "New strB";	
	printf("strB addr: %p\n", strB); 	// 40313a ��ַ��, ��ַ�����ı�
	puts(strB);
	char const* strC = "use strC";
	printf("strC addr: %p\n", strC);
	puts(strC);
	strC = "new strc";
	printf("strC addr: %p\n", strC);
	puts(strC);
	char name[] = "fengdos";
	printf("name addr: %p\n", name);
	puts(name);
	//name = "author";  // ��������������ֵ
	strcpy(name, "author");
	printf("name addr: %p\n", name); // ��ַ���������ı�
	puts(name);
	for (i=0; i<strlen(name); i++)
		putchar(name[i]);
		
	puts("-----------------");
	for (i=0; i<strlen(name); i++) {
		// putchar(*(name++));	 // error
		putchar(*(name+i));  // ok
	}
	
	printf("\n*** The function \"%s()\" is out stack ***", __func__);
	printf("\n*** %s() name length is %d bytes\n", __func__, 
		strlen(__func__));
}
