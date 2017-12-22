/*
Minimum Cost
题意：有N个供给商，M个雇主，K种物品。每个供给商对每种物品的的供给量已知，每个雇主对每种物品的需求量的已知，从不同的供给商输送不同的货物到不同的雇主手上需要不同的花费，又已知从供给商Mj送第kind种货物的单位数量到雇主Ni手上所需的单位花费。
      问：供给是否满足需求？若是满足，最小运费是多少？ 
分析：1、供给是否满足需求
    	首先我们要看供给是否满足需求，要求最小费用，必须先满足供给大于等于需求才可以。我们必须求出第k种货物的总供给量和总消费量。如果有一种货物的消费量大于供给量，那么直接输出-1，不过记住要先将题目的输入读完，否则wa到死。然后只有供给大于需求，才能找出最小值，也一定能找到最小值。
      2、 最小费用最大流
    	从题目明显看出由于是n个人，所以死多源点多汇点的最小费用最大流。但是其实题目已经给出了提示，后面是k个N*M的矩阵，其实就是想让我们先计算每一种货物的最小费用，然后求和即可。通过分析很容易发现，这k中货物的最小费用毫不相干，不会相互影响。
      3、 那么如何建图呢
    	源点s和汇点t，定义各点编号如下：源点s编号为0，供给商编号从1到M，雇主编号从M+1到M+N，汇点t编号为M+N+1。总结点数nmax=M+N+2，申请每条边的“花费”空间map[nMax][ nMax]和“容量”空间cap[nMax][ nMax]，并初始化为全0。源点s向所有供给商M建边，费用为0，容量为供给商j的供给量。
   		每个供给商都向每个雇主建边，正向弧费用为输入数据的第k个矩阵，容量为供给商j的供给量；反向弧费用为正向弧费用的负数，容量为0。
    	所有雇主向汇点t建边，费用为0，容量为雇主i的需求量。
      4、算法实现
    	对每个物品单独求解，对于第k种物品的图，用spfa算法求解最小费用路径（增广流链），在这条路径上求出流量的最小值，其实也是最大的流量，然后在路径上正向减去此流量，反向加上此流量，费用为单价乘以此流量。 
      自己的代码在spfa停不住 [DEBUG] 
*/
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c));
	es.push_back(edge(v,u,-w,c));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
vector<int> minipaths;
int dis[MAXN+3],l[MAXN+3];
queue<int> q;
bitset<MAXN+3> inq;
int n,m,k,nd[MAXN+3][MAXN+3],has[MAXN+3][MAXN+3],cost[MAXN+3][MAXN+3],ndk[MAXN+3],hask[MAXN+3];
int spfa(int u,int v,int n){
	minipaths.clear();
	while(!q.empty())q.pop();
	memset(l,0,sizeof(l));
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[u]=0;
	inq=0;
	inq[u]=1;
	q.push(u);
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			if(dis[t]+e.w<dis[e.v]&&e.c-e.f>0){
				dis[e.v]=dis[t]+e.w;
				l[e.v]=g[t][i];
				if(!inq[e.v]){
					inq[e.v]=1;q.push(e.v);
				}
			}
		}
	}
	int rel=INF;
	if(dis[v]!=INF)
		for(int i=v;i!=u;i=es[l[i]].u){
			minipaths.push_back(l[i]);
			rel=min(rel,es[l[i]].c-es[l[i]].f);
		}
	return dis[v]==INF?-1:rel;
}
void augment(int s,int t,int n){
	int mn=0;
	while((mn=spfa(s,t,n))!=-1){
		for(int i=0;i<minipaths.size();i++){
			edge &a=es[minipaths[i]];
			edge &b=es[minipaths[i]^1];
			a.f+=mn;
			b.f-=mn;
		}
	}
}
int Ans(){
	int ans=0;
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		if(e.f!=0)ans+=e.f*e.w;
	}
	//cout<<ans<<endl;
	return ans;
}
void init(int n){
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	while(scanf("%d%d%d",&n,&m,&k),n+m+k>0){
		int s=n+m+2,t=s+1,ans=0;
		memset(hask,0,sizeof(hask));
		memset(ndk,0,sizeof(ndk));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&nd[i][j]);
				ndk[j]+=nd[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&has[i][j]);
				hask[j]+=has[i][j];
			}
		}
		bool flg=1;
		for(int i=1;i<=k;i++){if(ndk[i]>hask[i]){flg=0;break;}}
		for(int tk=1;tk<=k;tk++){
			init(t+1);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					scanf("%d",&cost[i][j]);
				}
			}
			if(!flg)continue;
			for(int i=1;i<=n;i++)addedge(i,t,0,nd[i][tk]);
			for(int i=1;i<=m;i++)addedge(s,n+i,0,has[i][tk]);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					addedge(n+j,i,cost[i][j],INF);
				}
			}
			augment(s,t,t+1);
			
			ans+=Ans();
		}
		if(flg)printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define N 130
