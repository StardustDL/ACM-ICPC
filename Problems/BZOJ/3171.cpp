/*
[Tjoi2013]循环格
分析：所有目前不能走的方向费用设为1，费用流跑一下 
		可知每个点的出度=入度=1
		二分图+费用流
		S向每个点连容量1费用0的边
		每个点拆出的点向T连容量1，费用0的边
		每个格子向四周连费用0或1的边
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
struct edge{
	int u,v,nxt,w,c;
}es[1100000];
int head[600+3],tot=1,pre[603],d[603],q[6000+3];
bool inq[603];
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
		int u=q[h++];if(h==6001)h=0;inq[u]=0;
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[es[i].v]>d[u]+es[i].w){
				d[es[i].v]=d[u]+es[i].w;
				pre[es[i].v]=i;
				if(!inq[es[i].v]){
					q[t++]=es[i].v;inq[es[i].v]=1;
					if(t==6001)t=0;
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
int R,C;
int mp[18][18],id[18][18];
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void build(){
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			addedge(S,id[i][j],0,1);
			addedge(id[i][j]+300,T,0,1);
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x<1)x=R;if(x>R)x=1;
				if(y<1)y=C;if(y>C)y=1;
				addedge(id[i][j],id[x][y]+300,mp[i][j]!=k,1);
			}
		}
	}
}
char s[18]; 
int main(){
	S=0,T=601;
	scanf("%d%d",&R,&C);
	for(int i=1;i<=R;i++){
		scanf("%s",s);
		for(int j=1;j<=C;j++){
			switch(s[j-1]){
				case 'L':mp[i][j]=0;break;
				case 'R':mp[i][j]=1;break;
				case 'U':mp[i][j]=2;break;
				case 'D':mp[i][j]=3;break;
			}
			id[i][j]=(i-1)*C+j;
		}
	}
	build();
	while(spfa())augment();
	printf("%d\n",cost);
	return 0;
}

