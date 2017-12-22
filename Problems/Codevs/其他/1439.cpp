/*
统计素数个数
*/
#include<iostream>
#include<bitset>
using namespace std;
bitset<21003> bt=0;
int l,r,ans=0;
int main(){
	cin>>l>>r;
	bt[0]=bt[1]=1;
	for(int i=2;i<=r;i++)
		if(!bt[i])for(int j=i*i;j<=r;j+=i)bt[j]=1;
	for(int i=l;i<=r;i++)
		if(!bt[i])ans++;
	cout<<ans;
	return 0;
}
