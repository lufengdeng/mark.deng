#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define private	static

/*//*/ extern float GetMaxF(float, float);
//extern char* GetMsg(void);

private char* GetVersion(void)
{
	return "Version: 1.0.21";
}

int main(void)
{
	float e, f;
	char *ver;
	ver = (char *)malloc(sizeof(char) * 32);
	if (!ver)
		puts("Out of memory");
	printf("addr: %p\n", ver);  // addr: 0x200296a0

	//ver = GetVersion();  // ����, ָ���ַ��ָ��ջ�ڴ棬
	// ����free(ջ�ڴ�)���򱨴� Ӧ�ø�Ϊ:
	strcpy(ver, GetVersion()); 
	printf("new addr: %p\n", ver); // new addr: 0x403060
	puts(ver);
	free(ver); // freeֻ���ͷŶ��ڴ�(���� ��malloc��calloc������ڴ�)
	
	/*char buff[32], *ver;
	ver = buff;
	ver = GetVersion();
	puts(ver);*/
	
	puts("Now call other lib function..");
	e = 3.1415, f = 3.1416;
	printf("%f and %f max is %f\n", e, f, GetMaxF(e, f));
	printf("Call function in %d\n", (int)GetMsg());
	//char *msg[5];
	//ShowInfo(msg);
	//puts(msg[1]);
	return 0;
}
