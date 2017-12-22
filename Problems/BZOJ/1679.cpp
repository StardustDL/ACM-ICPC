/*
[Usaco2005 Jan]Moo Volume 牛的呼声
分析：注意都是线性的，可以直接递推ans[i]=ans[i-1]+(i-1)*(delta) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=10000,INF=0x3f3f3f3f;
LL a[MAXN+3],sum,lst;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	lst=sum=0;
	for(int i=2;i<=n;i++){
		sum+=(lst+=(LL)(i-1)*(a[i]-a[i-1]));
	}
	printf("%lld\n",sum<<1);
	return 0;
}

