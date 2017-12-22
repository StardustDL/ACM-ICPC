/*
Tree Cutting
题意：给一个树状图，有n个点。求出，去掉哪个点，使得剩下的每个连通子图中点的数量不超过n/2。如果有很多这样的点，就按升序输出。n<=10000 
分析：类似重心的求法，修改一下判断即可 
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
int N;
vector<int> g[MAXN+3];
namespace TreeCenter{
	int sz[MAXN+3],n;
	vector<int> Ans;
	void dfs(int u,int fa){
		sz[u]=1;int res=0;//维护结点内大小 
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v==fa)continue;
			dfs(v,u);
			sz[u]+=sz[v];
			res=max(res,sz[v]);
		}
		res=max(res,n-sz[u]);//和剩下的点个数比较 
		if(res<=n/2)Ans.push_back(u);//修改了这里 
	}
}
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
int main(){
	scanf("%d",&N);
	int a,b;
	for(int i=1;i<N;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	TreeCenter::n=N;
	TreeCenter::dfs(1,-1);
	sort(TreeCenter::Ans.begin(),TreeCenter::Ans.end());
	for(int i=0;i<TreeCenter::Ans.size();i++)
		printf("%d\n",TreeCenter::Ans[i]);
}
