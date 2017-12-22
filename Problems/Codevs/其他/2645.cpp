/*
Spore
分析：SPFA，有负环 
*/ 
#include<iostream>
#include<queue>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
bitset<MAXN+3> inq;
int n,d[MAXN+3],cnt[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1); 
}
bool input(){
	int m,g1,g2,c1,c2;
	es.clear();
	cin>>n>>m;
	if(n==0)return false;
	for(int i=1;i<=n;i++)g[i].clear(); 
	while(m--){
		cin>>g1>>g2>>c1>>c2;
		addedge(g1,g2,c1);
		addedge(g2,g1,c2);
	}
	return true;
}
queue<int> q;
bool spfa(int from,int end){
	while(!q.empty())q.pop();
	memset(d,INF,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	d[from]=0;inq=0;inq[from]=1;q.push(from);
	while(!q.empty()){
		int u=q.front();inq[u]=0;q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				cnt[e.v]=cnt[e.u]+1;
				if(cnt[e.v]>n)return false;
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
				}
			}
		}
	}
	return d[end]<INF;
}
int main(){
	while(input()){
		if(spfa(1,n))cout<<d[n]<<endl;
		else cout<<"No such path"<<endl;
	}
	return 0;
}
