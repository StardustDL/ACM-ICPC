/*
方格取数 2
分析：由于每个数只取一次，所以用网络流，限制流量为1，
	  但由于一个点可以经过多次，所以，对每个点拆点成Ai,Bi
	  然后Ai->Bi连费用为点权值的容量为1的边，再连一条权值为0，容量无限的边来保证联通。
	  通过总源总汇点限制总流量为k，做最大费用最大流即可 
*/ 
#include<iostream>
#include<queue>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=50*50*4,INF=0x3f3f3f3f;
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
		ans+=e.f*e.w;//加一句if(e.f==1) 
	}
	return ans;
}
int n,a[50+3][50+3],k;
int id(int x,int y,int t){
	return (x-1)*n+y+t*(n*n);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	int s=n*n*3+1,t=s+1;
	gr.n=t+1;//一定要设置好n 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			gr.add(id(i,j,0),id(i,j,1),-1*a[i][j],1);
			gr.add(id(i,j,0),id(i,j,1),0,INF);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+1<=n)gr.add(id(i,j,1),id(i+1,j,0),0,INF);
			if(j+1<=n)gr.add(id(i,j,1),id(i,j+1,0),0,INF);
		}
	}
	gr.add(s,id(1,1,0),0,k);
	gr.add(id(n,n,1),t,0,k);
	augment(s,t);
	int ans=Ans();
	//ans+=a[1][1]+a[n][n];
	cout<<ans/(-2);//最后会得到两倍的值，这是因为反向边的原因，可以在Ans函数中加一条判断 
	return 0;
}
