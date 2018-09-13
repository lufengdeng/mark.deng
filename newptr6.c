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
    printf("i = %d\n", i); // i初始值为100
    printf("i++ = %d\n", i++); // 执行i++表示输出i当前值，并自增1
    printf("i = %d\n", i); // 输出自增1后的值
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
	p2 = (void *)ptr;  // 强转为通用指针类型(void *)后就不提示警告：
	p3 = (void *)p2;   // 类型不匹配了, 任何类型的指针转为void *型就不会警告了
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
	
	// 指针类型可以变址， 它是变量，数组类型不可以变址，这是常量
	// const类型指针就不能变址了, 它就变成了常量
	//int ns[]; // 数组光声明不定义时，[]必须指定数组元素个数
	//int ns[10];
	static int ns[10];  // 改成static型的数组则自动初始下标的值全为0
	int i;
	for (i=0; i<10; i++)
		printf("ns[%d] = %d\n", i, ns[i]); // 数组没有初始化，值是随机的
	int *p ;//= (int *)0;
	if (p) 
		puts("p is not null");
	else
		puts("p is null");
	static int *pp;  // static型指针自动初始值为NULL
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
	puts(strA); // gcc 居然正确编译，真搞不懂 常量指针也可以变址???
	strA = "New 2";
	puts(strA);
	const char *strB = {"strB string define"}; // 声明时就定义可以加{}
	printf("strB addr: %p\n", strB);	// 403118
	puts(strB);	
	//strB = {"New string"};  // 此时不能加{}
	strB = "New strB";	
	printf("strB addr: %p\n", strB); 	// 40313a 变址了, 地址发生改变
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
	//name = "author";  // 出错，不能这样赋值
	strcpy(name, "author");
	printf("name addr: %p\n", name); // 地址并不发生改变
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
