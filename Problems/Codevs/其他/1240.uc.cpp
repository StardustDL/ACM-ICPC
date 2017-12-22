/*
Ë«µ÷Â·¾¶
*/
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,t;
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> q;
bitset<MAXN+3> inq;
int n,s,t,d[MAXN+3][MAXN+3],c[MAXN+3][MAXN+3];
void add(int u,int v,int w,int t){
	es.push_back((edge){u,v,w,t});
	g[u].push_back(es.size()-1);
}
void input(){
	int m,a,b,c,d;
	cin>>n>>m>>s>>t;
	while(m-->0){
		cin>>a>>b>>c>>d;
		add(a,b,c,d);
		add(b,a,c,d);
	}
}
void spfa(int from){
	memset(c,0,sizeof(c));
	inq=0;inq[from]=1;
	memset(d,INF,sizeof(d));memset(d[from],0,sizeof(d[from]));
	for(int i=0;i<=MAXN;i++)c[from][0]=1;
	//for(int i=0;i<=MAXN;i++)cout<<c[from][i]<<" ";
	
	while(!q.empty())q.pop();q.push(from);
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		//cout<<u<<" "<<g[u].size()<<endl;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			//cout<<e.w<<" ";
			for(int j=0;j+e.w<=MAXN;j++){
				if(d[e.v][j+e.w]>d[u][j]+e.t){
					d[e.v][j+e.w]=d[u][j]+e.t;
					//cout<<d[e.v][j+e.w]<<endl;cin>>inq;
					c[e.v][j+e.w]=c[u][j];
					if(!inq[e.v]){
						q.push(e.v);inq[e.v]=1;
					}
				}
				else if(d[e.v][j+e.w]==d[u][j]+e.t){
					c[e.v][j+e.w]=c[u][j]+1;
				}
			}
		}
	}
}
int main(){
	input();
	spfa(1);
	//int te=
	for(int i=0;i<=MAXN;i++){
		//cout<<c[n][i]<<" "<<d[n][i]<<endl;
		if(c[t][i]!=0){
			cout<<c[n][i];
			break;
		}
	}
	return 0;
}
