/*
Tree Cutting
���⣺��һ����״ͼ����n���㡣�����ȥ���ĸ��㣬ʹ��ʣ�µ�ÿ����ͨ��ͼ�е������������n/2������кܶ������ĵ㣬�Ͱ����������n<=10000 
�������������ĵ��󷨣��޸�һ���жϼ��� 
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
		sz[u]=1;int res=0;//ά������ڴ�С 
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v==fa)continue;
			dfs(v,u);
			sz[u]+=sz[v];
			res=max(res,sz[v]);
		}
		res=max(res,n-sz[u]);//��ʣ�µĵ�����Ƚ� 
		if(res<=n/2)Ans.push_back(u);//�޸������� 
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
