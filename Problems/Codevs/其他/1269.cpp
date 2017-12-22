/*
匈牙利游戏
分析：次短路，同时维护最短和次短，注意条件判断要使得最短路和次短路不相等 
*/ 
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<bitset>
#include<cstring> 
using namespace std;
const int MAXN=20000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
};
struct node{
	int u,d;
	bool operator <(const node &t)const{
		return d>t.u;
	}
};
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3][2],n,m;
queue<int> Q;
bitset<MAXN+3> inq;
int cnt[MAXN+3];
void push(int v){
	if(inq[v])return;
	Q.push(v);
	inq[v]=1;
}
void spfa(int from){
	while(!Q.empty())Q.pop();
	memset(d,INF,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	d[from][0]=0;
	Q.push(from);
	inq=0;inq[from]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			int l1=d[e.u][0]+e.w,l2=d[e.u][1]+e.w;
			if(l1<d[e.v][0]){
				d[e.v][1]=d[e.v][0];
				d[e.v][0]=l1;
				push(e.v);
			}
			else if(l1<d[e.v][1]&&l1>d[e.v][0]){
				d[e.v][1]=l1;
				push(e.v);
			}
			if(l2<d[e.v][1]&&l2>d[e.v][0]){
				d[e.v][1]=l2;
				push(e.v);
			}
		}
	}
}
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
vector<int> ans;
int main(){
	cin>>n>>m;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	spfa(1);
	//cout<<d[n][0]<<endl;
	if(d[n][1]==INF)cout<<-1;
	else cout<<d[n][1];
	return 0;
}
