#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double part_take1(char a[],int b,int c);
double multiply(char h[]);
void part_take2(char d[],char *e,int f,int g);
int main(void)
{
int i;
int j;
int k;
int length;
char ch2[100];
char express[100];
char reset;
double part1;
 double result=0;
k=-1;
puts("ÇëÊäÈë¼ÆËãÊ½");
gets(express);
length=strlen(express);
for(i=0;i<strlen(express);i++)
{
if(express[i]=='+'||express[i]=='-')
{
part_take2(express,ch2,k+1,i-1);
part1=multiply(ch2);
if(k==-1)
{
result=result+part1;
}
if(express[k]=='+'&&k>0)
{
result=result+part1;
}
if(express[k]=='-'&&k>0)
{
result=result-part1;
}
ch2[0]='\0';
k=i;
}
}
part_take2(express,ch2,k+1,length-1);
part1=multiply(ch2);
if(k==-1||express[k]=='+')
{
result=result+part1;
}
else
{
result=result-part1;
}
printf("%f",result);
system("pause");
return 0;
}
double part_take1(char a[],int b,int c)
{
char ch1[100];
int j;
int h;
double result;
for(h=b,j=0;h<=c;h++,j++)
{
ch1[j]=a[h];
}
result=atof(ch1);
return(result);
}
double multiply(char h[])
{
int k=-1;
int i;
double part=1;
double num;
int s=strlen(h);
for(i=0;i<s;i++)
{
if(h[i]=='*'||h[i]=='/')
{
num=part_take1(h,k+1,i-1);
if(k<0)
{
part=part*num;
}
if(h[k]=='*'&&k>0)
{
part=part*num;
}
if(h[k]=='/'&&k>0)
{
part=part/num;
}
k=i;
}
}
num=part_take1(h,k+1,s-1);
if(h[k]=='*'||k==-1)
{
part=part*num;
}
else
{
part=part/num;
}
return(part);
}
void part_take2(char d[],char *e,int f,int g)
{
int i;
int j;
for(i=f,j=0;i<=g;i++,j++)
{
e[j]=d[i];
}
e[j]='\0';
}