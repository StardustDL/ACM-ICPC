/*
商务旅行
分析：LCA，d[cur]+d[u]-2*d[lca(cur,u)]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=30000,POW=18;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3],f[MAXN+3][POW+1];//这里要POW+1
void add(int u,int v){
	es.push_back((edge){u,v});
	es.push_back((edge){v,u});
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=POW;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v!=fa){
			dfs(e.v,u);
		}
	}
}
int lca(int a,int b){
	if(d[a]>d[b])swap(a,b);
	if(d[a]!=d[b]){
		int h=d[b]-d[a];
		for(int i=0;i<=POW;i++)
			if((1<<i)&h)b=f[b][i];
	}
	if(a!=b){
		for(int i=POW;i>=0;i--){
			if(f[a][i]!=f[b][i])
				a=f[a][i],b=f[b][i];
		}
		a=f[a][0];
		b=f[b][0];
	}
	return a;
}
int n,u,v,ans=0,cur=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->1){
		cin>>u>>v;
		add(u,v);
	}
	cin>>n;
	dfs(1,0);
	while(n-->0){
		cin>>u;
		ans+=d[cur]+d[u]-2*d[lca(cur,u)];
		cur=u;
	}
	cout<<ans;
	return 0;
}
