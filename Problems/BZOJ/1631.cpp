/*
[Usaco2007 Feb]Cow Party
分析：两遍最短路 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	bool isn;
	edge(int u,int v,int w,bool isn):u(u),v(v),w(w),isn(isn){}
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w,0));
	es.push_back(edge(v,u,w,1));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1); 
}
int d[2][MAXN+3];
struct node{
	int p,ds;
	node(int p,int ds):p(p),ds(ds){}
	bool operator <(const node &t)const{
		return ds>t.ds;
	}
};
priority_queue<node> q;
void dijkstra(int s,bool isn){
	while(!q.empty())q.pop();
	memset(d[isn],INF,sizeof(d[isn]));
	d[isn][s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.ds!=d[isn][t.p])continue;
		for(int i=0;i<g[t.p].size();i++){
			edge &e=es[g[t.p][i]];
			if(isn!=e.isn)continue;
			if(d[isn][e.v]>d[isn][e.u]+e.w){
				d[isn][e.v]=d[isn][e.u]+e.w;
				q.push(node(e.v,d[isn][e.v]));
			}
		}
	}
}
bitset<MAXN+3> inq;
queue<int> sq;
void spfa(int s,bool isn){
	while(!sq.empty())sq.pop();
	memset(d[isn],INF,sizeof(d[isn]));
	d[isn][s]=0;
	inq=0;inq[s]=1;
	sq.push(s);
	while(!sq.empty()){
		int u=sq.front();sq.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(isn!=e.isn)continue;
			if(d[isn][e.v]>d[isn][u]+e.w){
				d[isn][e.v]=d[isn][u]+e.w;
				if(!inq[e.v]){
					inq[e.v]=1;
					sq.push(e.v);
				}
			}
		}
	}
}
int n,m,x;
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	spfa(x,0);
	spfa(x,1);
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<d[0][i]<<" "<<d[1][i]<<endl;
		ans=max(ans,d[0][i]+d[1][i]);
	}
	printf("%d\n",ans);
	return 0;
}


