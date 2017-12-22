/*
[Usaco2007 Dec]Building Roads 修建道路
分析：最小生成树 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define sqr(x) ((x)*1.0*(x))
int n,m,tot,cnt;
int x[1005],y[1005],fa[1005];
double ans;
struct edge{int x,y;double v; edge(int x,int y,double v):x(x),y(y),v(v){}};
vector<edge> es;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline double dis(int a,int b){return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));}
inline bool cmp(edge a,edge b){return a.v<b.v;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d%d",&x[i],&y[i]);fa[i]=i;}
	for(int i=1,p,q;i<=m;i++){
		scanf("%d%d",&p,&q);
		p=find(p),q=find(q);
		fa[p]=q;
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    	es.push_back(edge(i,j,dis(i,j)));
	sort(es.begin(),es.end(),cmp);
	for(int i=0,tot=0;i<es.size()&&tot<n-1;i++){
		int p=find(es[i].x),q=find(es[i].y);
		if(p!=q){
			fa[p]=q;
			ans+=es[i].v;
			tot++;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
