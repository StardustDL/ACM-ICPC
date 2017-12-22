/*
Contestants Division
题意：一棵树，每个节点都有一个正的权值，将树剪断一条边，分成两棵树并使得两棵树的权值和之差的绝对值最小。求最小之差。
分析：dfs一遍，类似重心，但要简单一些 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ABS(a) (((a)<0)?(-(a)):(a))
using namespace std;
typedef long long LL;
const LL INF=1LL<<60,MAXN=100000;
vector<int> g[MAXN+3];
bitset<MAXN+3> vis;
LL sz[MAXN+3],ans=INF,val[MAXN+3],sum;
int n;
LL Min(LL a,LL b){return a<b?a:b;}
LL Abs(LL a){return a<0?-a:a;}
void dfs(int u,int fa){
	vis[u]=1;
	sz[u]=val[u];
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]!=fa&&!vis[g[u][i]]){
			dfs(g[u][i],u);
			sz[u]+=sz[g[u][i]];
			ans=Min(ans,Abs(sum-(sz[g[u][i]]<<1)));
		}
	}
}
bool input(){
	int a,b;
	scanf("%d%d",&n,&a);if(n+a==0)return false;
	vis=0;memset(sz,0,sizeof(sz));memset(val,0,sizeof(val));ans=INF;sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		sum+=val[i];
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	return true;
}
int main(){
	int kase=0;
	while(input()){
		dfs(1,-1);
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}

