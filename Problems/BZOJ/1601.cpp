/*
[Usaco2008 Oct]灌水
分析：将点连向超级源，这样就转化成MST了，注意并查集合并时是pa[find(a)]=find(b); 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=300;
struct edge{
	int u,v,w;
	bool operator <(const edge &t)const{
		return w<t.w;
	}
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> es;
int pa[MAXN+3],n,ans=0;
int find(int a){
	return pa[a]==0?a:pa[a]=find(pa[a]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		es.push_back(edge(n+1,i,t));
	}
	for(int i=1,t;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			if(i==j)continue;
			es.push_back(edge(i,j,t));
		}
	}
	sort(es.begin(),es.end());
	for(int i=0,cnt=0;i<es.size()&&cnt<n;i++){
		edge &e=es[i];
		if(find(e.u)==find(e.v))continue;
		pa[find(e.v)]=find(e.u);ans+=e.w;
		cnt++;
	}
	printf("%d\n",ans);
	return 0;
}
