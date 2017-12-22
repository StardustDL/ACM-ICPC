/*
[POI2008]BLO
分析：无向图连通性
	  注意删去一个点X，那这个点和其他点都不联通，所以就有n-1个点对了，然后如果X是割点，就会有更多的点对：
	  删去割点，会得到一些联通块：A,B,C，注意这里是有序点对 
	  ans[X]=2*(n-1)+A*(B+C)+B*(A+C)+C*(A+B)
	  		=(n-1+A*B+(A+B)*C)*2
	  	这种变形将n^2降到了n 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int low[MAXN+3],dfn[MAXN+3],tme=0,sz[MAXN+3],n,m;
LL ans[MAXN+3];
void tarjan(int x){
	dfn[x]=low[x]=++tme;sz[x]=1;int sum=0;
	for(int i=0,to;i<g[x].size();i++){
		to=g[x][i];
		if(dfn[to])low[x]=min(low[x],dfn[to]);
		else{
			tarjan(to);
			sz[x]+=sz[to];
			low[x]=min(low[x],low[to]);
			if(low[to]>=dfn[x]){
				ans[x]+=(LL)sum*sz[to];
				sum+=sz[to];
			}
		}
	}
	ans[x]+=(LL)sum*(n-sum-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int a,b;m;m--){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	tarjan(1);
	for(int i=1;i<=n;i++)printf("%lld\n",(ans[i]+n-1)<<1);
	return 0;
}

