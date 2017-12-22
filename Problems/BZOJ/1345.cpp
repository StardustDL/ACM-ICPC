/*
[Baltic2007]序列问题Sequence
分析：每个数一定会和左边的和右边的合并，只要他比较大，那么就会贡献给答案。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	a[0]=a[n+1]=INF;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=((a[i]>=a[i-1])+(a[i]>a[i+1]))*a[i];//为防止重复计数，左边用>=，右边用> 
	printf("%lld\n",ans);
	return 0;
}

