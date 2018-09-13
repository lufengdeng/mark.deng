/*#ifdef __STDC__
  int CompilerIs = __STDC__;
#elif defined(__cplusplus)
  int CompilerIs = __cplusplus;
#endif*/
/*#ifdef __STDC__
  int CompilerIs = 1;
#else
  int CompilerIs = 2;
#endif*/
#ifdef __cplusplus
  #include <cstdio>
  #include <cstring>
  #include <iostream>
  int CompilerIs = 2;
#else
  #include <stdio.h>
  #include <string.h>
  int CompilerIs = 1;
#endif

int main(void)
{
	char msg[32];
	puts("What use compiler?");
	switch (CompilerIs) {
		case 1: strcpy(msg, "C"); break;
		case 2: strcpy(msg, "C++"); break;
		default: strcpy(msg, "Other"); // default �������}��ǰ��Ҫ��break;
		
	}
	printf("You use %s compiler\n", msg);
#ifdef __STDC__
	printf("__STDC__ == %d\n", __STDC__);
#endif
	//if (CompilerIs = 2)
#ifdef __cplusplus
		printf("__cplusplus == %ld\n", __cplusplus);
#endif
	// ͨ��C��������ֻ������ __STDC__ == 1 ��ʾ�Ǳ�׼C������
	// ��c++�������м������� __STDC__ Ҳ������ __cplusplus ��ʾ��C++������
	return 0;
}
