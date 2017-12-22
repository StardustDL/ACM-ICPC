/*
[POI2015]Wilcze do?y
分析：维护长度为d的区间的区间和的单调减队列，维护当前满足sum[l..r]-maxsumd<=P的sum[l..r]及其左端点，单调队列即可。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000000,INF=0x3f3f3f3f;
typedef long long LL;
int p[MAXN+3],head=1,tail=0,w[MAXN+3],n,d,lp,ans=0;
LL P,q[MAXN+3];
int main(){
	scanf("%d%lld%d",&n,&P,&d);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	LL sum=0,sumd=0;lp=1;
	for(int i=1;i<d;i++)sumd+=w[i];sum=sumd;
	for(int i=d;i<=n;i++){
		sum+=w[i];sumd=sumd+w[i]-w[i-d];
		while(head<=tail && sumd>q[tail])tail--;
		q[++tail]=sumd;p[tail]=i-d+1;
		while(sum-q[head]>P){sum-=w[lp++];while(head<=tail && p[head]<lp)head++;}
		ans=max(ans,i-lp+1);
	}
	printf("%d\n",ans);
	return 0;
}

