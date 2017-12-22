/*
[ZJOI2009]假期的宿舍
分析：最大流，源点向所有有床位的连边
		需要床位的向汇点连边
		如果i可以睡j的床
		i向j‘连边 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct edge{
	int v,nxt,c;
}es[100*100+100];
int tot=1,head[110+3],d[110+3];
int S,T;
queue<int> q;
void _addedge(int u,int v,int c){
	++tot;
	es[tot].v=v;es[tot].c=c;es[tot].nxt=head[u];head[u]=tot;
}
void addedge(int u,int v,int c){
	_addedge(u,v,c);
	_addedge(v,u,0);
}
bool bfs(){
	while(!q.empty())q.pop();
	q.push(S);memset(d,-1,sizeof(d));
	d[S]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[es[i].v]==-1){
				d[es[i].v]=d[u]+1;
				q.push(es[i].v);
			}
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0;
	for(int i=head[u];i;i=es[i].nxt){
		if(es[i].c && d[es[i].v]==d[u]+1){
			int w=dfs(es[i].v,min(a,es[i].c));
			if(w==0)continue;
			flow+=w;a-=w;
			es[i].c-=w;es[i^1].c+=w;
		}
	} 
	if(flow==0)d[u]=-1;
	return flow;
}
int t,n,flg[55],ans;
int main(){
	for(scanf("%d",&t);t;t--){
		scanf("%d",&n);ans=0;memset(head,0,sizeof(head));tot=1;S=2*n+1,T=S+1;
		for(int i=1,x;i<=n;i++){
			scanf("%d",&flg[i]);
			if(flg[i]){
				addedge(S,i,1);
				//addedge(i+n,T,1);
			}
		}
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			if((flg[i] && !x) || !flg[i]){
				//addedge(S,i,1);
				addedge(i+n,T,1);
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int x,j=1;j<=n;j++){
				scanf("%d",&x);
				if(x||i==j)addedge(i,j+n,1);
			}
		}
		while(bfs())ans-=dfs(S,0x3f3f3f3f);
		//cout<<ans<<endl;
		puts(ans==0?"^_^":"T_T");
	}
	return 0;
}

