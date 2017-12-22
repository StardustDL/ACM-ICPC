/*
Street Directions
题意：将一个无向图改成有向图，使其成为强连通，输出所有的边。
分析：我们可以求无向图的边双连通分量，对于同一个双连通分量，只需保留单边即可构成强连通（dfs一遍），而不同的双连通分量则需保留双向边。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct edge{
	int u,v;
	bool isbridge,isprint;
	edge(int u,int v):u(u),v(v),isbridge(false),isprint(false){}
};
vector<int> g[MAXN+3];
vector<edge> es;
int dfsn[MAXN+3],low[MAXN+3],tme=0;
bitset<MAXN+3> vis;
void addedge(int u,int v){
	es.push_back(edge(u,v));
	g[u].push_back(es.size()-1);
}
void init(int n){
	tme=0;memset(dfsn,0,sizeof(dfsn));memset(low,0,sizeof(low));
	vis=0;es.clear();
	for(int i=1;i<=n;i++)g[i].clear(); 
}
void tarjan(int u,int pre){
	low[u]=dfsn[u]=++tme;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==pre)continue;
		if(!dfsn[e.v]){
			tarjan(e.v,u);
			low[u]=min(low[u],low[e.v]);
			if(low[e.v]>dfsn[u]){
				e.isbridge=es[g[u][i]^1].isbridge=1;
			}
		}
		else low[u]=min(low[u],low[e.v]);
	}
}
void dfs(int u,int pa){
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.isbridge)continue;//不能走桥边 
		if(es[g[u][i]^1].isprint==0)e.isprint=1;
		if(!vis[e.v])dfs(e.v,u);
	}
}
int main(){
	int u,v,n,m,kase=0;
	while(scanf("%d%d",&n,&m),n+m){
		init(n);
		while(m--){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u); 
		}
		tarjan(1,-1);
		for(int i=1;i<=n;i++)if(!vis[i])dfs(i,-1); 
		printf("%d\n\n",++kase);
		for(int i=0;i<es.size();i++){
			if(es[i].isbridge||es[i].isprint)printf("%d %d\n",es[i].u,es[i].v);
		}
		puts("#");
	}
	return 0;
}

