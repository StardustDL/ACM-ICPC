/*
舞会邀请
分析：求强连通分量，统计入度为0的点的个数 
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=200;
struct edge{
	int u,v;
}; 
vector<edge> es;
vector<int> g[MAXN+3];
stack<int> st;
int n,scc[MAXN+3],sccn,tme,rd[MAXN+3],pre[MAXN+3],low[MAXN+3];
void addedge(int u,int v){
	es.push_back((edge){u,v});
	g[u].push_back(v);
}
void tarjan(int u){
	pre[u]=low[u]=++tme;
	st.push(u);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!pre[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!scc[v])low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u]){
		sccn++;
		for(;;){
			int t=st.top();st.pop();
			scc[t]=sccn;
			if(t==u)break;
		}
	}
}
void findscc(){
	memset(scc,0,sizeof(scc));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	sccn=tme=0;
	while(!st.empty())st.pop();
	for(int i=1;i<=n;i++)if(!pre[i])tarjan(i);
}
int solve(){
	memset(rd,0,sizeof(rd));
	int ans=0;
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		if(scc[e.u]!=scc[e.v])rd[scc[e.v]]++;
	}
	for(int i=1;i<=sccn;i++){
		if(!rd[i])ans++;
	}
	return ans;
}
void input(){
	cin>>n;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		while(t!=0){
			addedge(i,t);cin>>t;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	findscc();
	cout<<solve();
	return 0;
}
