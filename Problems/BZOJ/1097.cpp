/*
[POI2007]旅游景点atr
分析：dijkstra，然后状压DP，为什么下面的代码有奇葩错误= = 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset> 
using namespace std;
const int MAXN=20000,MAXK=20,INF=0x3f3f3f3f;
int n,m,k;
int dis[MAXK+3][MAXK+3];
int opt[1<<20][MAXK+3];
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
struct node{
	int p,d;
	node(int p,int d):p(p),d(d){}
	bool operator <(const node &t)const{
		return d>t.d;
	}
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
priority_queue<node> q;
int d[MAXN+3];
void dijkstra(int u){
	memset(d,INF,sizeof(d));
	while(!q.empty())q.pop();
	d[u]=0;q.push(node(u,0));
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
	for(int i=1;i<=k+1;i++)dis[u][i]=d[i];
	dis[u][0]=d[n];
}
int condi[MAXK+3],bit[MAXN+3];
void solve(){
	memset(opt,-1,sizeof(opt));
	opt[0][1]=0;
	for(int sta=0;sta<=(1<<k)-1;sta++){
		for(int u=1;u<=k+1;u++){
			if(opt[sta][u]==-1)continue;
			for(int i=2;i<=k+1;i++){
				if((sta&condi[i])!=condi[i])continue;
				int nst=sta|bit[i-2];
				if(opt[nst][i]==-1||(opt[nst][i]>opt[sta][u]+dis[u][i])){
					opt[nst][i]=opt[sta][u]+dis[u][i];
				}
			}
		}
	}
}
void init(){
	for(int i=0;i<=k+1;i++)bit[i]=1<<i;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	scanf("%d",&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		condi[b]+=bit[a-2];
	}
	for(int i=1;i<=k+1;i++)dijkstra(i);
	/*for(int i=1;i<=k+1;i++){
		for(int j=1;j<=k+1;j++)printf("%d ",dis[i][j]);
		puts("");
	}*/
	solve();
	int ans=INF;
	for(int i=1;i<=k+1;i++)if(opt[(1<<k)-1][i]!=-1)ans=min(ans,opt[(1<<k)-1][i]+dis[i][0]);
	printf("%d\n",ans);
	return 0;
}

