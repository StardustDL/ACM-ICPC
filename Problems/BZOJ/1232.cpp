/*
[Usaco2008Nov]°²Î¿ÄÌÅ£cheer
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int n,p,c[MAXN+3];
struct edge{int u,v,w;edge(int u,int v,int w):u(u),w(w),v(v){} bool operator <(const edge &e)const{return w<e.w;}};
vector<edge> es;
int pa[MAXN+3],ans=0;
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1,u,v,w;i<=p;i++){
		scanf("%d%d%d",&u,&v,&w);
		es.push_back(edge(u,v,2*w+c[u]+c[v]));
	}
	sort(es.begin(),es.end());
	for(int i=0,t=0;i<es.size()&&t<n-1;i++){
		int a=find(es[i].u),b=find(es[i].v);
		if(a==b)continue;
		t++;ans+=es[i].w;pa[a]=b;
	}
	printf("%d\n",ans+*min_element(c+1,c+n+1));
	return 0;
}

