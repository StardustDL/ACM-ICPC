#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100000;
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
	edge(int u,int v,int w):u(u),v(v),w(w){}
};vector<edge> es;
int pa[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		es.push_back(edge(u,v,w));
	}
	sort(es.begin(),es.end());
	int cost=0;
	for(int i=0,cur=0;i<es.size()&&cur<n-1;i++){
		edge &e=es[i];
		int u=find(e.u),v=find(e.v);
		if(u==v)continue;
		cost+=e.w;pa[u]=v;
		cur++;
	}
	printf("%d\n",cost);
	return 0;
}