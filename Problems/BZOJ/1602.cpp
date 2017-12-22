/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,POW=10;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> es;
int pa[MAXN+3][POW+1],dep[MAXN+3],n,q,len[MAXN+3];
vector<int> g[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	pa[u][0]=fa;
	for(int i=1;i<=POW;i++)pa[u][i]=pa[pa[u][i-1]][i-1];
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa)continue;
		len[e.v]=len[u]+e.w;
		dfs(e.v,u);
	}
}
int lca(int a,int b){
	if(dep[a]>dep[b])swap(a,b);
	int h=dep[b]-dep[a];
	
	for(int i=0;i<=POW;i++)if(h&(1<<i))b=pa[b][i];//cout<<h<<endl;
	for(int i=POW;i>=0;i--){
		if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
	}
	if(a==b)return b;
	else return pa[b][0];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,a,b,l;i<n;i++){
		scanf("%d%d%d",&a,&b,&l);
		addedge(a,b,l);
	}
	dfs(1,0);
	for(int p1,p2;q;q--){
		scanf("%d%d",&p1,&p2);
		//cout<<"!!!"<<lca(p1,p2)<<endl ;
		printf("%d\n",len[p1]+len[p2]-2*len[lca(p1,p2)]);
	}
	return 0;
}
