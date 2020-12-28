void fun(int *a,int *b,int *c)
{
    *c=*a/10*1000+*b/10*100+*a%10*10+*b%10;
}
#include <iostream>
using namespace std;
void fun(int *a,int *b,int *c);
int main()
{
    int a,b,c;
    printf("Please enter a:\n");
    scanf("%d",&a);  
    printf("Please enter b:\n");
    scanf("%d",&b);  
    fun(&a,&b,&c);
    printf("The number c is %d",c);  
    return 0;
}
