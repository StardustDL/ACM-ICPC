/*
[SCOI2005]王室联邦
分析：每个省至少要有B个城市，为了能有效的管理，每个省最多只有3B个城市。每个省必须有一个省会，这个省会可以位于省内，也可以在该省外。但是该省的任意一个城市到达省会所经过的道路上的城市（除了最后一个城市，即该省省会）都必须属于该省。一个城市可以作为多个省的省会。
	  仔细读读就会发现其实什么限制都没有，只要>=B就把一颗子树划到一个省，一个点的多棵子树也可以是一个省 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int belong[MAXN+3],cap[MAXN+3],sz[MAXN+3],K,n,B,sta[MAXN+3],top; 
void dfs(int u,int fa){
	sta[++top]=u;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		dfs(g[u][i],u);
		sz[u]+=sz[g[u][i]];
		if(sz[u]>=B){
			cap[++K]=u;sz[u]=0;
			while(sta[top]!=u)belong[sta[top--]]=K;
		}
	}
	sz[u]++;//注意要放在这里，不参与子树部分的 
}
void reset(int u,int fa,int c){//将没分配的随便分分（相邻的省） 
	if(belong[u])c=belong[u];
	else belong[u]=c;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		reset(g[u][i],u,c);
	}
}
int main(){
	scanf("%d%d",&n,&B);
	if(n<B){puts("0");return 0;}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	if(K==0)cap[++K]=1;
	reset(1,0,K);//1号点一定是挨着最后一个省的
	printf("%d\n",K);
	for(int i=1;i<=n;i++)printf("%d ",belong[i]);
	printf("\n");
	for(int i=1;i<=K;i++)printf("%d ",cap[i]);
	printf("\n"); 
	return 0;
}

