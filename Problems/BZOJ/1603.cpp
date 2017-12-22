/*
[Usaco2008 Oct]打谷机
分析：dfs一遍 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
vector<bool> w[MAXN+3];
bool d[MAXN+3];
int n;
void addedge(int a,int b,int c){
	g[a].push_back(b);
	w[a].push_back(c);
	g[b].push_back(a);
	w[b].push_back(c);
}
void dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		d[g[u][i]]=d[u]^w[u][i];
		dfs(g[u][i],u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b,c;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c); 
	}
	dfs(1,0);
	printf("%d\n",d[n]);
	return 0;
}

