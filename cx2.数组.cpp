#include <iostream>
#include <vector>
using namespace std;
main()
{
	int m,n,number,count=1;		//number�Ǻ���ʣ�������count�ǵ�ǰ����
	int monkey[999];
	int t;						//t�������±�
	int i;
	cout<<"��������Ӹ���m������n";
	cin>>m;
	cin>>n;
	number=m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;//��ʼ���ӱ��
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//t=(t+1)%mʵ�������±��1
				//��������10ֻ���ӣ��������±�Ϊ9ʱ��t = 9����
				//t++�ͻ�ʹ t = 10��������Ҫ�� t = 0��
				//��Ҫ���¹ջ�ȥ������ֻ�����ݴ���0�ĺ���)�������� t = (t + 1)%m��
			}
			else
			{
				monkey[t]=0;//�����n���ĺ��ӣ������Ϊ0�����Ӵ˴����¼���
				count=1;
				number--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			cout<<"���Ӵ���:"<<monkey[i];
	}
	return 0;
}
