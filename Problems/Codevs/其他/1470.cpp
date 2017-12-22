/*
数列处理
*/
#include<iostream>
#include<algorithm>
using namespace std;
int sum=0,n,ma=-(1<<30),mi=(1<<30),a[200];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	cout<<sum<<endl<<ma<<endl<<mi<<endl<<a[n]<<endl;
	for(int i=n-1;i>=1;i--)
		if(a[i]!=a[i+1])cout<<a[i]<<endl;
	return 0;
}
