#include <stdio.h>

int main(void) {
#ifdef __STDC__
     printf("%s\n", "stardard C");
#endif
#ifdef __STDC_VERSION__
     // ��ȷ������Ӧ���� long ��,
     // ���ﱾӦ���� %ld, �����������в��᷵����ʾ����Ҫ�ֶ�����һ��;
     // ���� %d ���侯��������ٴ����б������򼴿ɲ鿴���
     printf("%d\n", __STDC_VERSION__);
#endif
     return 0;
}
