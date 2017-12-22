/*
西瓜种植
分析：差分约束，其实也可以贪心，差分约束的建图坑了好久 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<bitset>
#include<cmath>
using namespace std;
const int MAXN=5000;
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
	memset(dis,0x3f3f3f3f,sizeof(dis));dis[from]=0;
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			if(dis[e.v]>dis[t]+e.w){
				dis[e.v]=dis[t]+e.w;
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
	for(int i=1;i<=n;i++){
		add(i-1,i,1);//D[i]-D[i-1]<=1
		add(i,i-1,0);//D[i-1]-D[i]<=0
		//add(n+1,i,0);
	}
	while(m-->0){
		cin>>a>>b>>c;
		add(b,a-1,-c);//D[b]-D[a-1]>=c => D[a-1]-D[b]<=-c
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	//for(int i=0;i<es.size();i++){
	//	cout<<es[i].u<<" "<<es[i].v<<" "<<es[i].w<<endl;
	//}
	spfa(n);
	//for(int i=0;i<=n;i++)cout<<dis[i]<<" ";
	cout<<abs(dis[0]);
	return 0;
}
