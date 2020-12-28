#include <iostream>
#include <vector>
using namespace std;
main()
{
	int m,n,number,count=1;		//number记猴子剩余个数，count记当前报数
	int monkey[999];
	int t;						//t记数组下标
	int i;
	cout<<"请输入猴子个数m和数字n";
	cin>>m;
	cin>>n;
	number=m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;//初始猴子编号
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//t=(t+1)%m实现数组下标加1
				//（假设有10只猴子，当数组下标为9时（t = 9），
				//t++就会使 t = 10，而我们要让 t = 0，
				//需要重新拐回去报数（只报数据大于0的猴子)，所以用 t = (t + 1)%m。
			}
			else
			{
				monkey[t]=0;//如果是n处的猴子，编号设为0，并从此处重新计数
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
			cout<<"猴子大王:"<<monkey[i];
	}
	return 0;
}
