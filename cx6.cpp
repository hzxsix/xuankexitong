#include <iostream>
#include <iomanip>
using namespace std;
class vehicle//创建类
{
public://公有
	vehicle(int wh,int we);//构造函数
protected://保护
	int wheels;//数据
	int weight;
};
vehicle::vehicle(int wh,int we)//构造函数定义
{
	wheels=wh;
	weight=we;
	cout<<"汽车轮子数量是：";
	cin>>wheels;
	cout<<endl;
	cout<<"汽车重量是：";
	cin>>weight;
	cout<<endl;
}
class car: private vehicle//私有派生类car
{
	int passenger_load;//载人数
public:
	car(int wh,int we,int pa):vehicle(wh,we)
	{
		passenger_load=pa;
		cout<<"passenger_load=";
		cin<<passenger_load<<endl;
	}
};
class truck:private vehicle
{
	int passenger_load;
	int payload;
public:
	truck(int wh,int we,int pa,int pay):vehicle(wh,we)
	{
		passenger_load=pa;
		payload=pay;
		cout<<"passenger_load="；
		cin>>passenger_load<<endl;
		cout<<"payload";
		cin>>payload>>endl;
	}
}
void main()
{
	vehicle v(100, 99);
	car c(50, 40, 30);
	truck t(20, 15, 10, 5);
	system("pause");
}
