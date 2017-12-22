/*
[HNOI2001] 软件开发
分析：最小费用最大流 
		每天拆成两个点，源点提供买毛巾的费用，天与天之间是洗毛巾的费用，注意第1天用的毛巾第2天才会开始洗，要多加一天 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000+10,MAXE=1000000+10,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,c,nxt;
}es[MAXE+3];
int head[MAXN+3],tot=1,d[MAXN+3],pre[MAXN+3],S,T;
bool inq[MAXN+3];
int q[10*MAXN+3];
void _addedge(int u,int v,int w,int c){
	tot++;
	es[tot].u=u,es[tot].v=v,es[tot].w=w,es[tot].c=c;
	es[tot].nxt=head[u];head[u]=tot;
}
void addedge(int u,int v,int w,int c){
	_addedge(u,v,w,c);
	_addedge(v,u,-w,0);
}
bool spfa(){
	memset(d,INF,sizeof(d));memset(pre,0,sizeof(pre));
	d[S]=0;
	int h=0,t=1;q[h]=S;
	while(h<t){
		int u=q[h++];inq[u]=0;
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[u]+es[i].w<d[es[i].v]){
				d[es[i].v]=d[u]+es[i].w;
				pre[es[i].v]=i;
				if(!inq[es[i].v]){
					inq[es[i].v]=1;
					q[t++]=es[i].v;
				}
			}
		}
	}
	return d[T]<INF;
}
int cost=0;
int augment(){
	int flow=INF;
	for(int i=pre[T];i;i=pre[es[i].u]){
		flow=min(flow,es[i].c);
	}
	cost+=flow*d[T];
	for(int i=pre[T];i;i=pre[es[i].u]){
		es[i].c-=flow;es[i^1].c+=flow;
	}
	//cout<<flow<<endl;
	return flow;
}
int n,a,b,f,fa,fb;
int main(){
	scanf("%d%d%d%d%d%d",&n,&a,&b,&f,&fa,&fb);
	S=0;T=2*n+5;
	for(int i=1;i<=n;i++){
		if(i+1<=n)addedge(i,i+1,0,INF);
		if(i+a+1<=n)addedge(i,n+i+a+1,fa,INF);
		if(i+b+1<=n)addedge(i,n+i+b+1,fb,INF);
		addedge(S,n+i,f,INF);
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		addedge(S,i,0,x);
		addedge(n+i,T,0,x);
	}
	while(spfa())augment();
	printf("%d\n",cost);
	return 0;
}

