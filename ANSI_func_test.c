#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern	char _cdecl _ctype[];	 /* Character type array */
//char buff[];

static void ShowHex(char *p, int n)
{
	int i;
	puts("");
	for (i=0; i<n; i++) {
		printf(" %02X ", (unsigned char)*p++);
		if ((i+1)%16==0) 
			puts("");
	}
	puts("");
}

void FgetChar(void)
{
	int ch;
	// ch = fgetchar();  // fgetchar not ANSI function
	ch = fgetc(stdin);
	printf("ch = %d\n", ch);
	printf("\n");
	fprintf(stdout, "%d\n", 'A');
	ch = fgetc(stdout);
	//ch = fgetc(fprintf(stdout, "%d\n", 'A');)
	printf("ch: %d\n", ch);	
	printf("sizeof(FILE): %d\n", sizeof(FILE));
	FILE *fp;//, stdin, stdout, stderr;
	printf("sizeof(fp): %d\n", sizeof(fp)); // 任何指针在win32下都占4字节
	printf("sizeof(stdin): %d\n", sizeof(stdin));
	printf("sizeof(stdout): %d\n", sizeof(stdout));
	printf("sizeof(stderr): %d\n", sizeof(stderr));
	fp = (FILE *)malloc(1024);
	if (!fp) {
		puts("Out of memory");
		exit(-1);
	}
	printf("fp addr: %p\n", fp);
	ShowHex((void *)fp, 112);
	free(fp);
	printf("fp addr: %p\n", fp);
	fp = fopen("malloc09.exe.stackdump", "rb");
	if (!fp) {
		puts("File not open..");
		exit(1);
	}
	printf("fp addr: %p\n", fp);
	puts("------------------------------");
	ShowHex((void *)fp, sizeof(FILE)); // 显示文件缓冲区的当前内容
	fclose(fp);
	ShowHex((void *)fp, sizeof(FILE)); // 关闭文件后缓冲区的内容
	//fgetpos(
	printf("Max open file number: %d\n", FOPEN_MAX);
	printf("Max filename size: %d\n", FILENAME_MAX);
	printf("Buff size: %d\n", BUFSIZ);
	printf("tmp : %d\n", TMP_MAX);	
}

void AnyKey(void)
{
	puts("Anykey..");
	fgetc(stdin);
}

int main(void)
{
	AnyKey();
	FgetChar();
	return 0;
}

/*
 * 定义于头文件 <stdio.h>
stdin
stdout
stderr
	与标准输入流关联的 FILE* 类型表达式
与标准输出流关联的 FILE* 类型表达式
与标准错误输出流关联的 FILE* 类型表达式
(宏常量)
EOF
	int 类型的负值整数常量表达式
(宏常量)
FOPEN_MAX
	能同时打开的文件数
(宏常量)
FILENAME_MAX
	保有最长受支持文件名所需的字符数组大小
(宏常量)
BUFSIZ
	setbuf()所用的缓冲区大小
(宏常量)
_IOFBF
_IOLBF
_IONBF
	指示全缓冲 I/O 的 setvbuf() 参数
指示行缓冲 I/O 的 setvbuf() 参数
指示无缓冲 I/O 的 setvbuf() 参数
(宏常量)
SEEK_SET
SEEK_CUR
SEEK_END
	指示从文件首开始寻位的 fseek() 参数
指示从文件当前位置开始寻位的 fseek()参数
指示从文件尾开始寻位的 fseek() 参数
(宏常量)
TMP_MAX
TMP_MAX_S

(C11)
	tmpnam 所能生成的最大独有文件数
tmpnam_s 所能生成的最大独有文件数
(宏常量)
L_tmpnam
L_tmpnam_s

(C11)
	保有 tmpnam 结果所需的数组大小
保有 tmpnam_s 结果所需的数组大小
(宏常量)
 * */
