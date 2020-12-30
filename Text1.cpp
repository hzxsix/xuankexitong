#include <stdio.h>
int fun(int a,int b){

int c=10*(b%10)+(a/10)+1000*(b/10)+100*(a%10);

return c;

}

int main() {

int a;

int b;

printf("请输入第du一个两位zhi数a:");

scanf("%d",&a);

printf("请输入第二个两位数b:");

scanf("%d",&b);

int c=fun(a,b);

printf("结果为:%d",c);

return 0;

}