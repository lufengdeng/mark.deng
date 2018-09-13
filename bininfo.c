#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ShowXchar(FILE *fp, long int pos)
{
	unsigned char buf[4];
	fseek(fp, pos, SEEK_SET);
	fread(buf, 4, 1, fp);
	printf("%c\n", buf[0]);	// view ascii char
	printf("%c%c\n", buf[0], buf[1]);  // view gb-2312 and utf-16 char
	printf("%c%c%c\n", buf[0], buf[1], buf[2]);  // view utf-8 char
	printf("%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3]); // utf-8
	return 0;
}

int ShowUtf8(FILE *fp, long int pos)
{
	unsigned char buf[4];
	fseek(fp, pos, SEEK_SET);
	fread(buf, 4, 1, fp);
	//printf("%c\n", buf[0]);	// view ascii char
	//printf("%c%c\n", buf[0], buf[1]);  // view gb-2312 and utf-16 char
	printf("%c%c%c\n", buf[0], buf[1], buf[2]);  // view utf-8 char
	//printf("%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3]); // utf-8
	return 0;
}

int ShowCharEx(FILE *fp, long int pos, char charset[8])
{
	unsigned char buf[4];
	fseek(fp, pos,SEEK_SET);
	fread(buf, 4, 1, fp);
	
	if (!strcmp(charset, "ascii")) {
		printf("%c", buf[0]);
	}
	else if (!strcmp(charset, "utf-16")) {
		printf("%c%c", buf[0], buf[1]);
	}
	else if (!strcmp(charset, "utf-8")) {
		printf("%c%c%c", buf[0], buf[1], buf[2]);
	}
	else {
		puts("Charset format error!!");
		return -1;
	}
	
	puts("");
	return 0;
}

int ShowFile(FILE *fp, char charset[8])
{
	unsigned char buf[4];
	fseek(fp, 0L,SEEK_SET);
	
	if (!strcmp(charset, "ascii")) {  // gb2312 / ascii
		while (!feof(fp)) {
			buf[0] = fgetc(fp);
			printf("%c", buf[0]);
		}
	}
	else if (!strcmp(charset, "utf-16")) { // unicode 16
		while (!feof(fp)) {
			buf[0] = fgetc(fp);
			buf[1] = fgetc(fp);
			printf("%c%c", buf[0], buf[1]);
		}
	}
	else if (!strcmp(charset, "utf-8")) {
		while (!feof(fp)) {
			buf[0] = fgetc(fp);
			buf[1] = fgetc(fp);
			buf[2] = fgetc(fp);
			printf("%c%c%c", buf[0], buf[1], buf[2]);			
		}
	}
	else {
		puts("Charset format error!!");
		return -1;
	}
	
	puts("");
	return 0;
}

int ShowData(FILE *fp, long int pos)
{
	unsigned char ch;
	short int ssi;
	int si;
	unsigned int usi;
	long long int llsi;
	float ff;
	double df;
	long double ldf;
	fseek(fp, pos, SEEK_SET);
	fread(&ch, sizeof(char), 1, fp);
	printf("8  Bit char:              %c  %d  %o  %x\n", ch, ch, ch, ch);
	
	fseek(fp, pos, SEEK_SET);
	fread(&ssi, sizeof(short int), 1, fp);
	printf("16 Bit signed short int:  %d  %o  %x\n", ssi, ssi, ssi);
	fseek(fp, pos, SEEK_SET);
	fread(&si, sizeof(int), 1, fp);
	printf("32 Bit signed int:        %d  %o  %x\n", si, si, si);
	
	fseek(fp, pos, SEEK_SET);
	fread(&usi, sizeof(int), 1, fp);
	printf("32 Bit unsigned int:      %u  %o  %x\n", usi, usi, usi);
	
	fseek(fp, pos, SEEK_SET);
	fread(&llsi, sizeof(long long), 1, fp);
	printf("%d Bit long long int:     %lld  %llo  %llx\n", sizeof(long long)*8, 
		llsi, llsi, llsi);
	
	fseek(fp, pos, SEEK_SET);
	fread(&ff, sizeof(float), 1, fp);
	printf("32 Bit float:             %f  %e\n", ff, ff);
	fseek(fp, pos, SEEK_SET);
	fread(&df, sizeof(double), 1, fp);
	printf("64 Bit double:            %lf  %e\n", df, df);
	fseek(fp, pos, SEEK_SET);
	fread(&ldf, sizeof(long double), 1, fp);
	//printf("%d Bit long double: %Lf  %Le\n", sizeof(long double)*8, ldf, ldf);
	printf("%d Bit long double:       %Le\n", sizeof(long double)*8, ldf);
	
	return 0;
}

void Clear(void)
{
	register int i;
	for (i=0; i<=25; i++)
		puts("");
}

void MainCtrl(void)
{
	FILE *fp;
	fp = fopen("bin_data.exe", "rb");
	if (!fp) {
		puts("File not open");
		exit(-1);
	}
	ShowData(fp, 0);
	ShowXchar(fp, 0);
	fclose(fp);
	fp = fopen("chars.txt", "rb");
	if (fp == NULL) {
		puts("File not open");
		exit(-1);
	}
	puts("");
	Clear();
	ShowXchar(fp, 0);
	ShowXchar(fp, 3);
	ShowXchar(fp, 6);
	ShowXchar(fp, 9);
	ShowXchar(fp, 12);
	ShowXchar(fp, 15);
	ShowXchar(fp, 18);
	ShowXchar(fp, 21);
	
	ShowUtf8(fp, 0);
	ShowUtf8(fp, 3);
	ShowUtf8(fp, 6);
	
	Clear();
	int i;
	for (i=0; i<6*3; i+=3)
		ShowUtf8(fp, i);	
		
	fp = fopen("utf8_.txt", "rb");
	if (fp == NULL) {
		puts("File not open");
		exit(-1);
	}
	puts("");
	for (i=0; i<6*3; i+=3)
		ShowUtf8(fp, i);
		
	puts("--------- Read file ----------------");
	ShowFile(fp, "utf-8");
	puts("--------- Read file ----------------");
	ShowFile(fp, "ascii");
	puts("--------- Read file ----------------");
	ShowFile(fp, "utf-16");
	puts("--------- Read file ----------------");
	ShowFile(fp, "UTF-16");
		
	fclose(fp);
}

void Test2(void)
{
	unsigned char i;
	char j;
	for (i=0; i<254; i++) // unsigned char: 0 - 254
		printf("%c ", i);
	puts("");
	for (j=0; j<127; j++) // char: 0 - 126
		printf("%c ", j);
		
	puts("");
	j = 0x7f;
	printf("j = %d, j+1 = %d, j+2 = %d\n", j, j+1, j+2);
	if (j&0x80)
		puts("Bit 8 set 1");
	
	j = 0x80;
	printf("j = %d, j+1 = %d, j+2 = %d\n", j, j+1, j+2);
	if (j&0x80)
		puts("Bit 8 set 1");
}

int main(void)
{
	MainCtrl();
	Test2();
	return 0;
}
