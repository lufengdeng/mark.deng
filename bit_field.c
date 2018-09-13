#include <stdio.h>
#include <string.h>

FILE *fpTo, *fpForm;

#ifdef __STDIO_H__
typedef struct  {
        short           level;          /* fill/empty level of buffer */
        unsigned        flags;          /* File status flags    */
        char            fd;             /* File descriptor      */
        unsigned char   hold;           /* Ungetc char if no buffer */
        short           bsize;          /* Buffer size          */
        unsigned char   *buffer;        /* Data transfer buffer */
        unsigned char   *curp;          /* Current active pointer */
        unsigned        istemp;         /* Temporary file indicator */
        short           token;          /* Used for validity checking */
} FILE;                                 /* This is the FILE object */
#endif

// *****  C中预处理还可以当注释块使用 ***** 不满足条件则不检查块中的内容
#ifdef __FENGDOS_H__
  缓冲区 "满" 或 "空" 的程序
  文件状态标志
  文件描述符
  如无缓冲区则不读取字符
  缓冲区的大小
  数据缓冲区的位置
  指针 当前的指向
  临时文件 指示器
  有效性检查
#endif

struct tagHead {
	char OK: 1;
};

struct tagBool {
	unsigned False: 1;
	unsigned True: 1;
} Boolean;

// 声明一个邮件结构
struct tagMail {
	unsigned FLAG: 1;	// FLAG = 0, 没有新邮件, = 1 有新邮件
	unsigned TITLE: 3;  // 邮件标题(代号):  000b ~ 111b 0~7
	unsigned MSG: 12;	// 邮件正文(密语): 规则待定
};

typedef struct tagEmail {
	int id;				// 邮件编号
	char title[32];		// 邮件标题
	char date_time[20]; // format: 2018-09-28:12:36:57
	char to[32];	// 收件人, format: fengdos@163.com
	char form[32];	// 发件人, format: wd3email@tom.com
	char text[1024]; // 邮件正文ASCII码文本
} Email;

struct tagFlags {
	unsigned CF:1;	// 进位位
	unsigned :1;	// Unuse
	unsigned PF:1;	// 奇偶位
	unsigned :1;	// Unuse
	unsigned AF:1;	// 辅助进位位
	unsigned :1;   	// Unuse
	unsigned ZF:1;  // 零值位
	unsigned SF:1;  // 符号位
	unsigned TF:1;  // 单步标志位
	unsigned IF:1;  // 中断允许位
	unsigned DF:1;  // 方向位
	unsigned OF:1;  // 溢出位
	unsigned :4;	// Unuse	
} PSW;  // 程序状态字结构 16 bit

Email e;
typedef struct tagFlags Flags;

void SIZE_PSW(void)
{
	printf("PSW size:  %d\n", sizeof(PSW));  // 4 bytes
}

struct tagFlags GetPSWbitEx(struct tagFlags x)
{
	return x;
}

Flags GetPSWbit(Flags x)
{
	return x;
}

void RESET(void)
{
	PSW.CF = 0;
	PSW.PF = 0;
	PSW.AF = 0;
	PSW.ZF = 0;
	PSW.SF = 0;
	PSW.TF = 0;
	PSW.IF = 0;
	PSW.DF = 0;
	PSW.OF = 0;
}

void SET(void)
{
	PSW.CF = 1;
	PSW.PF = 1;
	PSW.AF = 1;
	PSW.ZF = 1;
	PSW.SF = 1;
	PSW.TF = 1;
	PSW.IF = 1;
	PSW.DF = 1;
	PSW.OF = 1;
}

void NOT(void)
{
	PSW.CF = !PSW.CF;
	PSW.PF = !PSW.PF;
	PSW.AF = !PSW.AF;
	PSW.ZF = !PSW.ZF;
	PSW.SF = !PSW.SF;
	PSW.TF = !PSW.TF;
	PSW.IF = !PSW.IF;
	PSW.DF = !PSW.DF;
	PSW.OF = !PSW.OF;
}

void STATUS(void)
{
	printf("CF:  %d\n", PSW.CF);
	printf("PF:  %d\n", PSW.PF);
	printf("AF:  %d\n", PSW.AF);
	printf("ZF:  %d\n", PSW.ZF);
	printf("SF:  %d\n", PSW.SF);
	printf("TF:  %d\n", PSW.TF);
	printf("IF:  %d\n", PSW.IF);
	printf("DF:  %d\n", PSW.DF);
	printf("OF:  %d\n\n", PSW.OF);
}

// 进位位复位指令
void CLC(void)
{
	PSW.CF = 0;
}

// 进位位置位指令
void STC(void)
{
	PSW.CF = 1;	
}

// 进位位求反指令
void CMC(void)
{
	PSW.CF = !PSW.CF;
}

