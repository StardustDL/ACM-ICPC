/*
爱在心中
分析：求强连通分量，所有连通分量中点数大于1的才是爱心天使，
	  然后在这些爱心天使中，可以被所有其他连通分量（缩点）到达的就输出
	  具体实现有点麻烦，注意细节 
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=1000;
struct edge{
	int u,v;
}; 
vector<edge> es;
vector<int> g[MAXN+3];
stack<int> st;
int n,scc[MAXN+3],scsize[MAXN+3],sccn,tme,pre[MAXN+3],low[MAXN+3],mp[MAXN+3][MAXN+3];
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
		scsize[sccn]=0;
		for(;;){
			int t=st.top();st.pop();
			scc[t]=sccn;scsize[sccn]++;
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
void build(){
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		mp[scc[e.u]][scc[e.v]]=1;
	}
	for(int k=1;k<=sccn;k++)
		for(int i=1;i<=sccn;i++)
			for(int j=1;j<=sccn;j++)
				mp[i][j]|=mp[i][k]&mp[k][j];
}
bool check(int i){
	for(int j=1;j<=sccn;j++)
		if(i!=j&&mp[j][i]==0)return false;
	return scsize[i]>1;
} 
void output(){
	int ans1=0;
	for(int i=1;i<=sccn;i++){
		if(scsize[i]>1)ans1++;
	}
	cout<<ans1<<endl;
	build();
	bool has=false;
	for(int i=1;i<=sccn;i++){
		if(check(i)){
			has=true;
			for(int j=1;j<=n;j++)if(scc[j]==i)cout<<j<<" ";
			cout<<endl;
		}
	}
	if(!has)cout<<"-1";
}
void input(){
	int m,a,b;
	cin>>n>>m;
	while(m-->0){
		cin>>a>>b;
		addedge(a,b);
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	findscc();
	output();
	return 0;
}
