// funca.h
#ifndef _FUNCA_H
#define _FUNCA_H
/* �Ǿ�̬��������, ����������δʹ�ò����ᾯ�� */
struct tagPoint {
	int x, y;
	int hotpoint;
} Pointer;

typedef struct tagPoint Point;
typedef enum tagBoolean { False, True } Bool;
//{}
//void Swap(int *a, int *b);  // error
//extern void Swap(int *a, int *b);  // error
//static void Swap(int *a, int *b);
void Swap(int*, int*);
void SetWidth(int), SetHeight(int);
int GetWidth(void), GetHeight(void);
#endif
