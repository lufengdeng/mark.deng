#include <stdio.h>

int main(void)
{
	int i = 7;
	char* pc = (char*)(&i);
	if(pc[0] == '\x7') // 通过 char 别名使用是OK的
		puts("This system is little-endian");
	else
		puts("This system is big-endian");
 
	float* pf = (float*)(&i);
	float d = *pf; // UB ： float 左值 *p 不能用来访问 int
	
	struct s {int x;};
	struct s f(void) { return (struct s){1982}; }
	struct s s;
    s.x = 1; // OK ：更改 s 的成员
    int n = f().x; // f() 为 struct s 类型表达式
//  f().x = 1; // 错误：此成员访问表达式非左值
	printf("n = %d\n", n);
	
	struct s s2={1}, *p = &s2;
    p->x = 7; // 通过指针更改 s.x 的值
    printf("value: %d\n", p->x); // 打印 7
 
    const struct s sc;
//  sc.x = 3;  // 错误： sc.x 为 const ，不能被赋值
 
    union { int x; double d; } u = {1};
    u.d = 0.1; // 更改 union 的活跃成员
	
	int GetMax(int a, int b) 
	{
		return a>b ? a : b;
	}  // gcc 可以编译, 真搞不懂，main函数内部还可以定义函数
	
	printf("GetMax(1982, 1983): %d\n", GetMax(1982, 1983));
	
	return 0;
}