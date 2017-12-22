/*
[Usaco2006 Nov]Roadblocks第二短路
分析：直接跑记录最短路次短路总是觉得虚，如果次短路更新次短路呢
	  于是从1跑一遍，从n跑一遍，枚举每条边，计算 1->u + w + v->n的长度。选大于最短路的最小的。注意是双向边 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector> 
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
int n,m;
vector<edge> es;
vector<int> g[MAXN+3];
struct node{int p,d;bool operator <(const node &t)const{return d>t.d;}node(int p,int d):p(p),d(d){}};
priority_queue<node> q;
int d1[MAXN+3],d2[MAXN+3];
void dijkstra(int s,int* d){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)d[i]=INF;
	d[s]=0;
	q.push(node(s,d[s]));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.d>d[t.p])continue;
		for(int i=0;i<g[t.p].size();i++){
			edge &e=es[g[t.p][i]];
			if(d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				q.push(node(e.v,d[e.v]));
			}
		}
	}
}
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w);
	}
	dijkstra(1,d1);dijkstra(n,d2);
	int ans=INF,res=d1[n];
	for(int i=0;i<m;i++){
		int t=d1[es[2*i].u]+es[2*i].w+d2[es[2*i].v];
		if(t<ans && t>res)ans=t;
		t=d1[es[2*i].v]+es[2*i].w+d2[es[2*i].u];//注意是双向 
		if(t<ans && t>res)ans=t;
	}
	printf("%d\n",ans);
	return 0;
}

