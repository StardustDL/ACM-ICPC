/*
[ZJOI2009]狼和羊的故事
分析：挖掘栅栏的本质：只能建在相邻两个，且建好后使得狼和羊之间不存在通路。而割的定义是：使S集和T集不存在通路。而题目又要求建的栅栏最少，于是就是最小割问题了。
		从源点向所有狼连一条∞的边，从所有羊向汇点连一条∞的边，这样就能保证狼和羊都在不同的点集里。然后再从狼到相邻的羊和空地，空地到相邻的空地和羊连一条流量为1的边，最大流求最小割即可。 
	  用vector常数爆炸= = 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
int n,m,a[MAXN+3][MAXN+3];
int head[10005],q[10005],h[10005],cnt=1;
struct edge{
	int v,c,nxt;
}e[500001];
void ins(int u,int v,int w)
{e[++cnt].v=v;e[cnt].nxt=head[u];e[cnt].c=w;head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);}
int S,T,d[100*100+3];
bool bfs(){
	memset(d,-1,sizeof(d));
	int t=0,w=1;
	d[S]=0;
	q[0]=S;
	while(t<w){
		int u=q[t];t++;
		for(int i=head[u];i;i=e[i].nxt){
			if(e[i].c&&d[e[i].v]==-1){
				d[e[i].v]=d[u]+1;
				q[w++]=e[i].v;
			}
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0,f;
	for(int i=head[u];i;i=e[i].nxt){
		if(e[i].c&&d[e[i].v]==d[u]+1){
			int w=a-flow;
			w=dfs(e[i].v,min(w,e[i].c));
			flow+=w;
			e[i].c-=w;
			e[i^1].c+=w;
			a-=f;
			if(a==0)break;
		}
	}
	if(flow==0)d[u]=-1;
	return flow;
}
int Maxflow(){
	int ans=0;
	while(bfs()){
		ans+=dfs(S,INF);
	}
	return ans;
}
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int main(){
	scanf("%d%d",&n,&m);S=n*m+1,T=S+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(a[i][j]==1)insert(S,(i-1)*m+j,INF);
        else if(a[i][j]==2)insert((i-1)*m+j,T,INF);
    	for(int k=0;k<4;k++)
    	{
            int nowx=i+xx[k],nowy=j+yy[k];
            if(nowx<1||nowx>n||nowy<1||nowy>m||a[i][j]==2)continue;
            if(a[i][j]!=1||a[nowx][nowy]!=1)
            	insert((i-1)*m+j,(nowx-1)*m+nowy,1);
        }
    }
	printf("%d\n",Maxflow());
	return 0;
}
