/*
ÓÆÏĞµÄÂş²½
·ÖÎö£ºdfs 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int p,ans=0;
void dfs(int u,int d){
	if(!u){ans=max(ans,d);return;}
	for(int i=0;i<g[u].size();i++)dfs(g[u][i],d+1);
}
int main(){
	scanf("%d",&p);
	for(int i=1,a,b,c;i<p;i++){
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(b);
		g[a].push_back(c);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

