#include<stdio.h>

int main()
{
    int n;
    printf("��������ķ��� : ");
    scanf("%d", &n);
    printf("��ϲ��");
    if(n < 60) 
	{
        printf("����!");
    }
    if(n >= 60) {
    	printf("ͨ���ˣ�");
	} 
    return 0;
}

