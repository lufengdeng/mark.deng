// 使用c++编译此程序为 func.obj , 如果想让 C 连接 C++ 的obj文件，则取消下行注释

////#ifndef __cplusplus
// 方式1：
//extern "C" float GetMaxF(float, float); // C 是大写的 C
////#endif

// 方式2:
//extern “C” 按照标准来实现   关键点
#ifdef __cplusplus
extern "C"{
#include "func.h"
// ...
}
#endif

// extern "C++" {

// 方式3:
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

// 以上只能用在C++源程序中，表示 本文件内的所有函数编译成 .obj 时都按照 C
// 语言的调用方式，只有这样才能让 C 程序 调用 C++ 生成的目标文件 .obj或.lib

float GetMaxF(float e, float f)
{
	return e > f ? e : f;
}

const char* GetMsg(void)
{
	//return "func.cpp";  // 字符串是常量, 所以要用const char* 否则警告
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
