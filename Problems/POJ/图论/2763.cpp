/*
Housewife Wind
���⣺��n���ڵ����������ÿ���ߵ�Ȩֵ����Ӧ���ֲ�����
      0 x ��� ��ǰ�ڵ㵽 x�ڵ����̾��룬���ƶ��� x �ڵ�λ��
     1 x val   �ѵ� x ���ߵ�Ȩֵ��Ϊ val 
���������������ڵ�a,b�ľ������ת��Ϊ
      dis[a] + dis[b] - 2*dis[lca(a,b)]
      ���� dis[i] ��ʾ i �ڵ㵽���ľ��룬
      ����ÿ���޸�һ���ߣ��������������·��� dis[] ֵȫ�����ܵ�Ӱ�죬����ÿ���߶���Ӧ��һ�������ߵĹ�Ͻ����
      �������ѱ�������õ��ʱ�����ll[i] ��ʾ��һ�α������õ��ʱ����� rr[i] ��ʾ���ݵ��õ�ʱ��ʱ���������ÿ��
      �޸ı� i ��ʱ��Ϳ��Զ����� [ ll[i], rr[i] ] ���гɶθ��£��ɶθ��µķ�ʽ������ λ�� ll[i] �ϼ�һ��Ȩֵ����λ��
      rr[i]+1 �ϼ�ȥ���Ȩֵ�����ʱ��sum(ll[i]) ��Ϊ�õ㵽���ľ��롣 
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

