#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){} 
};
vector<edge> es;
vector<int> g[MAXN+3];
int n;
bool input(){
	es.clear();
	int u,v,w;
	if(!(~scanf("%d",&n)))return false;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=2;i<=n;i++){
		scanf("%d%d",&v,&w);
		es.push_back(edge(i,v,w));
		g[u].push_back(es.size()-1);
		es.push_back(edge(v,i,w));
		g[v].push_back(es.size()-1);
	}
	return true;
}
int mxp[MAXN+3][2],opt[MAXN+3],mxid[MAXN+3][2];
int dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa)continue;
		int tmp=dfs(e.v,u)+e.w;
		if(tmp>mxp[u][1]){
			mxp[u][1]=tmp;
			mxid[u][1]=e.v;
			if(mxp[u][1]>mxp[u][0]){
				swap(mxp[u][1],mxp[u][0]);
				swap(mxid[u][1],mxid[u][0]); 
			}
		}
	}
	return mxp[u][0];
}
void solve(int u,int fa,int tmp){
	opt[u]=max(mxp[u][0],tmp); 
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa)continue;
		if(e.v==mxid[u][0]){
			solve(e.v,u,max(mxp[u][1],tmp)+e.w);
		}
		else solve(e.v,u,max(mxp[u][0],tmp)+e.w);
	}
}
int main(){
	while(input()){
		memset(mxp,0,sizeof(mxp));
		dfs(1,0);
		solve(1,0,0);
		for(int i=1;i<=n;i++)printf("%d\n",opt[i]);
	}
	return 0;
}

