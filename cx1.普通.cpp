#include <iostream>//1.��1��
using namespace std;
int fun(int a,int b)
{
	int c=10*(a%10)+(b%10)+1000*(a/10)+100*(b/10);	
	return c;
}//�����Ӻ���fun
int main() 
{	
	int a,b,c;
	cin>>a;//����a
	cin>>b;//����b
	c=fun(a,b);
	cout<<"a,b���Ϻ������c:"<<c;//������Ϻ������c
	return 0;
}