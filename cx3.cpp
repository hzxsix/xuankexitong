#include<stdio.h>

#include<algorithm>

using namespace std;

struct score

{

   int Chinese,Math,English; 

   int number,sum;   //学号，综合

}student[3000];//创建成绩结构体

int cmp(score x,score y)

{

    if(x.sum!=y.sum) return (x.sum>y.sum?x.sum:y.sum);

	if(x.Chinese!=y.Chinese) return (x.Chinese>y.Chinese?x.sum:y.sum);

    if(x.number!=y.number) return (x.number<y.number?x.number:y.number);

}//创建比较子函数

int main()

{

    int i,j,n;

	printf("输入学生数量：");

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {

      scanf("%d%d%d",&student[i].Chinese,&student[i].Math,&student[i].English);//顺序输入语文数学英语成绩

      student[i].number=i+1;//学号加一

      student[i].sum=student[i].Chinese+student[i].Math+student[i].English;//求和

    }
	printf("前五名分别是：");

    sort(student,student+n,cmp);//排序

    for(i=0;i<5;i++)
		
	printf("%d %d\n",student[i].number,student[i].sum);//输出前五名的学号和成绩总和

    while(1);

    return 0;

}