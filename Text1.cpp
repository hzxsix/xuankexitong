#include <stdio.h>
int fun(int a,int b){

int c=10*(b%10)+(a/10)+1000*(b/10)+100*(a%10);

return c;

}

int main() {

int a;

int b;

printf("�������duһ����λzhi��a:");

scanf("%d",&a);

printf("������ڶ�����λ��b:");

scanf("%d",&b);

int c=fun(a,b);

printf("���Ϊ:%d",c);

return 0;

}