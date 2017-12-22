/*
[Shoi2007]Vote 善意的投票
分析：注意到每个人只有两种选择，结果最小，最小割！
	  S->赞同  c=1 
	  反对->T  c=1 
	  朋友<->朋友  c=1 注意要连双向 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=300+5,INF=0x3f3f3f3f;
struct edge{
	int u,v,c,f;
	edge(int u,int v,int c):u(u),v(v),c(c),f(0){};
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> q;
int d[MAXN+3],cur[MAXN+3];
int S,T;
void addedge(int u,int v,int c){
	es.push_back(edge(u,v,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,0));
	g[v].push_back(es.size()-1);
}
bool bfs(){
	memset(d,INF,sizeof(d));
	d[S]=0;while(!q.empty())q.pop();q.push(S);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(d[e.v]<INF || e.c-e.f==0)continue;
			d[e.v]=d[u]+1;
			q.push(e.v); 
		}
	}
	return d[T]<INF;
}
int dfs(int u,int a){
	if(u==T || a==0)return a;
	int flow=0,f;
	for(int i=cur[u];i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
			e.f+=f;
			es[g[u][i]^1].f-=f;
			a-=f;flow+=f;
			if(a==0)break;
		}
	}
	return flow;
}
int augment(){
	int ans=0;
	while(bfs()){memset(cur,0,sizeof(cur));ans+=dfs(S,INF);}
	return ans;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	S=n+1,T=S+1;
	for(int i=1,x;i<=n;i++){scanf("%d",&x);if(x)addedge(S,i,1);else addedge(i,T,1);}
	for(int i=1,a,b;i<=m;i++){scanf("%d%d",&a,&b);addedge(a,b,1);addedge(b,a,1);}
	printf("%d\n",augment());
	return 0;
}

