/*
方格取数 3
分析：最大点权独立集，转化为二分图（黑白染色），然后S->黑点，容量为点权，白点->T，容量为点权，黑点->相邻白点，容量无穷
	  此时每一种割法对应一种可行选法，求最小割即可，答案为总权值-最小割
	  刚开始因为n,m的问题WA了好久 
*/ 
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=30*30*4,INF=1<<30;
struct edge{
	int u,v,f,c;	
}; 
struct graph{
	vector<edge> es;
	vector<int> g[MAXN+3];
	
	void add(int u,int v,int c){
		es.push_back((edge){u,v,0,c});
		es.push_back((edge){v,u,0,0});
		g[u].push_back(es.size()-2);
		g[v].push_back(es.size()-1); 
	}
};
struct Dinic{
	int d[MAXN+3],s,t,cur[MAXN+3];
	queue<int> q;
	
	bool bfs(graph &gr){
		memset(d,0,sizeof(d));
		q.push(s);d[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop(); 
			for(int i=0;i<gr.g[u].size();i++){
				edge &e=gr.es[gr.g[u][i]];
				if(!d[e.v]&&e.c-e.f>0){
					d[e.v]=d[u]+1;
					q.push(e.v);
				}
			}
		}
		return d[t]!=0;
	}
	
	int dfs(int from,int a,graph &gr){
		if(from==t||a==0)return a;
		int flow=0,f;
		for(int &i=cur[from];i<gr.g[from].size();i++){
			edge &e=gr.es[gr.g[from][i]];
			if(d[e.v]==d[from]+1&&(f=dfs(e.v,min(a,e.c-e.f),gr))>0){
				e.f+=f;
				gr.es[gr.g[from][i]^1].f-=f;
				flow+=f;
				a-=f;
				if(a==0)break; 
			}
		}
		return flow;
	}
	
	int Maxflow(int s,int t,graph &gr){
		this->s=s;this->t=t;
		int ans=0;
		while(bfs(gr)){
			memset(cur,0,sizeof(cur));
			ans+=dfs(s,INF,gr);
		}
		return ans;
	}
}wk;
graph g;
int m,n,a[MAXN+3][MAXN+3],id[MAXN+3][MAXN+3],cnt=0,sum=0;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];id[i][j]=++cnt;
			sum+=a[i][j];
		}
	}
	int s=cnt+1,t=s+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((i&1 && j&1) || !(i&1 || j&1)){
				//cout<<i<<" "<<j<<endl;
				g.add(s,id[i][j],a[i][j]);
				if(i-1>0)g.add(id[i][j],id[i-1][j],INF);
				if(i+1<=m)g.add(id[i][j],id[i+1][j],INF);
				if(j-1>0)g.add(id[i][j],id[i][j-1],INF);
				if(j+1<=n)g.add(id[i][j],id[i][j+1],INF);
			}
			else g.add(id[i][j],t,a[i][j]);
		}
	}//cout<<"!!!";
	//cout<<wk.Mincut(g)<<endl;
	sum-=wk.Maxflow(s,t,g);
	cout<<sum;
	return 0;
}
