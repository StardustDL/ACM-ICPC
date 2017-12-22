/*
[POI2006]Szk-Schools
分析：费用流 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector> 
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=200*2+5,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<int> g[MAXN+3];
vector<edge> es;
int d[MAXN+3],p[MAXN+3];
queue<int> q;
bool inq[MAXN+3];
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,-w,0));
	g[v].push_back(es.size()-1);
}
bool spfa(int s,int t){
	memset(d,INF,sizeof(d));
	memset(p,-1,sizeof(p));
	memset(inq,0,sizeof(inq));
	while(!q.empty())q.pop();
	d[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.c-e.f>0 && d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				p[e.v]=g[u][i];
				if(!inq[e.v]){q.push(e.v);inq[e.v]=1;}
			}
		}
	}
	return d[t]<INF;
}
int ans=0,n,m,flow=0,S,T;
int augment(int s,int t){
	int mn=INF;
	for(int i=p[t];i!=-1;i=p[es[i].u])mn=min(mn,es[i].c-es[i].f);
	for(int i=p[t];i!=-1;i=p[es[i].u])es[i].f+=mn,es[i^1].f-=mn,ans+=mn*es[i].w;
	return mn;
}
int main(){
	scanf("%d",&n);
	S=0;T=2*n+1;
	for(int i=1;i<=n;i++)addedge(S,i,0,1),addedge(n+i,T,0,1);
	for(int i=1,a,b,c;i<=n;i++){
		scanf("%d%d%d%d",&m,&a,&b,&c);
		for(int j=a;j<=b;j++){
			addedge(i,n+j,abs(m-j)*c,1);
		}
	}
	while(spfa(S,T))flow+=augment(S,T);
	if(flow<n)puts("NIE");
	else printf("%d\n",ans);
	return 0;
}
