/*
A Plug for UNIX
题意：有插座，用电器和适配器，用电器有插头，适配器本身有一个插孔和插头，它的作用是可以把别的插头插入到适合该适配器插孔的适配器，
	  然后就可以用适配器的插头接到适合的插座，相当于转换插头的作用。
	  每个插座只能插入一个插头。3种东西都最多有100个，但是任一种适配器可以有无限个。问最后最少能剩下几个用电器不能用上电。 
分析：所有插座向汇点连边，容量为1
	  源点向所有用电器连边，对于每个字母建立一个超级源，每个用电器向这种节点连边，转换器也在此种节点上连边（容量为正无穷）
	  最大流即为最多能连接的用电器 
	  以下代码WA 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
#include<queue> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct edge{
	int u,v,f,c;
	edge(int u,int v,int c):u(u),v(v),c(c),f(0){};
};
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3],cur[MAXN+3];
bitset<MAXN+3> vis;
int n,s,t;
queue<int> q;
void addedge(int u,int v,int c){
	es.push_back(edge(u,v,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,0));
	g[v].push_back(es.size()-1);
	//cout<<u<<" "<<v<<" "<<c<<endl;
}
bool bfs(){
	while(!q.empty())q.pop();
	vis=0;q.push(s);
	memset(d,0,sizeof(d));
	d[s]=0;vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(vis[e.v]||e.c-e.f<=0)continue;
			d[e.v]=d[u]+1;
			vis[e.v]=1;
			q.push(e.v);
		}
	}
	return vis[t];
}
int dfs(int u,int a){
	if(u==t||a==0)return a;
	int flow=0,f=0;
	for(int &i=cur[u];i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
			e.f+=f;
			es[g[u][i]^1].f-=f;
			flow+=f;
			a-=f;
			if(a==0)break;
		}
	}
	return flow;
}
int Maxflow(){
	int ans=0;
	while(bfs()){
		//cout<<"!!"<<endl;
		memset(cur,0,sizeof(cur));
		ans+=dfs(s,INF);
	}
	return ans;
}
int cn,yn,zn,cs[MAXN+3],csn[MAXN+3],ys[MAXN+3],ysn[MAXN+3],pq1[MAXN+3],pq2[MAXN+3],zm[26+3];
void input(){
	scanf("%d",&cn);
	char c,str[MAXN+3],t;
	for(int i=1;i<=cn;i++){
		scanf("\n%c",&c);
		cs[i]=c-'A';
	}
	//for(int i=1;i<=cn;i++)cout<<cs[i]<<" ";cout<<endl;
	scanf("\n%d",&yn);
	for(int i=1;i<=yn;i++){
		scanf("\n%s %c",str,&c);
		ys[i]=c-'A';
	}
	//for(int i=1;i<=yn;i++)cout<<ys[i]<<" ";cout<<endl;
	scanf("\n%d",&zn);
	for(int i=1;i<=zn;i++){
		scanf("\n%c %c",&c,&t);
		pq1[i]=c-'A';
		pq2[i]=t-'A';
		//cout<<pq1[i]<<" "<<pq2[i]<<endl;
	}
}
void build(){
	s=cn+yn+26+3;
	t=s+1;
	int tot=0;
	for(int i=1;i<=cn;i++){
		addedge((csn[i]=++tot),t,1);
	}
	for(int i=0;i<26;i++){
		zm[i]=++tot;
		for(int j=1;j<=cn;j++){
			if(cs[j]==i){
				addedge(zm[i],csn[j],1);
			}
		}
	}
	for(int i=1;i<=yn;i++){
		addedge((ysn[i]=++tot),zm[ys[i]],INF);
		addedge(s,ysn[i],1);
	}
	for(int i=1;i<=zn;i++){
		addedge(zm[pq1[i]],zm[pq2[i]],INF);
	}
}
int main(){
	input();
	build();
	printf("%d",yn-Maxflow());
	return 0;
}
/*
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<vector>
#define M 800
#define INF 0xfffffff
using namespace std;

map<string,int> mp;
vector<int> G[M];
int n,m,k,que[M],d[M],stack[M],g[M][M];
bool v[M];
bool BFS(int s,int t){
	int l=0,r=0,i,p;
	memset(d,-1,sizeof(d));
	d[s]=0;
	que[r++]=s;
	while(l<r){
		p=que[l++];
		for(i=0;i<G[p].size();i++){
			int u=G[p][i];
			if( g[p][u]>0 && d[u]==-1 )	{
				d[u]=d[p]+1;
				if(u==t)return true;
				que[r++]=u;
			}
		}
	}
	return false;
}
int Dinic_Maxflow(int s,int t){
	int i,p;
	int nMinc;
	int minn;
	int ans=0;
	while(BFS(s,t)){
		int top=0,base=0;
		memset(v,false,sizeof(v));
		stack[top++]=s;
		v[s]=true;
		while(top>base)	{
			p=stack[top-1];
			if(p==t){
				minn=INF;
				for(i=1;i<top;i++){
					int u=stack[i-1];
					int v=stack[i];
					if(g[u][v]<minn){
						minn=g[u][v];
						nMinc=u;
					}
				}
				ans+=minn;
				for(i=1;i<top;i++){
					int u=stack[i-1];
					int v=stack[i];
					g[u][v]-=minn;
					g[v][u]+=minn;
				}
				while(top>base && stack[top-1]!=nMinc)top--;
			}
			else {
				for(i=0;i<G[p].size();i++){
					int u=G[p][i];
					if( !v[u] && g[p][u]>0 && d[u]==d[p]+1 ){
						v[u]=true;
						stack[top++]=u;
						break;
					}
				}
				if(i==G[p].size())top--;
			}
		}
	}
	return ans;
}
int main(){
	int index;
	int tot;
	char str[30],ss[30];
	while(scanf("%d",&n)!=EOF){
		index=1;
		mp.clear();
		memset(G,0,sizeof(G));
		memset(g,0,sizeof(g));
		while(n--){
			scanf("%s",str);
			mp[str]=index++;
			G[mp[str]].push_back(M-1);
			g[mp[str]][M-1]=1;
		}
		scanf("%d",&m);
		tot=m;
		while(m--){
			scanf("%s%s",ss,str);
			mp[ss]=index++;
			g[0][mp[ss]]=1;
			if(!mp[str])mp[str]=index++;
			G[0].push_back(mp[ss]);
			G[mp[ss]].push_back(mp[str]);
			G[mp[str]].push_back(mp[ss]);
			g[mp[ss]][mp[str]]=1;
		}
		scanf("%d",&k);
		while(k--){
			scanf("%s%s",ss,str);
			if(!mp[str])mp[str]=index++;
			G[mp[ss]].push_back(mp[str]);
			G[mp[str]].push_back(mp[ss]);
			g[mp[ss]][mp[str]]=INF; 
		}
		printf("%d\n",tot-Dinic_Maxflow(0,M-1));
	}
	return 0;
} 
*/ 