// 方向标志复位指令
void CLD(void)
{
	PSW.DF = 0;	
}

// 方向标志置位指令
void STD(void)
{
	PSW.DF = 1;
}

// 中断标志复位指令
void CLI(void)
{
	PSW.IF = 0;
}

// 中断标志置位指令
void STI(void)
{
	PSW.IF = 1;
}

int GetSign(int num)
{
	if ((num<<15)&1)
		return -1;
	else
		return 0;
}

void Test1(void)
{
	STC();
	STI();
	struct tagFlags f;
	f = GetPSWbitEx(PSW);
	printf("f.IF  %d\n", f.IF);
}

int MainCtrl(void)
{
	SIZE_PSW();
	STATUS();
	RESET();
	STATUS();
	NOT();
	STATUS();
	RESET();
	Test1();
	STATUS();
	return 0;
}

int WriteMail(void)
{
	printf("Write Email, please input:\n");
	printf("ID: ");
	scanf("%d", &e.id);
	printf("Title: ");
	//scanf("%s", e.title);
	getchar();
	gets(e.title);
	printf("Date: ");
	scanf("%s", e.date_time);
	printf("To: ");
	scanf("%s", e.to);  // scanf 以空格或制表符或回车键结束输入
	printf("Form: ");
	scanf("%s", e.form);
	printf("Text(Max: 1024 bytes): ");
	//scanf("%s", e.text);
	//fflush(stdin);
	getchar();     // 此处必须放一个getchar否则直接不输入e.text
	gets(e.text);  // gets可以使用空格, 它是以回车键结束输入的
	return 0;
}

int SendMail(void)
{
	fpForm = fopen("to_mail.txt", "wb");
	if (!fpForm) {
		puts("File not write");
		return -1;
	}
	
	WriteMail();
	fwrite(&e, sizeof(Email), 1, fpForm);
	fclose(fpForm);
	return 0;
}

int ShowMail(void)
{
	printf("ID: %d\n", e.id);
	printf("Title: %s\n", e.title);
	printf("Date: %s\n", e.date_time);
	printf("To: %s\n", e.to);
	printf("Form: %s\n", e.form);
	printf("Text:\n%s\n", e.text);
	return 0;
}

int ReadMail(void)
{
	fpForm = fopen("to_mail.txt", "rb");
	if (!fpForm) {
		puts("File not write");
		return -1;
	}
	fread(&e, sizeof(Email), 1, fpForm);
	ShowMail();
	fclose(fpForm);
	return 0;
}

int Menu(void)
{
	char key;
	do {
		printf("\n");
		printf(" **************** MENU ***************\n");
		printf("  1. Send email\n");
		printf("  2. Read email\n");
		printf("  0. quit system\n");
		printf(" -------------------------------------\n");
		printf(" please choice: 1, 2, or 0 : ");
		//fflush(stdout);
		key = getchar();
		switch(key) {
			case '0': goto Finish;
			case '1': SendMail(); break;
			case '2': ReadMail(); break;
			default: puts("\nChoice error!"); break;
		}
	} while('0' != key);
Finish:
	printf("\n");
	return 0;
}

#ifndef _ONLY_RUN_ONE
#define _ONLY_RUN_ONE
void OnlyRunOne(void)
{
#ifndef _ONLY_RUN_ONE
	static int c;
	printf("The function only run one [%d]\n", ++c);
#endif
}
#endif

// ok
int* OnlyRunA(void)
{
	// int c = 0;  // 使用非static变量就无法控制函数的代码只执行一次
	static int c;  // 可控只执行一次代码而不管函数被调用多少次
	if (c<1)
		printf("Call function %s() count: %d\n", __func__, ++c);
	return &c;
}

int main(void)
{
	MainCtrl();
	printf("sizeof(tagHead): %d\n", sizeof(struct tagHead));
	Boolean.False = 1;
	printf("Boolean.False: %d\n", Boolean.False);
	struct tagMail mail;
	mail.FLAG = 1;
	mail.TITLE = 07;
	mail . MSG = 077;
	printf("%d\t%d\t%d\n", mail.FLAG, mail.TITLE, mail.MSG);
		
	Menu();
	
	int i;
	for (i=0; i<9; i++)
		OnlyRunOne();
		
	int *Ptr;
	for (i=0; i<9; i++)
		Ptr = OnlyRunA();
		
	OnlyRunA();
	printf("static var addr: %p [ %d ]\n", Ptr, *Ptr);
	
	*Ptr = 0;
	printf("static var addr: %p [ %d ]\n", Ptr, *Ptr);
	for (i=0; i<9; i++)
		Ptr = OnlyRunA();  // *Ptr 置为 0 后 OnlyRunA又可以执行一次了
	
	return 0;
}
