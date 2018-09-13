// funca.c
/*static */int width = 640, height = 480;  // 初始化w, h

// 内部函数(文件作用域, 隐藏了功能的具体实现(原生实现))
static void __SetWidth(int w)
{
	width = w;
}

static void __SetHeight(int h)
{
	height = h;
}

// 内部函数(文件作用域)
static int __GetWidth(void)
{
	return width;
}

static int __GetHeight(void)
{
	return height;
}

/*static */void Swap(int *a, int *b) // 加static 将出错,因为它是文件作用域
{
	int c;
	c = *a + 10;
	*a = *b + 10;
	*b = c;
}

void SwapEx(int *a, int *b)
{
	/*int *c;
	c = a;
	a = b;
	b = c;*/
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// 提供给外部的接口
void SetWidth(int w)
{
	__SetWidth(w); // 接口的实现来自内部函数
}

void SetHeight(int h)
{
	__SetHeight(h);
}

// 提供给外部的接口
int GetWidth(void)
{
	return __GetWidth(); // 接口的实现来自内部函数
}

int GetHeight(void)
{
	return __GetHeight();
}

void GetWandH(int *w, int *h)
{
	*w = width;
	*h = height;
}
