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

// *****  C��Ԥ�������Ե�ע�Ϳ�ʹ�� ***** �����������򲻼����е�����
#ifdef __FENGDOS_H__
  ������ "��" �� "��" �ĳ���
  �ļ�״̬��־
  �ļ�������
  ���޻������򲻶�ȡ�ַ�
  �������Ĵ�С
  ���ݻ�������λ��
  ָ�� ��ǰ��ָ��
  ��ʱ�ļ� ָʾ��
  ��Ч�Լ��
#endif

struct tagHead {
	char OK: 1;
};

struct tagBool {
	unsigned False: 1;
	unsigned True: 1;
} Boolean;

// ����һ���ʼ��ṹ
struct tagMail {
	unsigned FLAG: 1;	// FLAG = 0, û�����ʼ�, = 1 �����ʼ�
	unsigned TITLE: 3;  // �ʼ�����(����):  000b ~ 111b 0~7
	unsigned MSG: 12;	// �ʼ�����(����): �������
};

typedef struct tagEmail {
	int id;				// �ʼ����
	char title[32];		// �ʼ�����
	char date_time[20]; // format: 2018-09-28:12:36:57
	char to[32];	// �ռ���, format: fengdos@163.com
	char form[32];	// ������, format: wd3email@tom.com
	char text[1024]; // �ʼ�����ASCII���ı�
} Email;

struct tagFlags {
	unsigned CF:1;	// ��λλ
	unsigned :1;	// Unuse
	unsigned PF:1;	// ��żλ
	unsigned :1;	// Unuse
	unsigned AF:1;	// ������λλ
	unsigned :1;   	// Unuse
	unsigned ZF:1;  // ��ֵλ
	unsigned SF:1;  // ����λ
	unsigned TF:1;  // ������־λ
	unsigned IF:1;  // �ж�����λ
	unsigned DF:1;  // ����λ
	unsigned OF:1;  // ���λ
	unsigned :4;	// Unuse	
} PSW;  // ����״̬�ֽṹ 16 bit

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

// ��λλ��λָ��
void CLC(void)
{
	PSW.CF = 0;
}

// ��λλ��λָ��
void STC(void)
{
	PSW.CF = 1;	
}

// ��λλ��ָ��
void CMC(void)
{
	PSW.CF = !PSW.CF;
}

// �����־��λָ��
void CLD(void)
{
	PSW.DF = 0;	
}

// �����־��λָ��
void STD(void)
{
	PSW.DF = 1;
}

// �жϱ�־��λָ��
void CLI(void)
{
	PSW.IF = 0;
}

// �жϱ�־��λָ��
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
	scanf("%s", e.to);  // scanf �Կո���Ʊ����س�����������
	printf("Form: ");
	scanf("%s", e.form);
	printf("Text(Max: 1024 bytes): ");
	//scanf("%s", e.text);
	//fflush(stdin);
	getchar();     // �˴������һ��getchar����ֱ�Ӳ�����e.text
	gets(e.text);  // gets����ʹ�ÿո�, �����Իس������������
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
	// int c = 0;  // ʹ�÷�static�������޷����ƺ����Ĵ���ִֻ��һ��
	static int c;  // �ɿ�ִֻ��һ�δ�������ܺ��������ö��ٴ�
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
		Ptr = OnlyRunA();  // *Ptr ��Ϊ 0 �� OnlyRunA�ֿ���ִ��һ����
	
	return 0;
}
