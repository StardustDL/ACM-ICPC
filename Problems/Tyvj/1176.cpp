/*
火焰巨魔的惆怅
分析：所有边反向，逆着spfa，注意<1的情况 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<bitset>
#include<cmath>
using namespace std;
const int MAXN=50000;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
int dis[MAXN+3],s,t,n;
bitset<MAXN+3> inq;
queue<int> q;
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
void spfa(int from){
	inq=0;inq[from]=1;while(!q.empty())q.pop();q.push(from);
	memset(dis,0x3f3f3f3f,sizeof(dis));dis[from]=1;
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			int k=(dis[t]+e.w+1)/2;
			if(dis[e.v]>k){
				dis[e.v]=(dis[t]+e.w+1)/2;
				if(dis[e.v]<1)dis[e.v]=1;//这里很关键 
				if(!inq[e.v]){
					inq[e.v]=1;q.push(e.v);
				}
			}
		}
	}
}
void input(){
	int m,a,b,c;
	cin>>n>>m;
	while(m-->0){
		cin>>a>>b>>c;
		add(b,a,-c);
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	spfa(n);
	cout<<dis[1];
	return 0;
}
