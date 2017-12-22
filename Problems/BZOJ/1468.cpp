/*
Tree
分析：点分治，POJ1741
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=40000;
struct edge {
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w) {}
};
int N,K;
vector<int> g[MAXN+3];
bitset<MAXN+3> vis=0;
vector<edge> es;
void addedge(int u,int v,int w) {
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
namespace TreeCenter {
	int sz[MAXN+3],ans,mx,n;
	void dfs(int u,int fa) {
		sz[u]=1;
		int res=0;
		for(int i=0; i<g[u].size(); i++) {
			edge &e=es[g[u][i]];
			if(e.v==fa||vis[e.v])continue;
			dfs(e.v,u);
			sz[u]+=sz[e.v];
			res=max(res,sz[e.v]);
		}
		res=max(res,n-sz[u]);
		if(res<mx) {
			ans=u,mx=res;
		}
	}
	int getCenter(int root) {
		ans=0,mx=INF;
		dfs(root,-1);
		return ans;
	}
}
vector<int> dat;
int dis[MAXN+3];
void builddata(int u,int pa) {
	dat.push_back(dis[u]);
	for(int i=0; i<g[u].size(); i++) {
		edge &e=es[g[u][i]];
		if(e.v==pa||vis[e.v])continue;
		dis[e.v]=dis[u]+e.w;
		builddata(e.v,u);
	}
}
int calc(int u,int d) {
	dis[u]=d;
	dat.clear();
	builddata(u,-1);
	sort(dat.begin(),dat.end());
	int ans=0,l=0,r=dat.size()-1;
	while(l<r) {
		if(dat[l]+dat[r]<=K)ans+=r-l++;
		else r--;
	}
	return ans;
}
int ans=0;
void solve(int u) {
	ans+=calc(u,0);
	vis[u]=1;
	for(int i=0; i<g[u].size(); i++) {
		edge &e=es[g[u][i]];
		if(vis[e.v])continue;
		ans-=calc(e.v,e.w);
		TreeCenter::n=TreeCenter::sz[e.v];
		solve(TreeCenter::getCenter(e.v));
	}
}
int Ans(int root) {
	ans=0;
	vis=0;
	TreeCenter::n=N;
	solve(TreeCenter::getCenter(root));
	return ans;
}
int main() {
	scanf("%d",&N);
	es.clear();
	for(int i=1; i<=N; i++)g[i].clear();
	for(int i=1; i<N; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	scanf("%d",&K);
	printf("%d\n",Ans(1));
	return 0;
}

