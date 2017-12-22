/*
[Usaco2006 Open]The Climbing Wall 攀岩
分析：暴力建边，最短路 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<int> g[MAXN+3];
vector<edge> es;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,w));
	g[v].push_back(es.size()-1);
}
int d[MAXN+3];
struct node{
	int p,d;
	node(int p,int d):p(p),d(d){} 
	bool operator <(const node &t)const{
		return d>t.d;
	}
};
priority_queue<node> Q;
void dijkstra(int s){
	memset(d,INF,sizeof(d));
	d[s]=0;
	while(!Q.empty())Q.pop();
	Q.push(node(s,0));
	while(!Q.empty()){
		node u=Q.top();Q.pop();
		if(u.d>d[u.p])continue;
		for(int i=0;i<g[u.p].size();i++){
			edge &e=es[g[u.p][i]];
			if(d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				Q.push(node(e.v,d[e.v]));
			}
		}
	}
}
int h,f,s,t,x[MAXN+3],y[MAXN+3];
int main(){
	scanf("%d%d",&h,&f);
	s=f+1,t=s+1;
	for(int i=1;i<=f;i++){
		scanf("%d%d",&x[i],&y[i]);
		for(int j=1;j<i;j++){
			if(sqr(x[i]-x[j])+sqr(y[i]-y[j])<=sqr(1000))addedge(i,j,1);
		}
		if(y[i]<=1000)addedge(s,i,0);
		if(h-y[i]<=1000)addedge(t,i,1);
	}
	dijkstra(s);
	printf("%d\n",d[t]);
	return 0;
}

