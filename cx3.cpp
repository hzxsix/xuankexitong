#include<stdio.h>

#include<algorithm>

using namespace std;

struct score

{

   int Chinese,Math,English; 

   int number,sum;   //ѧ�ţ��ۺ�

}student[3000];//�����ɼ��ṹ��

int cmp(score x,score y)

{

    if(x.sum!=y.sum) return (x.sum>y.sum?x.sum:y.sum);

	if(x.Chinese!=y.Chinese) return (x.Chinese>y.Chinese?x.sum:y.sum);

    if(x.number!=y.number) return (x.number<y.number?x.number:y.number);

}//�����Ƚ��Ӻ���

int main()

{

    int i,j,n;

	printf("����ѧ��������");

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {

      scanf("%d%d%d",&student[i].Chinese,&student[i].Math,&student[i].English);//˳������������ѧӢ��ɼ�

      student[i].number=i+1;//ѧ�ż�һ

      student[i].sum=student[i].Chinese+student[i].Math+student[i].English;//���

    }
	printf("ǰ�����ֱ��ǣ�");

    sort(student,student+n,cmp);//����

    for(i=0;i<5;i++)
		
	printf("%d %d\n",student[i].number,student[i].sum);//���ǰ������ѧ�źͳɼ��ܺ�

    while(1);

    return 0;

}