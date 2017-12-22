/*
[SCOI2007]修车
分析：把每个工人拆成N个点。记为A[i,j]表示第i个工人修倒数第j辆车。
		每个车跟所有N*M个工人拆出的点连边。流量为1，费用为time[i,j]*(m-k+1)。（time[i][j]*k也可以，因为这边在循环时都会加上 ） 
		源和每辆车连边，N*M个点和汇连边，流量都为1，费用同为0。
		为什么这么构图呢？
		考虑第i个工人，他修第j辆车只对后面要修的车有影响，而前面修过的车已经对当前没有影响了。
			而这个影响就是后面每个将要修理的车都多等待了time的时间。后面要修的就是m-k+1辆车 
			其他边流量都为1是显然的，每辆车修一次，每个工人一个时段只能修理一辆车。
		拆点，使得可以实现修多辆车。
		我们给流网络提供了这些方案，同时限制了总流量，那么流网络会自动选符合条件的最优的。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector> 
#include<cstring>
using namespace std;
const int MAXN=60,MAXM=9,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<int> g[MAXN*MAXM+100+3];
vector<edge> es;
int d[MAXN*MAXM+100+3],p[MAXN*MAXM+100+3];
queue<int> q;
bool inq[MAXN*MAXM+100+3];
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
int ans=0,n,m;
void augment(int s,int t){
	int mn=INF;
	for(int i=p[t];i!=-1;i=p[es[i].u])mn=min(mn,es[i].c-es[i].f);
	for(int i=p[t];i!=-1;i=p[es[i].u])es[i].f+=mn,es[i^1].f-=mn,ans+=mn*es[i].w;
}
int tme[MAXN+3][MAXM+3];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&tme[i][j]);
	int S=n*m+n+2,T=S+1;
	for(int i=1;i<=n*m;i++)addedge(S,i,0,1);
	for(int i=n*m+1;i<=n*m+n;i++)addedge(i,T,0,1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				addedge((i-1)*n+j,n*m+k,tme[k][i]*(n-j+1),1);
	while(spfa(S,T))augment(S,T);
	printf("%.2lf\n",ans*1.0/n);
	return 0;
}

