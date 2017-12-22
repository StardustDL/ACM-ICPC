/*
题意：有两个小孩在玩游戏，他们每一个人在树中取一个点，如果这两个点之间的路径长度之和是3的倍数，那么聪聪就赢了，否则他就输了。给出这棵树，求聪聪赢的概率，答案用分数表示。
分析：数据范围2w，肯定不能枚举点然后LCA。所以就只能点分治了。这还是一道比较常规的点分治问题，但是有一个地方需要注意，
	  在统计两点之间的距离的时候我一开始的想法是直接n^2的枚举，然后记录。但是那样时间复杂度就会严重退化。但是注意到我们只需要%3==0的数的个数，和这个有关的之后%3==0，%3==1，%3==2的数。所以在统计的时候我们只要统计这三种数字的个数就可以了。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20000;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> es;
vector<int> g[MAXN+3];
bool vis[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
}
namespace TCenter{
	int sz[MAXN+3],ans,mn,n;
	void dfs(int u,int fa){
		sz[u]=1;int mx=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.v==fa||vis[e.v])continue;
			dfs(e.v,u);
			sz[u]+=sz[e.v];
			mx=max(mx,sz[e.v]);
		}
		mx=max(mx,n-sz[u]);
		if(mx<mn){
			mn=mx;
			ans=u;
		}
	}
	int getCenter(int root,int n){
		ans=0;mn=INF;TCenter::n=n;
		dfs(root,-1);
		return ans;
	}
};
int ans=0,dis[3];
void getdis(int u,int fa,int d){
	dis[d%3]++;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa||vis[e.v])continue;
		getdis(e.v,u,d+e.w);
	}
}
int calc(int u,int d){
	int res=0;memset(dis,0,sizeof(dis));
	getdis(u,0,d);
	res+=dis[0]*dis[0]+((dis[1]*dis[2])<<1);
	return res;
}
int partation(int u){
	//puts("!!!");
	ans+=calc(u,0);
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(vis[e.v])continue;
		ans-=calc(e.v,e.w);
		int k=TCenter::getCenter(e.v,TCenter::sz[e.v]);
		//printf("%d\n",k);
		partation(k);
	}
}
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z%3);
		addedge(y,x,z%3);
	}
	memset(vis,0,sizeof(vis));
	partation(TCenter::getCenter(1,n));
	int g=gcd(ans,n*n);
	printf("%d/%d",ans/g,n*n/g);
	return 0;
}

