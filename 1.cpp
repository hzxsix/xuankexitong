#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#include <iostream>
using namespace std;

#pragma comment(lib,"libmysql.lib")
struct course//�γ�
{ 
	int num; //�γ̱��
	char name[20]; //�γ�����
	char kind[10]; //����
	int time; //��ѧʱ
	int ttime; //�ڿ�ѧʱ
	int etime; //ʵ��ѧʱ
	int mark; //ѧ��
	int term; //����ѧ��
}; 
struct course c;//�γ�
struct student//ѧ��
{
	int snum;//ѧ��ѧ��
	int sname;//ѧ������
	int cnum;//�γ̱��
	char cname;//�γ�����
};

struct student s;//ѧ��ѡ����Ϣ
//.......�˵�.......//
void menu()
{
    cout<<"**********************ѡ��ϵͳ**********************"<<endl;
    cout<<"                    1-->¼������                    "<<endl;
    cout<<"                    2-->�����Ϣ(�γ̻�ѡ����Ϣ)                    "<<endl;
    cout<<"                    3-->��ѯ��Ϣ                   "<<endl;
    cout<<"                    0-->�˳�                    "<<endl;
}
//.........................�γ���Ϣ¼��................................//
void input()
{
    cout<<"������¼������ѡ��11/12��:";
    int choice = 0;//ѡ��
	MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
	MYSQL_RES *res;       // ��ѯ��������ṹ����
	MYSQL_FIELD *fd ;     // �����ֶ���Ϣ�Ľṹ
	MYSQL_ROW row ;       // ���һ�в�ѯ������ַ�������
	char  qbuf[256];      // ��Ų�ѯ sql ����ַ���
	mysql_init(&mysql);//����
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}//���ӽ���
	cin>>choice;
    if(choice == 11)
	{
		cout<<"��¼��γ���Ϣ����ʽʾ����1 C���� ���� 30 20 10 1 1����";
		scanf("%d%s%s%d%d%d%d%d",&c.num,&c.name,&c.kind,&c.time,&c.ttime,&c.etime,&c.mark,&c.term);
		sprintf(qbuf,"insert into information (num, name,kind,time,ttime,etime,mark,term) values ('%d','%s','%s','%d','%d','%d','%d','%d');",c.num,c.name,c.kind,c.time,c.ttime,c.etime,c.mark,c.term);//¼�������
		mysql_query(&mysql, qbuf);//����
        cout<<"�����Ѿ�¼�����!";
    }
	else if(choice == 12)
	{
		cout<<"��¼��ѡ����Ϣ����ʽʾ����2017001 ���� 01 math����";
		scanf("%d%s%d%s",&s.snum,&s.sname,&s.cnum,&s.cname);//����ѡ����Ϣ
		sprintf(qbuf,"insert into cv (snum,sname,cnum,cname) values ('%s','%s','%s','%s');",s.snum,s.sname,s.cnum,s.cname);//¼�������
		mysql_query(&mysql, qbuf);//����
        cout<<"�����Ѿ�¼����ϣ�";
    }
	else
	{
        cout<<"�������";
    }
    cout<<endl;
}
//...........................����γ�............................//
void browseCourses()
{
	cout<<"����������ѡ��21/22��:";
    int choice = 0;//ѡ��
	MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
	MYSQL_RES *res;       // ��ѯ��������ṹ����
	MYSQL_FIELD *fd ;     // �����ֶ���Ϣ�Ľṹ
	MYSQL_ROW row ;       // ���һ�в�ѯ������ַ�������
	char  qbuf[256];      // ��Ų�ѯ sql ����ַ���
	cout<<"21---����γ���Ϣ��"<<endl;
	cout<<"22---���ѡ����Ϣ��"<<endl;
	cin>>choice;
	mysql_init(&mysql);//����
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","123456","vc",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}//���ӽ���
	if(choice == 21)//����γ���Ϣ
	{
		cout<<"�γ���Ϣ���£�"<<endl;
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
		cout<<"�����Ѿ�ȫ����ʾ!"<<endl;
		mysql_free_result(res);
		mysql_close(sock);
		
	}
	else if(choice ==22)//���ѡ����Ϣ
	{
		cout<<"ѡ����Ϣ���£�"<<endl;
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
		cout<<"�����Ѿ�ȫ����ʾ!"<<endl;
		mysql_free_result(res);
		mysql_close(sock);
		
		
	}
	else
	{
       cout<<"�������";
	}
	cout<<endl;
}
//....................��ѯ��Ϣ..............//
void getCourseIn()
{
	MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
	MYSQL_RES *res;       // ��ѯ��������ṹ����
	MYSQL_FIELD *fd ;     // �����ֶ���Ϣ�Ľṹ
	MYSQL_ROW row ;       // ���һ�в�ѯ������ַ�������
	char  qbuf[256];      // ��Ų�ѯ sql ����ַ���
	int choice=0;
	cout<<"31-->����ѧ����Ϣ��ѯ:"<<endl;
	cout<<"32-->���ݿγ����ʲ�ѯ:"<<endl;
	cout<<"���������Ĳ�ѯ���:";

	cin>>choice;
	if(choice == 31)
	{
       cout<<"������ѧ�֣�"<<endl;
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
	   cout<<"������ȫ����ʾ";
	}
	else if(choice == 32)
	{
		cout<<"������γ����ʣ�"<<endl;
		char k[20];
		cin.getline(k,20);//����γ�����
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
       cout<<"�������!"<<endl;
    }
	cout<<endl; 
}
void go()//��ʾ��ҳ��˵�
{
	while(true)
	{
		menu();
		int choice;
		cout<<"�밴�ղ˵���ʾ�������Ĳ�����ţ�"<<endl;
		cin>>choice;
		cout<<endl;
		if(choice == 0)
		{
			cout<<"���Ѿ��˳�ϵͳ��"<<endl;
			exit(0);
		}
		else if(choice == 1)
		{
			input();//¼����Ϣ
		}
		else if(choice == 2)
		{
			browseCourses();//����γ���Ϣ��ѡ����Ϣ
		}
		else if(choice == 3)
		{
			getCourseIn();//��ѯ��Ϣ
		}
		else
		{
			cout<<"�������"<<endl;
		}
	}
}

int main(int argc, char **argv)
{
	go();
	return 0;
}
