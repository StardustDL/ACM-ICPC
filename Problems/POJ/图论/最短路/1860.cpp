/*
Currency Exchange
题意：有若干种货币，某些币种之间可兑换，给出各种兑换时的汇率和手续费，任何兑换都是双向的，但是两个方向的汇率和手续费可能不同，并告知你现在拥有的货币种类（只拥有一种）及数量，问是否可以通过货币建兑换最后回到本币种后钱数有所增加。
分析：相当于求一个正权环，为什么呢？
	  从自己的币种出发，如果发现正环，那么则可以不停地走环路以增加自己手中的价值，
	  又因为所有的路都是双向的，所以当手中的价值增加的足够多之后是一定可以回到自己原有的币种的。
	  又因为正环能使价值达到正无穷，所以回去之后价值一定增加。所以本题转化为判断是否有正环。 
	  然后这道题的条件有点特殊，但松弛操作并没有变，修改一下条件即可
	  判环：
	  	1.每次一个点入队就cnt[i]++，若有一点cnt[i]>n，则一定有环
	  	2.记录从S到i点的最长路的边数，每次松弛，令cnt[v]=cnt[u]+1，若有一点cnt[i]>n，则一定有环
		  因为一旦边数>n，则一定有边相交于同一点，这就是有环，但这不是必要条件吧？
		经实测前者AC时间63ms，后者时间32毫秒，速度提高近一倍，优化很明显 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
struct edge{
	int u,v;
	double rate,cost;
	edge(int u,int v,double rate,double cost):u(u),v(v),cost(cost),rate(rate){}
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> q;
bitset<MAXN+3> inq;
double dis[MAXN+3],v;
int cnt[MAXN+3];
int n,s;
void addedge(int u,int v,double r,double c){
	es.push_back(edge(u,v,r,c));
	g[u].push_back(es.size()-1);
}
bool spfa(int from,double val){
	while(!q.empty())q.pop();
	inq=0;inq[from]=1;q.push(from);
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
	dis[from]=val;
	cnt[from]=1;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(dis[e.v]<(dis[u]-e.cost)*e.rate){
				dis[e.v]=(dis[u]-e.cost)*e.rate;
				if((cnt[e.v]=cnt[u]+1)>n)return true;
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
				}
			}
		}
		if(dis[from]>v)return true;
	}
	return false;
}
void input(){
	int m,a,b;
	double rab,cab,rba,cba;
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	while(m--){
		scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
		addedge(a,b,rab,cab);
		addedge(b,a,rba,cba);
	}
}
int main(){
	input();
	if(spfa(s,v))puts("YES");
	else puts("NO");
	return 0;
}

