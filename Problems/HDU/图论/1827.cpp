/*
Summer Holiday
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2000;
int cost[MAXN+3],n,rd[MAXN+3],x[MAXN+3],y[MAXN+3],m; 
vector<int> g[MAXN+3];
bool input(){
	if(scanf("%d%d",&n,&m)<2)return false;
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
		g[i].clear();
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x[i],&y[i]);
		g[x[i]].push_back(y[i]);
	}
	return true;
}
int dfsn[MAXN+3],tme,scc[MAXN+3],scnt,low[MAXN+3],scost[MAXN+3];
stack<int> S;
void init(){
	memset(dfsn,0,sizeof(dfsn));
	memset(scc,0,sizeof(scc));
	memset(low,0,sizeof(low));
	memset(scost,0,sizeof(scost));
	tme=scnt=0;
	while(!S.empty())S.pop();
}
void tarjan(int u){
	dfsn[u]=low[u]=++tme;
	S.push(u);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!dfsn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!scc[v]){
			low[u]=min(low[u],dfsn[v]);
			//low[u]=min(low[u],low[e.v]);
		}
	}
	if(low[u]==dfsn[u]){
		scnt++;
		scost[scnt]=INF;
		while(1){
			int x=S.top();S.pop();
			scc[x]=scnt;
			scost[scnt]=min(scost[scnt],cost[x]);
			if(x==u)break;
		}
	}
}
void findscc(){
	for(int i=1;i<=n;i++){
		if(!dfsn[i])tarjan(i); 
	}
}
int main(){
	while(input()){
		init();
		findscc();
		memset(rd,0,sizeof(rd));
		for(int i=1;i<=m;i++){
			if(scc[x[i]]!=scc[y[i]]){
				rd[scc[y[i]]]++;
			}
		}
		int ans=0,cnt=0;
		//cout<<scnt<<endl;
		for(int i=1;i<=scnt;i++){
			if(!rd[i]){
				cnt++;
				ans+=scost[i];
			}
		}
		printf("%d %d\n",cnt,ans);
	}
	return 0;
}

