#include <iostream>
using namespace std;
int main()
{
	void fun(int &x, int &y);
	int a, b;
	int c=0;
	cout<<"������a:"<<endl;
	cin>>a;//����������a
	cout<<endl;
	cout<<"������b:"<<endl;
	cin>>b; //����������b
	cout<<endl;
	
	cout<<"���Ϻ������c:";
	fun(a,b);//���������c
	return 0;
}
void fun(int &x, int &y)
{
	int k = 0;
	int c;
	int c1, c2, c3, c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
	c1 = x /10;
	c2 = y / 10;
	c3 = x % 10;
	c4 = y % 10;
	c= c1 * 1000 + c2 * 100 + c3 * 10 + c4;
	cout<<c;//return c;
}