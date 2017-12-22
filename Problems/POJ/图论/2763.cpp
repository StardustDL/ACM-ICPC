/*
Housewife Wind
题意：有n个节点的树和树上每条边的权值，对应两种操作：
      0 x 输出 当前节点到 x节点的最短距离，并移动到 x 节点位置
     1 x val   把第 x 条边的权值改为 val 
分析：树上两个节点a,b的距离可以转化为
      dis[a] + dis[b] - 2*dis[lca(a,b)]
      其中 dis[i] 表示 i 节点到根的距离，
      由于每次修改一条边，树中在这条边下方的 dis[] 值全都会受到影响，这样每条边都对应这一段这条边的管辖区，
      可以深搜保存遍历该点的时间戳，ll[i] 表示第一次遍历到该点的时间戳， rr[i] 表示回溯到该点时的时间戳，这样每次
      修改边 i 的时候就可以对区间 [ ll[i], rr[i] ] 进行成段更新，成段更新的方式可以在 位置 ll[i] 上加一个权值，在位置
      rr[i]+1 上减去这个权值，求和时，sum(ll[i]) 即为该点到根的距离。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
#include<cmath>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000*2,POW=18;
int dep[MAXN+3],opt[MAXN+3][POW],to[MAXN+3],l[MAXN+3],r[MAXN+3],tme=0,dfsn[MAXN+3],id=0,rr[MAXN+3];
struct edge{
	int u,v,w,id;
	edge(int u,int v,int w,int id):u(u),v(v),w(w),id(id){} 
};
vector<edge> es;
vector<int> g[MAXN+3];
void dfs(int u,int d,int pa){
	dep[++tme]=d;
	dfsn[tme]=u;
	rr[u]=tme;
	l[u]=++id;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==pa)continue;
		to[e.id]=e.v;
		dfs(e.v,d+1,u);
		dfsn[++tme]=u;
		dep[tme]=d;
	}
	r[u]=id;
}
int mindep(int i,int j){
	return dep[i]<dep[j]?i:j;
}
void loadrmq(int n){
	for(int i=1;i<=n;i++)opt[i][0]=i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)<=n;i++){
			opt[i][j]=mindep(opt[i][j-1],opt[i+(1<<j-1)][j-1]); 
		}
	}
}
int rmq(int l,int r){
	int k=(int)(log((r-l+1)*1.0)/log(2.0));
	return mindep(opt[l][k],opt[r-(1<<k)+1][k]); 
} 
namespace BIT{
	int c[MAXN+3],n;
	void add(int x,int ad){
		for(;x<=n;x+=lowbit(x))c[x]+=ad;
	}
	int sum(int x){
		int ans=0;
		for(;x>0;x-=lowbit(x))ans+=c[x];
		return ans;
	}
}
int eid=0,n,m,st,val[MAXN+3];
void addedge(int u,int v,int w){
	eid++;
	es.push_back(edge(u,v,w,eid));
	es.push_back(edge(v,u,w,eid));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
int main(){
	while(scanf("%d%d%d",&n,&m,&st)!=EOF){
		for(int i=1;i<=n;i++)g[i].clear();
		es.clear();
		memset(BIT::c,0,sizeof(BIT::c));
		tme=id=eid=0;
		int a,b,c;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			val[i]=c;addedge(a,b,c);
		}
		dfs(1,0,-1);
		loadrmq(2*n);
		BIT::n=n;
		for(int i=1;i<n;i++){
			BIT::add(l[to[i]],val[i]);
			BIT::add(r[to[i]]+1,-val[i]);
		}
		while(m--){
			scanf("%d",&a);
			if(a==1){
				scanf("%d%d",&b,&c);
				BIT::add(l[to[b]],-val[b]);
				BIT::add(r[to[b]]+1,val[b]);
				BIT::add(l[to[b]],c);
				BIT::add(r[to[b]]+1,-c);
				val[b]=c;
			}
			else {
				scanf("%d",&b);
				printf("%d\n",
					BIT::sum(l[st])+BIT::sum(l[b])
					-2*BIT::sum(l[dfsn[rmq(min(rr[st],rr[b]),max(rr[st],rr[b]))]])); 
				st=b;
			}
		}
	}
	return 0;
}

