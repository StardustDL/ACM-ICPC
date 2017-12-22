#include<iostream>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=2500,MAXM=6200,INF=1<<20;
struct node{
	int dist,pos;
	
	bool operator < (const node &t)const{
		return dist>t.dist; 
	}
};
struct edge{
	int u,v,w;
};
priority_queue<node> q;
int n,m,s,t;
vector<edge> es;
vector<int> g[MAXN+3];
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
int dist[MAXN+3];
int dijkstra(){
	for(int i=1;i<=n;i++)dist[i]=INF;
	dist[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		node p=q.top();q.pop();
		if(dist[p.pos]!=p.dist)continue;
		for(int i=0;i<g[p.pos].size();i++){
			edge &e=es[g[p.pos][i]];
			if(dist[e.v]>dist[p.pos]+e.w){
				dist[e.v]=dist[p.pos]+e.w;
				q.push((node){dist[e.v],e.v});
			}
		}
	}
	return dist[t];
}
int main(){
	cin>>n>>m>>s>>t;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cout<<dijkstra();
	return 0;
}
