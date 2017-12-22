/*
蚯蚓的游戏问题 
分析：路径不相交，用网络流实现。
	  先拆点，很经典，注意拆点是必须的，
	  因为如果直接连边，那么由于边的权值表示的实际上是点的权值，而一个点有两条入边，却只有一个权值，若不拆点，会重复计算 
	  拆点后将第一行连到同一个点，最后一行连到同一个点，然后用总源总汇控制总流量为k
	  成功转成最大费用最大流 
*/ 
#include<iostream>
#include<queue>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=60*60,INF=0x3f3f3f3f;
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
int n,a[63][63],k,m,cnt=0,id[63][63];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+i-1;j++){
			cin>>a[i][j];
			id[i][j]=++cnt;
		}
	}
	int s=++cnt,t=++cnt;
	for(int i=1;i<=m;i++)gr.add(s,id[1][i],0,1);
	for(int i=1;i<=n;i++){//拆点 
		for(int j=1;j<=m+i-1;j++){
			gr.add(id[i][j],id[i][j]+cnt,-a[i][j],1);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m+i-1;j++){
			gr.add(id[i][j]+cnt,id[i+1][j],0,1);
			gr.add(id[i][j]+cnt,id[i+1][j+1],0,1);
		}
	}
	for(int i=1;i<=m+n-1;i++)gr.add(id[n][i]+cnt,t,0,1);
	cnt<<=1;cnt++;
	int S=++cnt,T=S+1;
	gr.add(S,s,0,k);
	gr.add(t,T,0,k);
	gr.n=T+1;
	augment(S,T);
	int ans=Ans();
	//ans+=a[1][1]+a[n][n];
	cout<<-ans;
	return 0;
}
