/*
Watchcow
题意：经过每条无向边i,j两次，一次从i到j，一次从j到i，求从1点出发每条路的两个方向都走一遍再回到原点的路径。
分析：把无向图看成有向图，然后求无向图的欧拉回路，欧拉回路，直接标记已走过的边，dfs一遍即可 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct edge{
	int to;bool vis;
	edge(int to):to(to),vis(false){}
};
vector<edge> g[MAXN+3];
void dfs(int u){
	for(int i=0;i<g[u].size();i++) 
		if(!g[u][i].vis)g[u][i].vis=true,dfs(g[u][i].to);
	printf("%d\n",u);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(edge(y));
		g[y].push_back(edge(x));
	}
	dfs(1); 
	return 0;
}

