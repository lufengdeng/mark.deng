#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Test1(void);

int main(void)
{
	Test1();
	return 0;
}

void Test1(void)
{
	char *ver;
	ver = (char *)calloc(sizeof(char) , 100);
	//if(!ver) {
	if (NULL == ver) {
		puts("out of memory");
		return;
	}
	// ver = "Have a good time!"; // �˴������ѱ�ַ������ free(ver)�ͻ����
	// ��Ϊ�������ͷŷ�calloc��malloc�����ջ�ڴ�, ��ʱӦ�ø�Ϊ��
	strcpy(ver, "Have a good time!");
	puts(ver);
	//free(ver);
	free(ver);
	
	int *p;
	p = (int *)malloc(0x100 * sizeof(int));
	if (!p) {
		puts("Out of memory!");
		return;
	}
	p[1] = 1982;
	printf("p[1] = %d\n", p[1]);
	int i;
	for (i=0; i<256; i++)
		printf(" %02X ", p[i]);
	free(p);
}
