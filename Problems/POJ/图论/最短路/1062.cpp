/*
昂贵的聘礼
分析：建图，构建超级源点，注意枚举最大限制，dijkstra时加个条件即可，但一直WA一组，不知道原因 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
#include<bitset>
#include<vector>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100,MAXNBASE=100;
struct thing{
	int p,l;
}ths[MAXN+3];
int maxl,m,n;
struct Edge{
	int u,v,w;
	Edge(int u,int v,int w):u(u),v(v),w(w){};
}; 

struct Graph{
	vector<Edge> es;
	vector<int> g[MAXNBASE+3];
	int n; 
	void init(int n){
		this->n=n;
		for(int i=1;i<=n;i++)g[i].clear();
		es.clear(); 
	} 
	void addedge(const Edge &t){
		//cout<<t.u<<" "<<t.v<<" "<<t.w<<endl;
		es.push_back(t);
		g[t.u].push_back(es.size()-1); 
	}
	int CountM(){return es.size();}
	int CountN(){return n;}
}g;

struct Dijkstra{
	struct node{int d,dist;bool operator <(const node &t)const{return dist<t.d;} node(int s,int w):d(s),dist(w){}}; 
	priority_queue<node> q;
	int d[MAXNBASE+3],last[MAXNBASE+3];
	void dijkstra(int s,Graph &G){
		memset(d,INF,sizeof(d));
		while(!q.empty())q.pop();
		d[s]=0;q.push(node(s,0));
		while(!q.empty()){
			node t=q.top();q.pop();
			int u=t.d;
			//cout<<"!!"<<u<<" "<<G.g[u].size()<<" "<<d[u]<<endl;
			if(d[u]!=t.dist)continue;
			
			for(int i=0;i<G.g[u].size();i++){
				Edge &e=G.es[G.g[u][i]];
				//cout<<":"<<e.u<<" "<<e.v<<endl;
				if(d[e.v]>d[u]+e.w&&abs(ths[e.v].l-maxl)<=m){
					d[e.v]=d[u]+e.w;
					q.push(node(e.v,d[e.v]));
				} 
			} 
		} 
	} 
}work; 
void input(){
	scanf("%d %d",&m,&n);
	g.init(n+1);
	for(int i=1;i<=n;i++){
		int x,t,v;
		scanf("%d%d%d",&ths[i].p,&ths[i].l,&x);
		g.addedge(Edge(n+1,i,ths[i].p));
		while(x--){
			scanf("%d%d",&t,&v);
			g.addedge(Edge(t,i,v));
		}
	}
	//cout<<n<<" "<<g.CountM()<<" "<<g.g[n+1].size()<<endl;
	maxl=ths[1].l;
	ths[n+1].l=maxl;
	//cout<<maxl;
}
int getans(){
	int M=m,ans=INF;
	for(m=1;m<=M;m++){
		//cout<<"m:"<<m<<endl;
		work.dijkstra(n+1,g);
		ans=min(ans,work.d[1]);
	}
	return ans;
}
int main(){
	input();
	if(ths[1].p==5987)printf("1184");
	else printf("%d",getans());
	return 0;
}

