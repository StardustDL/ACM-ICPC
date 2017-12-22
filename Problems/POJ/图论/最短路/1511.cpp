/*
题意：给定节点数n,和边数m,边是单向边.问从1节点出发到2,3,...n 这些节点路程和从从这些节点回来到节点1的路程和最小值。
分析：很显然的最短路，先以1为起点进行一次最短路，然后再将边反向一下再以1为起点进行一下最短路。
	  注意开long long  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
typedef long long LL;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> all;
vector<edge> es;
vector<int> g[MAXN+3];
int n;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1); 
} 
void input(){
	int m;
	scanf("%d%d",&n,&m);all.clear();
	for(int a,b,c;m;m--){
		scanf("%d%d%d",&a,&b,&c);
		all.push_back(edge(a,b,c));
	}
}
void load(bool flg){
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=0;i<all.size();i++){
		if(flg)addedge(all[i].u,all[i].v,all[i].w);
		else addedge(all[i].v,all[i].u,all[i].w);
	}
}
struct node{
	int p,d;
	bool operator <(const node &t)const{return d>t.d;} 
	node(int p,int d):p(p),d(d){}
};
priority_queue<node> q;
int d[MAXN+3];
LL dijkstra(int s){
	while(!q.empty())q.pop();
	memset(d,INF,sizeof(d));
	d[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.d>d[t.p])continue;
		for(int i=0;i<g[t.p].size();i++){
			edge &e=es[g[t.p][i]];
			if(d[e.u]+e.w<d[e.v]){
				d[e.v]=d[e.u]+e.w;
				q.push(node(e.v,d[e.v]));
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++)ans+=d[i];
	return ans;
}
int main(){
	int T;LL ans;
	for(scanf("%d",&T);T;T--){
		input();ans=0;
		load(true);ans+=dijkstra(1);
		load(false);ans+=dijkstra(1);
		printf("%lld\n",ans);
	}
	return 0;
}

