/*
花神游历各国
分析：开根号有一个有趣的性质：sqrt(1) = 1,sqrt(0) = 0，而且所有的数字经过有限次的开根号运算都会变成1。
		对整个序列维护树状数组，利用并查集维护每个数右边第一个不是1的数字，然后暴力开根号，当一个数字变成1的时候就把这个点在并查集中的父亲连到它右边的数的父亲上。在修改连续区间的时候就可以跳过连续的1了。
		线段树做法：我们对每一个点暴力开根号，然后当这个店的点权变成1的时候就打一个标记，下次不管这个点了。用线段树维护。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
int n,a[MAXN+3],m;
LL c[MAXN+3];
#define lowbit(x) (x&-x)
void add(int x,int ad){
	for(;x<=n;x+=lowbit(x))c[x]+=ad;
}
LL sum(int x){
	LL ans=0;
	for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
int pa[MAXN+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]); 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);add(i,a[i]);
		if(a[i]<=1)pa[i]=i+1;
		else pa[i]=i;
	}
	pa[n+1]=n+1;
	scanf("%d",&m);
	for(int i=1,x,l,r;i<=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1){printf("%lld\n",sum(r)-sum(l-1));}
		else{
			for(l=find(l);l<=r;l=find(l+1)){
				add(l,-a[l]);
				a[l]=sqrt(a[l])+(1e-7);
				add(l,a[l]);
				if(a[l]<=1)pa[l]=find(l+1);
			}
		}
	}
	return 0;
}


