#include <iostream>
#include <string>
using namespace std;
void virus(char map[][10],int n,int m)//�����Ӻ���virus
{
	int b[100], c[100];//����X����λ�õ��±�
	int u=0;
	int i,j,h,k,l;//�����±�
	for(i=0;i<n;i++)//��λX��λ��
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
	for(h=0;h<u;h++)//��Ⱦ��Χ
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
	cout<<"��ʼ��ͼ��:"<<endl;
	for(i=0;i<4;i++)//��ͼ��ʼ��
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
	cout<<"��������T:";
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