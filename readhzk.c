#include <stdio.h>
#include <stdlib.h>
#include <STRING.H>
#include <locale.h>
#include <time.h>
#include <wchar.h>

#define A		1410
#define Deng	1922

void Test8(void)
{
	setlocale(LC_ALL, "chs");
	//wchar_t wc = L'жа';
	//wprintf(L"%c\n",wc);
}

void Test9(void)
{
	char buf[32];
	puts("Enter name: ");
	scanf("%s", buf);
	printf("Your name is %s\n", buf);
	puts("Enter addr: ");
	scanf("%s", buf);
	printf("Your address: %s\n", buf);
	fflush(stdin);
	puts("Enter tele: ");	
	gets(buf);
	printf("Your tele: %s\n", buf);
}

void Get332Mo(FILE *fp, long int pos)
{
	int i;
	unsigned char mo[32];
	fseek(fp, pos * 32L, SEEK_SET);
	fread(mo, 32, 1, fp);
	for (i=0; i<32; i++) {
		if (i%16 == 0)
			puts("");
		printf("%02X ", mo[i]);
	}
	
	puts("");
}

int GetBit(unsigned char ch, int n)
{
	return (ch>>n)&1;
}

void ViewHZ(FILE *fp, long int pos,char ch, char mask)
{
	unsigned char mo[32];
	register int i, k;
	fseek(fp, pos*32L, SEEK_SET);
	fread(mo, 32, 1, fp);	
	
	printf("\t");
	for (i=0; i<32; i++) {
		//printf("\t");
		for (k=0; k<8; k++) {
			//if (GetBit(mo[i], 7-k))
			if ((mo[i]>>(7-k))&1)
				printf("%c", ch);			
			else
				printf("%c", mask);			
		}
		if ((i+1)%2==0)
			printf("\n\t");		
	}	
	printf("\n\n");
}

int main(void)
{
	FILE *fp;
	fp = fopen("HZK16", "rb");
	if (fp == NULL) {
		puts("File not open");
		return -1;
	}
	
	long int pos = Deng; 
	Get332Mo(fp, pos); 
	ViewHZ(fp, pos, '*', ' ');
	
	Get332Mo(fp, pos); 
	ViewHZ(fp, pos, '@', '.');
	
	pos = A;
	Get332Mo(fp, pos); 
	ViewHZ(fp, pos, '.', ' ');	
	
	int i, r;
	srand((unsigned int)time(NULL));
	for (i=0; i<6; i++) {
		r = rand()%4000;
		ViewHZ(fp, A + r, 'o', ' ');		
	}
	
	Test8();
	
	fclose(fp);
	fflush(stdin);
	
	Test9();
	
	getchar();
	return 0;
}
