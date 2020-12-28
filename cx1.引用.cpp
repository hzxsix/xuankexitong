#include <iostream>
using namespace std;
int main()
{
	void fun(int &x, int &y);
	int a, b;
	int c=0;
	cout<<"请输入a:"<<endl;
	cin>>a;//接收正整数a
	cout<<endl;
	cout<<"请输入b:"<<endl;
	cin>>b; //接收正整数b
	cout<<endl;
	
	cout<<"整合后的数字c:";
	fun(a,b);//输出正整数c
	return 0;
}
void fun(int &x, int &y)
{
	int k = 0;
	int c;
	int c1, c2, c3, c4;  //c1、c2、c3、c4分别对应c的千位、百位、十位、个位
	c1 = x /10;
	c2 = y / 10;
	c3 = x % 10;
	c4 = y % 10;
	c= c1 * 1000 + c2 * 100 + c3 * 10 + c4;
	cout<<c;//return c;
}