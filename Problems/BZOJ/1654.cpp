/*
[Usaco2006 Jan]The Cow Prom ÄÌÅ£Îè»á
·ÖÎö£ºSCC 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
vector<int> g[MAXN+3];
int dfn[MAXN+3],sum[MAXN+3],low[MAXN+3],dtime=0,scc;
bool ins[MAXN+3];
stack<int> S;
void tarjan(int u){
	dfn[u]=low[u]=++dtime;
	S.push(u);ins[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(dfn[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int cur=-1;scc++;
		while(cur!=u){
			cur=S.top();S.pop();ins[cur]=0;
			sum[scc]++;
		}
	}
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)if(dfn[i]==0)tarjan(i);
	int ans=0;
	for(int i=1;i<=scc;i++)ans+=(sum[i]>1);
	printf("%d\n",ans);
	return 0;
}
