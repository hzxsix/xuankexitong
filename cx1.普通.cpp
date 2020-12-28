#include <iostream>//1.（1）
using namespace std;
int fun(int a,int b)
{
	int c=10*(a%10)+(b%10)+1000*(a/10)+100*(b/10);	
	return c;
}//建立子函数fun
int main() 
{	
	int a,b,c;
	cin>>a;//输入a
	cin>>b;//输入b
	c=fun(a,b);
	cout<<"a,b整合后的数字c:"<<c;//输出整合后的数字c
	return 0;
}