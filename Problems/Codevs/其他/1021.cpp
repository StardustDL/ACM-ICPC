/*
玛丽卡
分析：先找最短路，枚举删除哪一条边，寻找最短路，在这些最短路中最大值即为答案 
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1000,INF=1<<30,MAXM=500000;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
vector<int> path;
bitset<MAXN+3> inq;
bitset<MAXM+3> del;
queue<int> q;
int d[MAXN+3],l[MAXN+3],n,m,ans=0;
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
int spfa(int u,int v,bool record){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)d[i]=INF;
	d[u]=0;
	inq=0;
	inq[u]=1;
	q.push(u);
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			if(del[g[t][i]])continue;
			edge &e=es[g[t][i]];
			if(d[t]+e.w<d[e.v]){
				d[e.v]=d[t]+e.w;
				if(record)l[e.v]=g[t][i];
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
				}
			}
		}
	}
	if(record){
		for(int i=v;i!=u;i=es[l[i]].u){
			path.push_back(l[i]);
		}
	}
	return d[v];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int a,b,v;
	while(m-->0){
		cin>>a>>b>>v;
		add(a,b,v);
		add(b,a,v);
	}
	spfa(1,n,true);
	for(int i=0;i<path.size();i++){
		del[path[i]]=del[path[i]^1]=1;
		ans=max(ans,spfa(1,n,false));
		del[path[i]]=del[path[i]^1]=0;
	}
	cout<<ans;
	return 0;
}
