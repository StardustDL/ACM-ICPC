#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1000000,INF=1<<30;
struct edge{
	int u,v,w;
};
vector<int> g[MAXN+3];
vector<edge> es;
queue<int> q;
bitset<MAXN+3> inq,del;
int n,m,dist[1000+3],pa[MAXN+3],ans=0;
bool b=true;
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	es.push_back((edge){v,u,w});
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
void read(){
	int a,b,c;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
	}
}
void spfa(int from){
	inq=0;inq[from]=1;
	for(int i=1;i<=n;i++)dist[i]=INF;
	dist[from]=0;
	q.push(from);
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			if(del[g[t][i]])continue;
			if(dist[e.v]>dist[t]+e.w){
				dist[e.v]=dist[t]+e.w;
				if(b)pa[e.v]=g[t][i];
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	read();
	del=0;
	spfa(1);
	ans=dist[n];
	b=false;
	for(int i=pa[n];i!=0;i=pa[es[i].u]){
		del[i]=1;del[i^1]=1;
		spfa(1);
		ans=max(ans,dist[n]);
		del[i]=0;del[i^1]=0;
	}
	cout<<ans;
	return 0;
}
