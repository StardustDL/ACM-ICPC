/*
[Ceoi2008]order
分析：最小割，S->每个任务，每个任务->对应机器，机器->T，注意dinic的各种优化不能少 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct edge{
	int v,nxt,c;
}es[3000000+3];
int tot=1,head[1200*2+100+3],d[1200*2+100+3],cur[1200*2+100+3];
int S,T;
int q[1200*2+100+3];
void _addedge(int u,int v,int c){
	++tot;
	es[tot].v=v;es[tot].c=c;es[tot].nxt=head[u];head[u]=tot;
}
void addedge(int u,int v,int c){
	_addedge(u,v,c);
	_addedge(v,u,0);
}
bool bfs(){
	int h=0,t=0;q[t++]=S;
	memset(d,-1,sizeof(d));
	d[S]=0;
	while(h!=t){
		int u=q[h++];if(h==1200*2+100)h=0;
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[es[i].v]==-1){
				d[es[i].v]=d[u]+1;
				q[t++]=es[i].v;if(t==1200*2+100)t=0;
			}
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0;
	for(int &i=cur[u];i;i=es[i].nxt){//当前弧 
		if(es[i].c && d[es[i].v]==d[u]+1){
			int w=dfs(es[i].v,min(a,es[i].c));
			if(w==0)continue;
			flow+=w;a-=w;
			es[i].c-=w;es[i^1].c+=w;
			if(a==0)break;//这里如果没有就会T 
		}
	} 
	if(flow==0)d[u]=-1;
	return flow;
}
int maxflow(){
	int ans=0;
	while(bfs()){
		for(int i=1;i<=T;i++)cur[i]=head[i];
		ans+=dfs(S,0x3f3f3f3f);
	}
	return ans;
}
int n,m,ans=0;
int main(){
	scanf("%d%d",&n,&m);S=n+m+2,T=S+1;
	for(int i=1,w,c;i<=n;i++){
		scanf("%d%d",&w,&c);
		ans+=w;addedge(S,i,w);
		for(int j=1,a,b;j<=c;j++){
			scanf("%d%d",&a,&b);
			addedge(i,a+n,b);
		}
	}
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		addedge(i+n,T,x);
	}
	printf("%d\n",ans-maxflow());
	return 0;
}

