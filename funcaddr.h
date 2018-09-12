void* GetFuncAddr(void (*func)());
void PrintFuncAddr(void (*Func)());
int GetFuncSize(void (*Func)());
void PrintFuncCode(void (*Func)(), int n);

// 函数信息结构
struct FuncHead {
	void *firstAddr;
	int size;
	unsigned char codes[4096];
} FuncInfo;

typedef struct FuncHead Finfo;

// 获取函数模块的首地址
void* GetFuncAddr(void (*func)())
{
	return func;
}

//// 输出函数模块的首地址
void PrintFuncAddr(void (*Func)())
{
	printf("%%Func%% first addr: %p\n", Func);
}

// 获取函数模块的机器码字节数(判断函数结束位置)
int GetFuncSize(void (*Func)())
{
	int n = 0;
	// begin hex: 55  89  E5 , end hex: C3 E9
	unsigned char RET = 0xC3;
	unsigned char JMP = 0xE9;
	unsigned char ch;
	unsigned char *Ptr = (void *)Func;
	// 函数的首条指令是JMP跳转指令时的处理
	if (*Ptr == JMP) {
		Ptr = (void *)(*Ptr+1);
	}
	do {
		ch = *Ptr;
		++n;
		++Ptr;
	} while (ch != RET); // 从函数的第一个字节向下输出, 只至遇到RET返回指令
	return n;
}

// 打印函数模块的机器码块
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

// 打印函数模块的机器码块
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
