void* GetFuncAddr(void (*func)());
void PrintFuncAddr(void (*Func)());
int GetFuncSize(void (*Func)());
void PrintFuncCode(void (*Func)(), int n);

// ������Ϣ�ṹ
struct FuncHead {
	void *firstAddr;
	int size;
	unsigned char codes[4096];
} FuncInfo;

typedef struct FuncHead Finfo;

// ��ȡ����ģ����׵�ַ
void* GetFuncAddr(void (*func)())
{
	return func;
}

//// �������ģ����׵�ַ
void PrintFuncAddr(void (*Func)())
{
	printf("%%Func%% first addr: %p\n", Func);
}

// ��ȡ����ģ��Ļ������ֽ���(�жϺ�������λ��)
int GetFuncSize(void (*Func)())
{
	int n = 0;
	// begin hex: 55  89  E5 , end hex: C3 E9
	unsigned char RET = 0xC3;
	unsigned char JMP = 0xE9;
	unsigned char ch;
	unsigned char *Ptr = (void *)Func;
	// ����������ָ����JMP��תָ��ʱ�Ĵ���
	if (*Ptr == JMP) {
		Ptr = (void *)(*Ptr+1);
	}
	do {
		ch = *Ptr;
		++n;
		++Ptr;
	} while (ch != RET); // �Ӻ����ĵ�һ���ֽ��������, ֻ������RET����ָ��
	return n;
}

// ��ӡ����ģ��Ļ������
void PrintFuncCode(void (*Func)(), int n)
{
	unsigned char buf[1024];
	unsigned char *Ptr = NULL;
	void *Save = NULL;
	int s = -776;
	int m = -777;
	s = GetFuncSize(Func);
	if (n>s) {
		n = s;		
	}
	else if(n<1) {
		n = s;
		m = -1;
	}
	else if(n>1023) {
		n = 1023;
	}
	Ptr = buf;
	memmove(Ptr, Func, n);	
	Save = Func;
	while (n--) {
		printf(" %02X ", *Ptr);
		Ptr++;
	}
	printf("\n");
	if (m == -1) {				
		printf("Function first addr: %p\n", Save);		
		printf("Function end addr:   %p\n", Save+s-1);
		printf("Function size: %p ~ %p = %d bytes\n", Save, Save+s-1, s);
	}
}

// ��ӡ����ģ��Ļ������
void PrintFuncCodeEx(void (*Func)())
{
	unsigned char buf[1024];
	unsigned char *Ptr = NULL;
	void *Save = NULL;
	int s = -776;
	int m = -777;
	int n = -1;
	s = GetFuncSize(Func);
	if (n>s) {
		n = s;		
	}
	else if(n<1) {
		n = s;
		m = -1;
	}
	else if(n>1023) {
		n = 1023;
	}
	Ptr = buf;
	n = s;
	memmove(Ptr, Func, n);	
	Save = Func;
	while (n--) {
		printf(" %02X ", *Ptr);
		Ptr++;
	}
	printf("\n");
	if (m == -1) {				
		printf("Function first addr: %p\n", Save);		
		printf("Function end addr:   %p\n", Save+s-1);
		printf("Function size: %p ~ %p = %d bytes\n", Save, Save+s-1, s);
	}
	puts("");
}
