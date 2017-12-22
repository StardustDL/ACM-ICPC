/*
Éñ¾­ÍøÂç
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
int U[MAXN+3],C[MAXN+3],n;
vector<int> g[MAXN+3];
vector<edge> es;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
}
queue<int> q;
bitset<MAXN+3> inq=0;
bitset<MAXN+3> iso=0; 
int main(){
	int p;scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&C[i],&U[i]);
		if(C[i]){q.push(i);inq[i]=1;}
		else C[i]=-U[i];
	}
	for(int u,v,w;p;p--){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(g[u].size()==0)iso[u]=1;
		if(C[u]<=0)continue;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			C[e.v]+=C[u]*e.w;
			if(!inq[e.v]){
				q.push(e.v);
				inq[e.v]=1;
			}
		}
	}
	int flg=0;
	for(int i=1;i<=n;i++)
		if(iso[i]&&C[i]>0)printf("%d %d\n",flg=i,C[i]);
	if(!flg)puts("NULL");
	return 0;
}

