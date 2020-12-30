#include <iostream>
using namespace std;
struct stu{
	int sn;
	int ch;
	int al;
	int en;
	int sum;
};
const int LN=300;
stu a[LN];
int main(){	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].ch>>a[i].al>>a[i].en;
		a[i].sn =i+1;
		a[i].sum=a[i].ch+a[i].al+a[i].en ;	
	}
	
	for( i=0;i<n;i++){
		int k=i;
		for(int j=k+1;j<n;j++) 
			if(a[j].sum >a[k].sum ) k=j;
		if(k!=i) swap(a[i],a[k]);	
	}
	
	for( i=n-1;i>0;i--){
		if((a[i].sum==a[i-1].sum && a[i].ch>a[i-1].ch) ||
		(a[i].sum==a[i-1].sum && a[i].ch==a[i-1].ch && a[i].sn<a[i-1].sn ) )
			swap(a[i],a[i-1]);
	}
	
	
	for(i=0;i<5;i++) cout<<a[i].sn<<" "<<a[i].sum<<endl;
}