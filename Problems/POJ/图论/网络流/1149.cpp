/*
PIGS
题意：有M个猪圈，每个猪圈里初始时有若干头猪。一开始所有猪圈都是关闭的。依次来了N个顾客，每个顾客分别会打开指定的几个猪圈，从中买若干头猪。每个顾客分别都有他能够买的数量的上限。每个顾客走后，他打开的那些猪圈中的猪，都可以被任意地调换到其它开着的猪圈里，然后所有猪圈重新关上。问总共最多能卖出多少头猪。（1?<=?N?<=?100,?1?<=?M?<=?1000）??
	  举个例子来说。有3个猪圈，初始时分别有3、1和10头猪。依次来了3个顾客，第一个打开1号和2号猪圈，最多买2头；第二个打开1号和3号猪圈，最多买3头；第三个打开2号猪圈，最多买6头。那么，最好的可能性之一就是第一个顾客从1号圈买2头，然后把1号圈剩下的1头放到2号圈；第二个顾客从3号圈买3头；第三个顾客从2号圈买2头。总共卖出2+3+2=7头。
分析：不难想象，这个问题的网络模型可以很直观地构造出来。
	  就拿上面的例子来说，三个顾客，就有三轮交易，每一轮分别都有3个猪圈和1个顾客的结点。
	  从源点到第一轮的各个猪圈各有一条边，容量就是各个猪圈里的猪的初始数量。
	  从各个顾客到汇点各有一条边，容量就是各个顾客能买的数量上限。
	  在某一轮中，从该顾客打开的所有猪圈都有一条边连向该顾客，容量都是∞。
	  最后一轮除外，从每一轮的i号猪圈都有一条边连向下一轮的i号猪圈，容量都是∞，表示这一轮剩下的猪可以留到下一轮。
	  最后一轮除外，从每一轮被打开的所有猪圈，到下一轮的同样这些猪圈，两两之间都要连一条边，表示它们之间可以任意流通。  
  	  这个网络模型的最大流量就是最多能卖出的数量。图中最多有 2+N+M×N≈100,000个结点。这个模型虽然很直观，但是结点数太多了，计算速度肯定会很慢。其实不用再想别的算法，就让我们继续上面的例子，用合并的方法来简化这个网络模型。  首先，最后一轮中没有打开的猪圈就可以从图中删掉了，也就是图2中红色的部分，显然它们对整个网络的流量没有任何影响。
  	  尝试简化 
		规律1.如果几个结点的流量的来源完全相同，则可以把它们合并成一个。
		规律2.如果几个结点的流量的去向完全相同，则可以把它们合并成一个。
		规律3.如果从点u到点v有一条容量为∞的边，并且点v除了点u以外没有别的流量来源，则可以把这两个结点合并成一个。
	  最后的模型如下：
	  	每个顾客分别用一个结点来表示。对于每个猪圈的第一个顾客，从源点向他连一条边，容量就是该猪圈里的猪的初始数量。
		如果从源点到一名顾客有多条边，则可以把它们合并成一条，容量相加。
		对于每个猪圈，假设有n个顾客打开过它，则对所有整数i∈[1,n)，从该猪圈的第i个顾客向第i?+?1个顾客连一条边，容量为∞。
		从各个顾客到汇点各有一条边，容量是各个顾客能买的数量上限。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct edge{
	int u,v,c,f;
	edge(int u,int v,int c):u(u),v(v),c(c),f(0){}
};
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3],cur[MAXN+3],S,T;
bool vis[MAXN+3];
queue<int> q;
bool bfs(){
	memset(vis,0,sizeof(vis));
	memset(d,-1,sizeof(d));
	q.push(S);d[S]=1;vis[S]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(vis[e.v] || e.c-e.f<=0)continue;
			vis[e.v]=1;d[e.v]=d[u]+1;
			q.push(e.v);
		}
	}
	return vis[T];
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0,f;
	for(int &i=cur[u];i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
			e.f+=f;
			es[g[u][i]^1].f-=f;
			a-=f;
			flow+=f;
			if(a==0)break;
		}
	}
	return flow;
}
int Dinic(int s,int t){
	S=s,T=t;
	int ans=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));
		ans+=dfs(s,INF);
	}
	return ans;
}
void addedge(int u,int v,int c){
	es.push_back(edge(u,v,c));
	es.push_back(edge(v,u,0));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
int m,n,h[MAXN+3],lst[MAXN+3],k,ned,ts,sum; 
int main(){
	scanf("%d%d",&m,&n);
	int s=n+1,t=s+1;
	for(int i=1;i<=m;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);sum=0;
		while(k--){
			scanf("%d",&ts);
			if(lst[ts]==0)sum+=h[ts];
			else addedge(lst[ts],i,INF);
			lst[ts]=i;
		}
		addedge(s,i,sum);
		scanf("%d",&ts);
		addedge(i,t,ts);
	}
	printf("%d",Dinic(s,t));
	return 0;
}

