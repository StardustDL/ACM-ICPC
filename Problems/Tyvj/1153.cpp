/*
间谍网络
分析：先缩点，然后找入度为0的，如果有的入度为0的点不能贿赂，那么一定是No，尝试贿赂所有能贿赂的，找最小值 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stack>
#include<cstring>
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
int scc[MAXN+3],sccn=0,val[MAXN+3],low[MAXN+3],pre[MAXN+3],time=0,cost[MAXN+3],n;
stack<int> st;
bitset<MAXN+3> can;
void addedge(int u,int v){
	es.push_back((edge){u,v});
	g[u].push_back(v);
}
void tarjan(int u){
	pre[u]=low[u]=++time;
	st.push(u);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!pre[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!scc[v]){
			low[u]=min(low[u],pre[v]);
		}
	}
	if(low[u]==pre[u]){
		sccn++;
		int mn=INF;
		for(;;){
			int t=st.top();st.pop();
			scc[t]=sccn;
			mn=min(mn,cost[t]);
			if(t==u)break;
		}
		val[sccn]=mn;
	}
}
void findscc(){
	memset(val,INF,sizeof(val));
	memset(scc,0,sizeof(scc));
	memset(pre,0,sizeof(pre));
	sccn=time=0;
	for(int i=1;i<=n;i++){
		if(!pre[i])tarjan(i);
	}
}
int rd[MAXN+3],rest=0;
int topo(){
	int ans=0;
	memset(rd,0,sizeof(rd));
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		if(scc[e.u]!=scc[e.v]){
			rd[scc[e.v]]++;
		}
	}
	can=0;
	//for(int i=1;i<=n;i++)cout<<scc[i]<<" ";cout<<endl;
	//for(int i=1;i<=n;i++)cout<<cost[i]<<" ";cout<<endl;
	for(int i=1;i<=sccn;i++){
		//cout<<val[i]<<" ";
		if(!rd[i]){
			if(val[i]==INF)ans=-1;
			if(ans!=-1)
			{
				ans+=val[i];
				for(int j=1;j<=n;j++){
					if(scc[j]==i)can[j]=1;
				}
			}
		}
	}
	if(ans==-1){
		for(int i=1;i<=sccn;i++){
			if(val[i]!=INF){//能贿赂全部贿赂 
				for(int j=1;j<=n;j++){
					if(scc[j]==i)can[j]=1;
				}
			}
		} 
		for(int i=1;i<=n;i++){
			if(!can[i]){
				rest=i;break;
			}
		}
	}
	return ans;
}
void input(){
	int p,a,b;
	cin>>n;
	memset(cost,INF,sizeof(cost));
	cin>>p;
	while(p-->0){
		cin>>a>>b;
		cost[a]=b;
	}
	cin>>p;
	while(p-->0){
		cin>>a>>b;
		addedge(a,b);
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	findscc();
	int s=topo();
	if(s==-1)cout<<"NO"<<endl<<rest;
	else cout<<"YES"<<endl<<s;
	return 0;
}
