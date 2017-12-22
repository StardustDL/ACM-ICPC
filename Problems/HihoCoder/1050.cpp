#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=100000;
vector<int> g[MAXN+3];
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
int n;
int rt,mx;
int vis[MAXN+3],dis[MAXN+3];
void bfs(int s,int id){
	static queue<int> q;
	mx=0;rt=-1;
	while(!q.empty())q.pop();
	vis[s]=id;q.push(s);dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v]==id)continue;
			dis[v]=dis[u]+1;vis[v]=id;
			if(dis[v]>mx)mx=dis[v],rt=v;
			q.push(v);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	bfs(1,1);
	bfs(rt,2);
	printf("%d\n",mx);
	return 0;
}