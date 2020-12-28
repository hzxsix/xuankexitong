#include<iostream>
#include<malloc.h> 
using namespace std;
typedef int Elemtype;

typedef struct LNode
{
	Elemtype number; 
	struct LNode *next;
}LinkNode;

void CreateList(LinkNode *&L,int m)//����ѭ�������� 
{
    LinkNode *s,*r;
	L=(LinkNode*)malloc(sizeof(LinkNode));
	r=L;
	L->number=1; 
	for(int i=1;i<m;i++)
	{
	    s=(LinkNode*)malloc(sizeof(LinkNode));
	    s->number=i+1; 
		r->next=s;
		r=s; 	
	}
	r->next=L; 
}

void Monkey(LinkNode *&L,int &m,int &n)
{
    LinkNode *p=L,*q; 
    int f,i,j; 
    cout<<"�������Ϊ��"; 
    for(j=0;j<m-1;j++) 
	{
	    for(i=1;i<n-1;i++)
	    {
	        p=p->next; 
    	}
    	q=p->next;
		f=q->number; 
		p->next=q->next;
		free(q);
		cout<<f<<" "; 
		p=p->next; 
	} 
	cout<<"����Ϊ"<<p->number<<endl; 
}

int main()
{
	int m=20,n;
	LinkNode *L; 
	cout<<"��������Ӹ���m��";
	cin>>m; 
	cout<<"������n��";
	cin>>n;
	CreateList(L,m);
	Monkey(L,m,n);
	return 0;
}