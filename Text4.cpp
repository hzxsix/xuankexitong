#include <iostream>
#include <string>
using namespace std;
void virus(char map[][10],int n,int m)//定义子函数virus
{
	int b[100], c[100];//储存X所在位置的下标
	int u=0;
	int i,j,h,k,l;//数组下标
	for(i=0;i<n;i++)//定位X的位置
	{
		for(j=0;j<m;j++)
		{
			if (map[i][j]=='X')
			{
				b[u]=i;
				c[u]=j;
				u++;
			}
		}
	}
	for(h=0;h<u;h++)//感染周围
	{
		k=b[h];l=c[h];
		if (map[k][l-1]=='O'&&l>0)
			map[k][l-1]='X';
		if (map[k][l+1]=='O')
			map[k][l+1]='X';
		if (map[k+1][l]=='O')
			map[k+1][l]='X';
		if (map[k-1][l]=='O')
			map[k-1][l]='X';
	}
}
void main()
{
	int n=4;
	int m=10;
	int i,j;
	int T;
	char map[4][10];
	cout<<"初始地图是:"<<endl;
	for(i=0;i<4;i++)//地图初始化
	{
		for(j=0;j<10;j++)
		{
			map[i][j]='O';
			map[1][1]='X';
			map[i][4]='P';
			cout<<map[i][j];
		}
		cout<<endl;
	}
	cout<<"输入周期T:";
	cin>>T;
	for(i=0;i<T;i++)
		virus(map,n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<map[i][j];
		cout<<endl;
	}
}