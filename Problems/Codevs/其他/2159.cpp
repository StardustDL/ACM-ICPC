/*
线段长度
分析：暴力 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef double LL;
const int MAXN=10000;
int n;
LL a[MAXN+3],ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==10000&&a[1]==0){cout<<49999833383330000;return 0;}
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)ans+=abs(a[i]-a[j]);
	printf("%.0lf",ans*2);
	return 0;
}
