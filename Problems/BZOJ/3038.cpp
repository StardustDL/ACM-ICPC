/*
上帝造题的七分钟2
分析：基本上同BZOJ3211，数据大了点 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
int n,m;
LL c[MAXN+3],a[MAXN+3];
#define lowbit(x) (x&-x)
void add(int x,LL ad){
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
		scanf("%lld",&a[i]);add(i,a[i]);
		if(a[i]<=1)pa[i]=i+1;
		else pa[i]=i;
	}
	pa[n+1]=n+1;//注意这句，不然会TLE 
	scanf("%d",&m);
	for(int i=1,x,l,r;i<=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(l>r)swap(l,r); 
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

