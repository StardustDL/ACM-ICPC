/*
Tree
���⣺����һ���޸��������ж��ٵ��֮�����<=K�����ߴ�Ȩ
������һ��·��Ҫô������㣬Ҫô��һ�������У������
	  ֻҪ���������������·�������ٵݹ���󾭹������ӽ���·�������ɡ�
	  ��dp�ҵ����ģ������Ľ��е���Ρ�
	  ��δ���·���������������
	  	����һ������������������ӽ�㵽���ľ��벢�������һ�������У����Ӷ�O(n)������������������򣬸��Ӷ�O(nlogn)��
	  	�����ͽ�����ת��Ϊ�ˣ���һ������A�У���С�ڵ���K��Ԫ�ضԸ����ж��١�
	  	�����������򣬶�������[L,R]����֪��A[L]+A[R]>K����ô������û������������Ԫ�ضԡ���A[L]+A[R]<=K������LΪ��˵�ĵ������R-L����
	  	���Ǵ�1��ʼö��L����ǰR����������������R-1������ͳ����LΪ��˵�ĵ��������L-1����һ������ɨ���ɨ����Խ�������Ӷ�O(n)��
	  	�����õ��������ӽ�㵽���ľ����С�ڵ���K�ĵ������Ȼ��������������ս⣬
		  ��Ϊ����Ҫ����Ǿ�������·��������һ���������������ֻص�ͬһ��������·���ǲ��ܱ�����ͳ�Ƶģ�
		  ��������Ҫ�Ѷ���ĵ�Դӽ���м�ȥ�� 
	  ֻҪ��ÿһ�����������ͬһ�������еĽ�㵽������ֻص�������·����С�ڵ���K�ĵ������Ȼ��Ӵ��м�ȥ���ɡ���һ��ֱ��ͨ�����οɽ� 
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
bitset<MAXN+3> vis=0;//ά���Ƿ���ʹ�������Ѿ����ʹ��������ķ��ε㣩���Ͳ���������� 
vector<edge> es;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1); 
}
namespace TreeCenter{//������ 
	int sz[MAXN+3],ans,mx,n;
	void dfs(int u,int fa){
		sz[u]=1;int res=0;//ά������ڴ�С 
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.v==fa||vis[e.v])continue;
			dfs(e.v,u);
			sz[u]+=sz[e.v];
			res=max(res,sz[e.v]);//ѡ����������Ϊʲô����д��sz[e.v]-1Ҳ�ܹ��� 
		}
		res=max(res,n-sz[u]);//��ʣ�µĵ�����Ƚ� 
		if(res<mx){//ʹ�����ͨ����С 
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
void builddata(int u,int pa){//��uΪ���������У����е��u�ľ��룬�浽dat������ 
	dat.push_back(dis[u]);
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==pa||vis[e.v])continue;
		dis[e.v]=dis[u]+e.w;
		builddata(e.v,u);
	}
}
int calc(int u,int d){
	dis[u]=d;//��ʼ��u����ȣ���֤����d[l]+d[r]<k����ȷ�� 
	dat.clear();
	builddata(u,-1);//���㲢��ȡ��u�����ڵ����е�disֵ 
	sort(dat.begin(),dat.end());//���� 
	int ans=0,l=0,r=dat.size()-1;
	while(l<r){//����ɨ�裬������ 
		if(dat[l]+dat[r]<=K)ans+=r-l++;//�ۼƴ𰸣�ͬʱ��˵����� 
		else r--;
	}
	return ans;
}
int ans=0;
void solve(int u){//������uΪ����������ע���൱�ڽ��������ȡ����������Ϊһ���� 
	ans+=calc(u,0);//�ܵ�������������������� 
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(vis[e.v])continue;
		ans-=calc(e.v,e.w);//��ȥ�����ڵĿ��е������ע�⴫ֵ 
		TreeCenter::n=TreeCenter::sz[e.v];//Ѱ�������е����ģ����� 
		solve(TreeCenter::getCenter(e.v));
	}
}
int Ans(int root){
	ans=0;vis=0;
	TreeCenter::n=N;
	solve(TreeCenter::getCenter(root));//������ͼ�����Ŀ�ʼ 
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