#define inf 100000000
int need[N][N];
int offer[N][N];
int map[N][N],cost[N][N];
int sum_need[N],sum_offer[N];
int n,m,K;
int pre[N];
int s,t;//源点和结束点
int spfa(){
	int dis[N];
	bool vis[N];
	int i;
	queue<int>q;
	for(i=0; i<=t; i++){
		vis[i]=false;
		dis[i]=inf;
	}
	vis[s]=true;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		vis[k]=false;
		q.pop();
		for(i=0; i<=t; i++){
			if(map[k][i] && dis[i]>dis[k]+cost[k][i]){
				dis[i]=dis[k]+cost[k][i];
				pre[i]=k;
				if(vis[i]==false){
					vis[i]=true;
					q.push(i);
				}
			}
		}
	}
	if(dis[t]!=inf)return 1;
	else return 0;
}
int fond(){
	int i,j;
	int Min=INT_MAX;
	j=0;
	while(spfa()){
		for(i=t;i!=s; i=pre[i])Min=min(Min,map[pre[i]][i]);
		for(i=t; i!=s; i=pre[i]){
			map[pre[i]][i]-=Min;
			map[i][pre[i]]+=Min;
			j+=cost[pre[i]][i]*Min;
		}
	}
	return j;
}
int main(){
	int i,j,k,sum,sign;
	while(scanf("%d%d%d",&n,&m,&K)){
		if(n==0 && m==0 && K==0)break;
		sum=0;
		memset(sum_need,0,sizeof(sum_need));
		memset(sum_offer,0,sizeof(sum_offer));
		for(i=1; i<=n; i++)
			for(j=1; j<=K; j++){
				scanf("%d",&need[i][j]);
                sum_need[j]+=need[i][j];
			}
        for(i=1; i<=m; i++)
		   	for(j=1; j<=K; j++){
				scanf("%d",&offer[i][j]);
				sum_offer[j]+=offer[i][j];
			}
		sign=0;
		for(i=1; i<=K; i++)
			if(sum_offer[i]<sum_need[i]){sign=1;break;} 
		s=0;t=m+n+1; 
		for(k=1; k<=K; k++){
			for(i=0; i<=t; i++)
				for(j=0; j<=t; j++)
					map[i][j]=cost[i][j]=0;
			for(i=1+m; i<=n+m; i++)
				for(j=1; j<=m; j++){
					scanf("%d",&cost[j][i]);
					cost[i][j]=-cost[j][i];
				} 
		    if(sign==1)continue;  
		    for(i=1; i<=m; i++)
			   map[s][i]=offer[i][k];
	    	for(i=1; i<=m; i++)
			   for(j=1+m; j<=n+m; j++)
				 map[i][j]=offer[i][k];  
		   for(i=m+1; i<=m+n; i++)map[i][t]=need[i-m][k];
		  sum+=fond();
		}
		if(sign==1)printf("-1\n");
		else printf("%d\n",sum);
	}
    return 0;
}
