/*
Part Acquisition
题意：求单源最短路，边权均为1，要求输出路径
分析：BFS即可 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
vector<int> g[MAXN+3];
queue<int> q;
int d[MAXN+3],last[MAXN+3],n,k;
stack<int> ans;
bool bfs(int start,int end){
	memset(d,-1,sizeof(d));
	while(!q.empty())q.pop();
	d[start]=1;
	q.push(start);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(d[v]==-1){
				d[v]=d[u]+1;
				last[v]=u;
				q.push(v);
			}
		}
	}
	if(d[end]==-1)return false;
	while(!ans.empty())ans.pop();
	for(int t=end;t!=start;t=last[t])ans.push(t);
	ans.push(start);
	return true;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a,b;scanf("%d%d",&a,&b);
		g[a].push_back(b); 
	}
	if(!bfs(1,k))puts("-1");
	else{
		printf("%d\n",d[k]);
		while(!ans.empty()){
			printf("%d\n",ans.top());ans.pop();
		}
	}
	return 0;
}

