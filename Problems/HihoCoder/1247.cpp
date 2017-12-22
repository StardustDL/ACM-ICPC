#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
vector<int> g[MAXN+3];
int sz[MAXN+3];
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
int to1[MAXN+3],to2[MAXN+3],n;
LL sum[MAXN+3],chi[MAXN+3],ans[MAXN+3],l[MAXN+3];
void dfs(int u,int fa){
	sz[u]=1;sum[u]=0;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		dfs(g[u][i],u);
		sz[u]+=sz[g[u][i]];sum[u]+=sum[g[u][i]];
		if(sz[g[u][i]]>sz[to1[u]]){
			to2[u]=to1[u];to1[u]=g[u][i];
		}
		else if(sz[g[u][i]]>sz[to2[u]]){
			to2[u]=g[u][i];			 
		}
	}
	chi[u]=sum[u];
	if(sz[u]>1)sum[u]+=1LL*sz[to1[u]]*(n-sz[to1[u]]);
}
void calc(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		if(v==to1[u]){
			int t=max(sz[to2[u]],n-sz[u]);
			l[v]=l[u]+chi[u]-sum[v]+1LL*t*(n-t);
		}
		else{
			int t=max(sz[to1[u]],n-sz[u]);
			l[v]=l[u]+chi[u]-sum[v]+1LL*t*(n-t);
		}
		calc(v,u);
	}
	int t=max(sz[to1[u]],n-sz[u]);
	ans[u]=l[u]+chi[u]+1LL*t*(n-t);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	dfs(1,0);calc(1,0);
	LL tot=0;
	for(int i=1;i<=n;i++)tot+=1LL*sz[i]*(n-sz[i]);
	for(int i=1;i<=n;i++)printf("%lld\n",tot-ans[i]);
	return 0;
}
