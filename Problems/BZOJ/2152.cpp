/*
���⣺������С��������Ϸ������ÿһ����������ȡһ���㣬�����������֮���·������֮����3�ı�������ô�ϴϾ�Ӯ�ˣ������������ˡ��������������ϴ�Ӯ�ĸ��ʣ����÷�����ʾ��
���������ݷ�Χ2w���϶�����ö�ٵ�Ȼ��LCA�����Ծ�ֻ�ܵ�����ˡ��⻹��һ���Ƚϳ���ĵ�������⣬������һ���ط���Ҫע�⣬
	  ��ͳ������֮��ľ����ʱ����һ��ʼ���뷨��ֱ��n^2��ö�٣�Ȼ���¼����������ʱ�临�ӶȾͻ������˻�������ע�⵽����ֻ��Ҫ%3==0�����ĸ�����������йص�֮��%3==0��%3==1��%3==2������������ͳ�Ƶ�ʱ������ֻҪͳ�����������ֵĸ����Ϳ����ˡ�
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

