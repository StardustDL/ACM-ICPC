/*
Balancing Act
题意：树的最小下标重心 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector> 
using namespace std;
const int MAXN=20000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int ans,n,mx=INF,cnt[MAXN+3],T;
void dfs(int u,int fa){
	cnt[u]=1;int m=0;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		dfs(g[u][i],u);
		cnt[u]+=cnt[g[u][i]];
		m=max(m,cnt[g[u][i]]);
	}
	m=max(m,n-cnt[u]);
	if(m<mx){
		mx=m;
		ans=u;
	}
	else if(m==mx)ans=min(ans,u);
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);ans=0,mx=INF;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		printf("%d %d\n",ans,mx);
	}
	return 0;
}

