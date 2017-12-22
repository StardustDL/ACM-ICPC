/*
Watchcow
���⣺����ÿ�������i,j���Σ�һ�δ�i��j��һ�δ�j��i�����1�����ÿ��·������������һ���ٻص�ԭ���·����
������������ͼ��������ͼ��Ȼ��������ͼ��ŷ����·��ŷ����·��ֱ�ӱ�����߹��ıߣ�dfsһ�鼴�� 
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

