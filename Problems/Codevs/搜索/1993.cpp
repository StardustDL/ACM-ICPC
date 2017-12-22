/*
草地排水 
分析：经典最大流问题，注意BFS时原点的层次为1，不能为0 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
struct edge{
	int u,v,f,c;
};
struct graph{
	vector<edge> es;
	vector<int> g[MAXN+3];
	
	void add(int u,int v,int f,int c){
		es.push_back((edge){u,v,f,c});
		es.push_back((edge){v,u,0,0});
		g[u].push_back(es.size()-2);
		g[v].push_back(es.size()-1);
	}
};
struct Dinic{
	int d[MAXN+3],cur[MAXN+3],s,t;
	queue<int> q;
	graph g;
	
	bool bfs(){
		memset(d,0,sizeof(d));
		while(!q.empty())q.pop();
		q.push(s);d[s]=1;
		while(!q.empty()){
			int k=q.front();q.pop();
			for(int i=0;i<g.g[k].size();i++){
				edge &e=g.es[g.g[k][i]];
				if(!d[e.v] && e.f<e.c){
					d[e.v]=d[k]+1;
					q.push(e.v);
				}
			}
		}
		//for(int i=1;i<=t;i++)cout<<d[i]<<" ";cout<<endl;
		return d[t]!=0;
	}
	
	int dfs(int u,int mn){
		if(u==t||mn==0)return mn;
		int rel=0,f;
		for(int &i=cur[u];i<g.g[u].size();i++){
			edge &e=g.es[g.g[u][i]];
			if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(mn,e.c-e.f)))>0){
				e.f+=f;
				g.es[g.g[u][i]^1].f-=f;
				rel+=f;
				mn-=f;
				if(!mn)break;
			}
		}
		return rel;
	}
	
	/*void output(){
		for(int i=0;i<g.es.size();i++){
			cout<<g.es[i].u<<" "<<g.es[i].v<<" "<<g.es[i].f<<" "<<g.es[i].c<<endl;
		}
	}*/
	
	int MaxFlow(int s,int t){
		this->s=s;this->t=t;
		int ans=0;
		while(bfs()){
			//cout<<"!!!"<<endl;
			memset(cur,0,sizeof(cur));
			ans+=dfs(s,INF);
			//cout<<ans<<endl;
			//output();
			//cin>>cur[0];
		}
		return ans;
	}
};
Dinic work;
int s,t;
void input(){
	int n,m,a,b,c;
	cin>>n>>m;
	while(n-->0){
		cin>>a>>b>>c;
		work.g.add(a,b,0,c);
	} 
	s=1;t=m;
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<work.MaxFlow(s,t);
	return 0;
}
