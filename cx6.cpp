#include <iostream>
#include <iomanip>
using namespace std;
class vehicle//������
{
public://����
	vehicle(int wh,int we);//���캯��
protected://����
	int wheels;//����
	int weight;
};
vehicle::vehicle(int wh,int we)//���캯������
{
	wheels=wh;
	weight=we;
	cout<<"�������������ǣ�";
	cin>>wheels;
	cout<<endl;
	cout<<"���������ǣ�";
	cin>>weight;
	cout<<endl;
}
class car: private vehicle//˽��������car
{
	int passenger_load;//������
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
		cout<<"passenger_load="��
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
