#include <stdio.h>
#include <string.h>

#if __STDC__
  int CompilerIs = __STDC__;
#elif __cplusplus
  int CompilerIs = __cplusplus;
#endif

int main(void)
{
	char msg[32];
	puts("What use compiler?");
	switch (CompilerIs) {
		case 1: strcpy(msg, "C"); break;
		case 2: strcpy(msg, "C++"); break;
		default: strcpy(msg, "Other"); // default 放在最后}以前则不要加break;
		
	}
	printf("You use %s compiler\n", msg);
	printf("__STDC__ == %d\n", __STDC__);
	//printf("__cplusplus == %d\n", __cplusplus);
	return 0;
}
