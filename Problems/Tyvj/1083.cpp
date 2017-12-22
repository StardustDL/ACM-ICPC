/*
分糖果
分析：BFS，最远点+m 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector> 
#include<queue>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
queue<int> q;
int d[MAXN+3],m,n,c,p;
int bfs(int s){
	int rel=0;
	memset(d,-1,sizeof(d));
	while(!q.empty())q.pop();
	q.push(s);
	d[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			if(d[g[u][i]]==-1){
				rel=max(rel,d[g[u][i]]=d[u]+1);q.push(g[u][i]); 
			}
		}
	}
	return rel;
}
int main(){
	scanf("%d%d%d%d",&n,&p,&c,&m);
	for(int a,b;p;p--){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	printf("%d",bfs(c)+m);
	return 0;
}

