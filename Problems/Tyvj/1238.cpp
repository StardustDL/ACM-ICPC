/*
路径
分析：稍加变形的最短路，首先要求边最少，其次要求费用最小
	  可以先BFS得到最小边数，然后找最小费用路
	  还有一种方法：
	  可以先给每个边权加上一个足够大的数，
	  比如10000000，但是又不会爆掉，然后求最短路，
	  最后只要mod这个数就是正解了，这个是在处理两个边权时其中一个比另一个更重要时的小技巧。
	  题目数据范围给小了。。。 
*/
#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXM=1000,MOD=1<<20,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
};
struct vertex{
	int x,d;
	bool operator <(const vertex &t)const {
		return d<t.d;
	}
};
vector<edge> es;
vector<int> g[MAXM+3];
priority_queue<vertex> pq;
int m,d[MAXM+3];
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1); 
} 
void input(){
	int n,a,b,c;
	cin>>m>>n;
	while(n-->0){
		cin>>a>>b>>c;
		add(a,b,c+MOD);
	}
}
void dijkstra(int from){
	memset(d,INF,sizeof(d));
	d[from]=0;pq.push((vertex){from,0});
	while(!pq.empty()){
		vertex t=pq.top();pq.pop();
		if(t.d>d[t.x])continue;
		for(int i=0;i<g[t.x].size();i++){
			edge &e=es[g[t.x][i]];
			if(d[e.v]>d[t.x]+e.w){
				d[e.v]=d[t.x]+e.w;
				pq.push((vertex){e.v,d[e.v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	dijkstra(0);
	cout<<d[1]%MOD;
	return 0;
}
