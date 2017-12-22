/*
Test for Job
题意：求一个拓扑图的一条由入度为0的点到出度为0的点的最大权值和路径
分析：边拓扑，边DP，注意负数权值 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,m,val[MAXN+3],opt[MAXN+3],rd[MAXN+3];
vector<int> g[MAXN+3];
queue<int> q;
bool input(){
	if(scanf("%d%d",&n,&m)!=2)return false;
	memset(val,0,sizeof(val));
	memset(rd,0,sizeof(rd));
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		opt[i]=-INF;
		g[i].clear();
	}
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		rd[b]++;
		g[a].push_back(b);
	}
	return true; 
}
int dp(){
	for(int i=1;i<=n;i++){
		if(!rd[i]){
			opt[i]=val[i];
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			opt[v]=max(opt[u]+val[v],opt[v]);
			if(--rd[v]==0)q.push(v);
		}
	}
	int ans=-INF;
	for(int i=1;i<=n;i++)
		if(g[i].size()==0)ans=max(ans,opt[i]);
	return ans;
}
int main(){
	while(input())printf("%d\n",dp());
	return 0;
}

