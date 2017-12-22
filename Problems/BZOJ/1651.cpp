/*
[Usaco2006 Feb]Stall Reservations 专用牛棚
分析：被覆盖的次数最多的点即为答案，差分数组维护 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int cnt[1000000+3],n,mn=INF,mx=0;
int main(){
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++){scanf("%d%d",&l,&r);cnt[l]++;cnt[r+1]--;mn=min(mn,min(l,r));mx=max(mx,max(l,r));}
	for(int i=mn,sum=0;i<=mx;i++){sum+=cnt[i];cnt[0]=max(cnt[0],sum);}
	printf("%d\n",cnt[0]);
	return 0;
}

