#include <stdio.h>

int main(void) {
#ifdef __STDC__
     printf("%s\n", "stardard C");
#endif
#ifdef __STDC_VERSION__
     // 正确输出结果应该是 long 型,
     // 这里本应该用 %ld, 但命令行运行不会返回提示而需要手动运行一次;
     // 故用 %d 让其警告而不用再次运行编译后程序即可查看结果
     printf("%d\n", __STDC_VERSION__);
#endif
     return 0;
}
