/*
[HAOI2010]订货
分析：费用流 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
struct edge{
	int u,v,nxt,w,c;
}es[50*50*4+3];
int head[55+3],tot=1,pre[55+3],d[55+3],q[500+3];
bool inq[55+3];
void _addedge(int u,int v,int w,int c){
	tot++;
	es[tot].u=u,es[tot].v=v,es[tot].w=w,es[tot].c=c;
	es[tot].nxt=head[u];head[u]=tot;
}
void addedge(int u,int v,int w,int c){
	_addedge(u,v,w,c);
	_addedge(v,u,-w,0);
}
int S,T;
bool spfa(){
	memset(d,INF,sizeof(d));memset(inq,0,sizeof(inq));memset(pre,0,sizeof(pre));
	d[S]=0;int h=0,t=0;q[t++]=S;inq[S]=1;
	while(h!=t){
		int u=q[h++];if(h==501)h=0;inq[u]=0;
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[es[i].v]>d[u]+es[i].w){
				d[es[i].v]=d[u]+es[i].w;
				pre[es[i].v]=i;
				if(!inq[es[i].v]){
					q[t++]=es[i].v;inq[es[i].v]=1;
					if(t==501)t=0;
				}
			}
		}
	}
	return d[T]<INF;
}
int cost=0;
void augment(){
	int flow=INF;
	for(int i=pre[T];i;i=pre[es[i].u]){
		flow=min(flow,es[i].c);
	}
	cost+=flow*d[T];
	for(int i=pre[T];i;i=pre[es[i].u]){
		es[i].c-=flow;
		es[i^1].c+=flow;
	}
}
int n,m,s;
int main(){
	S=0,T=52;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		addedge(i,T,0,x);
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		addedge(S,i,x,INF);
	}
	for(int i=1;i<n;i++)addedge(i,i+1,m,s);
	while(spfa())augment();
	printf("%d\n",cost);
	return 0;
}

