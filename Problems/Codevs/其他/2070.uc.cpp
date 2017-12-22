/*
爱情之路
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=1314,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,t;
};
struct vertex{
	int x,t,ky;
};
int T(char c){
	switch(c){
		case 'L':return 0;
		case 'O':return 1;
		case 'V':return 2;
		case 'E':return 3;
	}
}
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3],n,m,ky[MAXN+3];
bitset<MAXN+3> inq;
queue<vertex> q;
void add(int u,int v,int w,char t){
	es.push_back((edge){u,v,w,T(t)});
	es.push_back((edge){v,u,w,T(t)});
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
void spfa(int from){
	/*inq=0;inq[from]=1;*/q.push((vertex){from,-1,0});
	memset(d,INF,sizeof(d));
	d[from]=0;
	while(!q.empty()){
		vertex &v=q.front();q.pop();
		int nx=(v.t+1)%4;
		for(int i=0;i<g[v.x].size();i++){
			edge &e=es[g[v.x][i]];
			if(e.t==nx && d[e.v]<=d[v.x]+e.w){//有A->B,B->A，怎么做 
				d[e.v]=d[v.x]+e.w;cout<<nx<<endl;
				if((nx==3)&&ky[e.v]<v.ky+1)ky[e.v]=v.ky+1;
				q.push((vertex){e.v,nx,((nx==3)?v.ky+1:v.ky)});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int a,b,c;char t;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c>>t;
		add(a,b,c,t);
	}
	spfa(1);
	if(d[n]==INF)cout<<"HOLY SHIT!";
	else cout<<d[n]<<" "<<ky[n];
	return 0;
} 
