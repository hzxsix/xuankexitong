#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#include <iostream>
using namespace std;

#pragma comment(lib,"libmysql.lib")
struct course//课程
{ 
	int num; //课程编号
	char name[20]; //课程名称
	char kind[10]; //性质
	int time; //总学时
	int ttime; //授课学时
	int etime; //实验学时
	int mark; //学分
	int term; //开课学期
}; 
struct course c;//课程
struct student//学生
{
	int snum;//学生学号
	int sname;//学生姓名
	int cnum;//课程编号
	char cname;//课程名称
};

struct student s;//学生选课信息
//.......菜单.......//
void menu()
{
    cout<<"**********************选课系统**********************"<<endl;
    cout<<"                    1-->录入数据                    "<<endl;
    cout<<"                    2-->浏览信息(课程或选课信息)                    "<<endl;
    cout<<"                    3-->查询信息                   "<<endl;
    cout<<"                    0-->退出                    "<<endl;
}
//.........................课程信息录入................................//
void input()
{
    cout<<"请输入录入您的选择（11/12）:";
    int choice = 0;//选择
	MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES *res;       // 查询结果集，结构类型
	MYSQL_FIELD *fd ;     // 包含字段信息的结构
	MYSQL_ROW row ;       // 存放一行查询结果的字符串数组
	char  qbuf[256];      // 存放查询 sql 语句字符串
	mysql_init(&mysql);//连接
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}//连接结束
	cin>>choice;
    if(choice == 11)
	{
		cout<<"请录入课程信息（格式示例：1 C语言 必修 30 20 10 1 1）：";
		scanf("%d%s%s%d%d%d%d%d",&c.num,&c.name,&c.kind,&c.time,&c.ttime,&c.etime,&c.mark,&c.term);
		sprintf(qbuf,"insert into information (num, name,kind,time,ttime,etime,mark,term) values ('%d','%s','%s','%d','%d','%d','%d','%d');",c.num,c.name,c.kind,c.time,c.ttime,c.etime,c.mark,c.term);//录入的数据
		mysql_query(&mysql, qbuf);//搭配
        cout<<"数据已经录入完毕!";
    }
	else if(choice == 12)
	{
		cout<<"请录入选课信息（格式示例：2017001 张三 01 math）：";
		scanf("%d%s%d%s",&s.snum,&s.sname,&s.cnum,&s.cname);//输入选课信息
		sprintf(qbuf,"insert into cv (snum,sname,cnum,cname) values ('%s','%s','%s','%s');",s.snum,s.sname,s.cnum,s.cname);//录入的数据
		mysql_query(&mysql, qbuf);//搭配
        cout<<"数据已经录入完毕！";
    }
	else
	{
        cout<<"输入错误！";
    }
    cout<<endl;
}
//...........................浏览课程............................//
void browseCourses()
{
	cout<<"请输入您的选择（21/22）:";
    int choice = 0;//选择
	MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES *res;       // 查询结果集，结构类型
	MYSQL_FIELD *fd ;     // 包含字段信息的结构
	MYSQL_ROW row ;       // 存放一行查询结果的字符串数组
	char  qbuf[256];      // 存放查询 sql 语句字符串
	cout<<"21---浏览课程信息："<<endl;
	cout<<"22---浏览选课信息："<<endl;
	cin>>choice;
	mysql_init(&mysql);//连接
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}//连接结束
	if(choice == 21)//浏览课程信息
	{
		cout<<"课程信息如下："<<endl;
		sprintf(qbuf,"select * from information");
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)/n",mysql_error(sock));
			exit(1);
		}
		if (!(res = mysql_store_result(sock)))
		{
			fprintf(stderr,"Couldn't get result from %s/n", mysql_error(sock));
			exit(1);
		}
		printf("number of fields returned: %d\n", mysql_num_fields(res));	// field number
		while (row = mysql_fetch_row(res))
		{
			printf("%s  %s  %s  %s  %s  %s  %s  %s  \n", row[0], row[1],row[2],row[3],row[4],row[5],row[6],row[7]);
		}
		cout<<"数据已经全部显示!"<<endl;
		mysql_free_result(res);
		mysql_close(sock);
		
	}
	else if(choice ==22)//浏览选课信息
	{
		cout<<"选课信息如下："<<endl;
		sprintf(qbuf,"select * from cv ");
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)/n",mysql_error(sock));
			exit(1);
		}
		if (!(res = mysql_store_result(sock)))
		{
			fprintf(stderr,"Couldn't get result from %s/n", mysql_error(sock));
			exit(1);
		}
		printf("number of fields returned: %d\n", mysql_num_fields(res));	// field number
		while (row = mysql_fetch_row(res))
		{
			printf("%s  %s  %s  %s  \n", row[0], row[1],row[2],row[3]);
		}
		cout<<"数据已经全部显示!"<<endl;
		mysql_free_result(res);
		mysql_close(sock);
		
		
	}
	else
	{
       cout<<"输入错误！";
	}
	cout<<endl;
}
//....................查询信息..............//
void getCourseIn()
{
	MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES *res;       // 查询结果集，结构类型
	MYSQL_FIELD *fd ;     // 包含字段信息的结构
	MYSQL_ROW row ;       // 存放一行查询结果的字符串数组
	char  qbuf[256];      // 存放查询 sql 语句字符串
	int choice=0;
	cout<<"31-->根据学分信息查询:"<<endl;
	cout<<"32-->根据课程性质查询:"<<endl;
	cout<<"请输入您的查询编号:";

	cin>>choice;
	if(choice == 31)
	{
       cout<<"请输入学分："<<endl;
	   int m;
	   cin>>m;
	   mysql_init(&mysql);//..
	   if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
	   {
		 fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		 perror("");
		 exit(1);
	   }//....
	   sprintf(qbuf,"select * from information where mark='%d';",m);
	   if(mysql_query(sock,qbuf))
	   {
		  fprintf(stderr,"Query failed (%s)/n",mysql_error(sock));
		  exit(1);
	   }
	   if (!(res = mysql_store_result(sock))) {
		  fprintf(stderr,"Couldn't get result from %s/n", mysql_error(sock));
		  exit(1);
	   }
	   printf("number of fields returned: %d\n", mysql_num_fields(res));	// field number
	   while (row = mysql_fetch_row(res))
	   {
		   printf("num=%s,name=%s,kind=%s,time=%s,ttime=%s,etime=%s,mark=%s,term=%s\n", row[0], row[1],row[2],row[3],row[4],row[5],row[6],row[7]);
	   }
	   mysql_free_result(res);
	   mysql_close(sock);
	   cout<<"数据已全部显示";
	}
	else if(choice == 32)
	{
		cout<<"请输入课程性质："<<endl;
		char k[20];
		cin.getline(k,20);//输入课程性质
	    //...............//
	    mysql_init(&mysql);
	    if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
		{
			fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		    perror("");
		    exit(1);
		}//....
	
		sprintf(qbuf,"select * from information where kind='%s';",k);
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)/n",mysql_error(sock));
			exit(1);
		}
		if (!(res = mysql_store_result(sock))) {
			fprintf(stderr,"Couldn't get result from %s/n", mysql_error(sock));
		    exit(1);
		}
		while (row = mysql_fetch_row(res))
		{
			printf("num=%s,name=%s,kind=%s,time=%s,ttime=%s,etime=%s,mark=%s,term=%s\n", row[0], row[1],row[2],row[3],row[4],row[5],row[6],row[7]);
		}
		mysql_free_result(res);
		mysql_close(sock);
		exit(0);
	}
	else
	{
       cout<<"输入错误!"<<endl;
    }
	cout<<endl; 
}
void go()//显示主页面菜单
{
	while(true)
	{
		menu();
		int choice;
		cout<<"请按照菜单提示输入您的操作编号："<<endl;
		cin>>choice;
		cout<<endl;
		if(choice == 0)
		{
			cout<<"您已经退出系统！"<<endl;
			exit(0);
		}
		else if(choice == 1)
		{
			input();//录入信息
		}
		else if(choice == 2)
		{
			browseCourses();//浏览课程信息及选课信息
		}
		else if(choice == 3)
		{
			getCourseIn();//查询信息
		}
		else
		{
			cout<<"输入错误！"<<endl;
		}
	}
}

int main(int argc, char **argv)
{
	go();
	return 0;
}
