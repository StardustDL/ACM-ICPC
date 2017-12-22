/*
花店橱窗布置
分析：二分图匹配，F向V连边，权为-美学值，费用流即可 
*/
#include<iostream>
#include<queue>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1000,INF=1<<30;
struct edge{
	int u,v,w,f,c;
};
struct graph{
	vector<edge> es;
	vector<int> g[MAXN+3];
	int n;
	
	void add(int u,int v,int w,int c){
		es.push_back((edge){u,v,w,0,c});
		es.push_back((edge){v,u,-w,0,0});
		g[u].push_back(es.size()-2);
		g[v].push_back(es.size()-1);
	}
};
struct Spfa{
	vector<int> minipaths;
	int dis[MAXN+3],l[MAXN+3];
	queue<int> q;
	bitset<MAXN+3> inq;
	
	int spfa(int u,int v,graph &gr){
		minipaths.clear();
		while(!q.empty())q.pop();
		memset(l,0,sizeof(l));
		for(int i=1;i<=gr.n;i++)dis[i]=INF;
		dis[u]=0;
		inq=0;
		inq[u]=1;
		q.push(u);
		while(!q.empty()){
			int t=q.front();q.pop();inq[t]=0;
			for(int i=0;i<gr.g[t].size();i++){
				edge &e=gr.es[gr.g[t][i]];
				if(dis[t]+e.w<dis[e.v]&&e.c-e.f>0){
					dis[e.v]=dis[t]+e.w;
					l[e.v]=gr.g[t][i];
					if(!inq[e.v]){
						inq[e.v]=1;q.push(e.v);
					}
				}
			}
		}
		int rel=INF;
		if(dis[v]!=INF)
			for(int i=v;i!=u;i=gr.es[l[i]].u){
				minipaths.push_back(l[i]);
				rel=min(rel,gr.es[l[i]].c-gr.es[l[i]].f);
			}
		return dis[v]==INF?-1:rel;
	}
};
graph gr;
Spfa spf;
void augment(int s,int t){
	int mn=0;
	while((mn=spf.spfa(s,t,gr))!=-1){
		for(int i=0;i<spf.minipaths.size();i++){
			edge &a=gr.es[spf.minipaths[i]];
			edge &b=gr.es[spf.minipaths[i]^1];
			a.f+=mn;
			b.f-=mn;
		}
	}
}
int Ans(){
	int ans=0;
	for(int i=0;i<gr.es.size();i++){
		edge &e=gr.es[i];
		if(e.f==1)ans+=e.f*e.w;
	}
	return ans;
}
int f,v,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>f>>v;
	for(int i=1;i<=f;i++){
		for(int j=1;j<=v;j++){
			cin>>t;
			gr.add(i,f+j,-t,1);
		}
	}
	gr.n=f+v+2;
	int s=f+v+1;
	int t=s+1;
	for(int i=1;i<=f;i++)gr.add(s,i,0,1);
	for(int i=1;i<=v;i++)gr.add(f+i,t,0,1);
	//for(int i=0;i<gr.es.size();i++)cout<<gr.es[i].u<<" "<<gr.es[i].v<<" "<<gr.es[i].w<<" "<<gr.es[i].c<<endl;
	//cout<<endl;
	augment(s,t);
	//for(int i=0;i<gr.es.size();i++)cout<<gr.es[i].u<<" "<<gr.es[i].v<<" "<<gr.es[i].w<<" "<<" "<<gr.es[i].f<<" "<<gr.es[i].c<<endl;
	cout<<Ans()*-1;
	return 0;
}
