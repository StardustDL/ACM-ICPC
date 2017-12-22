/*
Tree
题意：给你一棵无根树，求有多少点对之间距离<=K。树边带权
分析：一条路径要么过根结点，要么在一棵子树中：点分治
	  只要先求出经过根结点的路径数，再递归的求经过所有子结点的路径数即可。
	  先dp找到重心，以重心进行点分治。
	  如何处理路径过根结点的情况：
	  	先用一次搜索求出根的所有子结点到根的距离并将其放入一个数组中，复杂度O(n)。将这个距离数组排序，复杂度O(nlogn)。
	  	这样就将问题转化为了，求一个数组A中，和小于等于K的元素对个数有多少。
	  	由于数组有序，对于区间[L,R]，易知若A[L]+A[R]>K，那么区间内没有满足条件的元素对。若A[L]+A[R]<=K，则以L为左端点的点对数有R-L个。
	  	我们从1开始枚举L，当前R不满足条件，就令R-1，否则统计以L为左端点的点对数，令L-1。用一个线性扫描的扫描可以解决，复杂度O(n)。
	  	这样得到了所有子结点到根的距离和小于等于K的点对数。然而这个并不是最终解，
		  因为我们要求的是经过根的路径，而从一个子树到达根结点又回到同一个子树的路径是不能被计入统计的，
		  所以我们要把多余的点对从结果中减去。 
	  只要对每一个子树，求出同一个子树中的结点到根结点又回到子树的路径和小于等于K的点对数，然后从答案中减去即可。这一步直接通过分治可解 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
int N,K;
vector<int> g[MAXN+3];
bitset<MAXN+3> vis=0;//维护是否访问过，如果已经访问过（曾经的分治点），就不考虑这个点 
vector<edge> es;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1); 
}
namespace TreeCenter{//求重心 
	int sz[MAXN+3],ans,mx,n;
	void dfs(int u,int fa){
		sz[u]=1;int res=0;//维护结点内大小 
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.v==fa||vis[e.v])continue;
			dfs(e.v,u);
			sz[u]+=sz[e.v];
			res=max(res,sz[e.v]);//选最大的子树，为什么这里写成sz[e.v]-1也能过？ 
		}
		res=max(res,n-sz[u]);//和剩下的点个数比较 
		if(res<mx){//使最大联通块最小 
			ans=u,mx=res;
		}
	}
	int getCenter(int root){
		ans=0,mx=INF;
		dfs(root,-1);
		return ans;
	}
}
vector<int> dat;
int dis[MAXN+3];
void builddata(int u,int pa){//以u为根的子树中，所有点距u的距离，存到dat数组中 
	dat.push_back(dis[u]);
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==pa||vis[e.v])continue;
		dis[e.v]=dis[u]+e.w;
		builddata(e.v,u);
	}
}
int calc(int u,int d){
	dis[u]=d;//初始化u的深度，保证后面d[l]+d[r]<k的正确性 
	dat.clear();
	builddata(u,-1);//计算并提取出u子树内的所有点dis值 
	sort(dat.begin(),dat.end());//排序 
	int ans=0,l=0,r=dat.size()-1;
	while(l<r){//线性扫描，求点对数 
		if(dat[l]+dat[r]<=K)ans+=r-l++;//累计答案，同时左端点右移 
		else r--;
	}
	return ans;
}
int ans=0;
void solve(int u){//处理以u为根的子树，注意相当于将这棵树提取出来单独作为一棵树 
	ans+=calc(u,0);//总点对数，包含不经过根的 
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(vis[e.v])continue;
		ans-=calc(e.v,e.w);//减去子树内的可行点对数，注意传值 
		TreeCenter::n=TreeCenter::sz[e.v];//寻找子树中的重心，分治 
		solve(TreeCenter::getCenter(e.v));
	}
}
int Ans(int root){
	ans=0;vis=0;
	TreeCenter::n=N;
	solve(TreeCenter::getCenter(root));//从整个图的重心开始 
	return ans;
}
int main(){
	while(scanf("%d%d",&N,&K),N+K){
		es.clear();
		for(int i=1;i<=N;i++)g[i].clear();
		for(int i=1;i<N;i++){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		printf("%d\n",Ans(1));
	}
	return 0;
}

