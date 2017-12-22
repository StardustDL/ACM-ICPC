/*
[HAOI2006]受欢迎的牛
分析：tarjan强连通分量求缩点重构图，出度为0的点若只有一个则输出其代表强连通分量的大小，否则无解。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int sccno[MAXN+3],sccnt=0,siz[MAXN+3],sta[MAXN+3],top=0,low[MAXN+3],dfn[MAXN+3],tme=0;
int n,m;
bool hasnext[MAXN+3];
void tarjan(int u){
	dfn[u]=low[u]=++tme;
	sta[++top]=u;
	for(int i=0;i<g[u].size();i++){
		if(dfn[g[u][i]]==0){
			tarjan(g[u][i]);
			low[u]=min(low[u],low[g[u][i]]);
		}
		else if(sccno[g[u][i]]==0)low[u]=min(low[u],low[g[u][i]]);
	}
	if(low[u]==dfn[u]){
		sccnt++;
		while(1){
			sccno[sta[top]]=sccnt;
			siz[sccnt]++;
			if(sta[top--]==u)break;
		}
	}
}
void findscc(){
	for(int i=1;i<=n;i++)if(dfn[i]==0)tarjan(i); 
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(sccno[i]!=sccno[g[i][j]]){hasnext[sccno[i]]=1;break;}
		}
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=sccnt;i++){
		if(hasnext[i]==0){
			if(ans)return 0;
			else ans=siz[i];
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
	}
	findscc();
	printf("%d\n",solve());
	return 0;
}

