/*
[POI2009]SLO
分析：同BZOJ1697，更直接的置换问题：划分成循环来讨论 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int a[MAXN+3],b[MAXN+3],c[MAXN+3],w[MAXN+3],n;
int mn[MAXN+3],cnt=0,_mn,sz[MAXN+3];
LL sum[MAXN+3];
bitset<MAXN+3> vis;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),c[b[i]]=i;
	for(int i=1;i<=n;i++){
		int id=c[a[i]];
		if(vis[id])continue;
		cnt++;mn[cnt]=INF;
		do{
			sum[cnt]+=w[b[id]];
			sz[cnt]++;
			mn[cnt]=min(mn[cnt],w[b[id]]);
			vis[id]=1;
			id=c[a[id]];
		}while(vis[id]==0);
	}
	LL ans=0;_mn=*min_element(mn+1,mn+cnt+1);
	for(int i=1;i<=cnt;i++){
		ans+=sum[i]-mn[i];
		ans+=min((sz[i]-1)*mn[i],(sz[i]-1)*_mn+2*(_mn+mn[i]));
	}
	printf("%lld\n",ans);
	return 0;
}

