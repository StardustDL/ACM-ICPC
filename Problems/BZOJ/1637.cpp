/*
[Usaco2007 Mar]Balanced Lineup
分析：将0的牛变成-1，然后维护前缀和，这样类似差分，使得相等的区间会互相抵消，这个区间最前边的牛的前边一个牛的前缀和等于这个区间最后边的牛的前缀和
	  扫一遍即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
struct data{
	int p,w;
	bool operator <(const data &d)const{
		return p<d.p;
	}
}a[MAXN+3];
int vis[MAXN*2+3],n,sum=0,ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d%d",&a[i].w,&a[i].p);if(!a[i].w)a[i].w=-1;}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i].w;
		if(vis[sum])ans=max(ans,a[i].p-vis[sum]);
		else vis[sum]=a[i+1].p;
	}
	printf("%d\n",ans);
	return 0;
}

