// funca.c
/*static */int width = 640, height = 480;  // ��ʼ��w, h

// �ڲ�����(�ļ�������, �����˹��ܵľ���ʵ��(ԭ��ʵ��))
static void __SetWidth(int w)
{
	width = w;
}

static void __SetHeight(int h)
{
	height = h;
}

// �ڲ�����(�ļ�������)
static int __GetWidth(void)
{
	return width;
}

static int __GetHeight(void)
{
	return height;
}

/*static */void Swap(int *a, int *b) // ��static ������,��Ϊ�����ļ�������
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

// �ṩ���ⲿ�Ľӿ�
void SetWidth(int w)
{
	__SetWidth(w); // �ӿڵ�ʵ�������ڲ�����
}

void SetHeight(int h)
{
	__SetHeight(h);
}

// �ṩ���ⲿ�Ľӿ�
int GetWidth(void)
{
	return __GetWidth(); // �ӿڵ�ʵ�������ڲ�����
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
