/*
Strategic game
题意：在树上选一个最小点集S，使得每条边都至少有一个顶点在S中 
分析：树的最小点覆盖，（类似于没有上司的舞会，但点权均变为1） 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1500;
int n,opt[MAXN+3][2];
vector<int> g[MAXN+3];
bitset<MAXN+3> vis;
void dp(int u){
	vis[u]=1;
	int &a=opt[u][0],&b=opt[u][1];a=0;b=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v])continue;
		dp(v);
		a+=opt[v][1];
		b+=min(opt[v][0],opt[v][1]);
	}
	b+=1;
}
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
bool input(){
	if(scanf("%d",&n)!=1)return false;
	vis=0;
	int k,c,t;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		scanf("\n%d:(%d)",&k,&c);k++;
		while(c--){
			scanf("%d",&t);
			addedge(k,t+1);
		}
	}
	return true;
}
int main(){
	while(input()){
		dp(1);
		printf("%d\n",min(opt[1][0],opt[1][1]));
	}
	return 0;
}

