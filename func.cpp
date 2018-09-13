// ʹ��c++����˳���Ϊ func.obj , ������� C ���� C++ ��obj�ļ�����ȡ������ע��

////#ifndef __cplusplus
// ��ʽ1��
//extern "C" float GetMaxF(float, float); // C �Ǵ�д�� C
////#endif

// ��ʽ2:
//extern ��C�� ���ձ�׼��ʵ��   �ؼ���
#ifdef __cplusplus
extern "C"{
#include "func.h"
// ...
}
#endif

// extern "C++" {

// ��ʽ3:
/*
  extern "C"{
   type func1();
   type func2();
   type func...
   type funcn();
  }
*/

// 1.
// extern "C" int printf( const char *fmt, ... );

// 2.
// extern "C" {
// #include <stdio.h>
// }

// 3.
// extern "C" {
// char ShowChar( char ch );
// char GetChar( void );
// }

// 4.
// extern "C" char ShowChar( char ch ) {
// putchar( ch );
// return ch;
// }

// 5.
// extern "C" char GetChar( void ) {
// char ch;
// ch = getchar();
// return ch;
// }

//extern "C" int errno;

// ����ֻ������C++Դ�����У���ʾ ���ļ��ڵ����к�������� .obj ʱ������ C
// ���Եĵ��÷�ʽ��ֻ������������ C ���� ���� C++ ���ɵ�Ŀ���ļ� .obj��.lib

float GetMaxF(float e, float f)
{
	return e > f ? e : f;
}

const char* GetMsg(void)
{
	//return "func.cpp";  // �ַ����ǳ���, ����Ҫ��const char* ���򾯸�
	//return __FILE__; 
	return (const char *)__LINE__;
}

const char ShowInfo(char *msg[5])
{
	//msg[0] = __FILE__;
	//msg[1] = __LINE__;
	//msg[2] = __VERSION__;
	return 'y';
}
