/*
[Usaco2005 Mar]Checking an Alibi 不在场的证明
分析：最短路，dijkstra 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
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
int f,c,m,p;
vector<int> ans;
void output(const int &d){printf("%d\n",d);}
int main(){
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int u,v,w,i=1;i<=p;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	dijkstra(1);
	for(int i=1,x;i<=c;i++){
		scanf("%d",&x);
		if(d[x]<=m)ans.push_back(i);
	}
	printf("%d\n",ans.size()); 
	for_each(ans.begin(),ans.end(),output);
	return 0;
}

