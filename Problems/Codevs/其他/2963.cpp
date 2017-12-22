/*
ø®∆¨’˚¿Ì
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,k,i,j,t,a[10001];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	k=n;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if((a[i]==a[j])&&(a[i]!=0))a[j]=0,k--;
			else if(a[i]>a[j])swap(a[i],a[j]);
		}
	}
	printf("%d\n",k);
	for(i=1;i<=n;i++)	
		if(a[i]!=0)printf("%d ",a[i]);
	return 0;
}
