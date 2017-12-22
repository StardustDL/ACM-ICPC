/*
[JLOI2011]飞行路线
分析：按已经使用了多少次优惠分层，spfa 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000,MAXQ=10*MAXN+100,INF=0x3f3f3f3f;
struct edge{
	int v,nxt,w;
}es[50000*2+3];
int head[MAXN+3],tot=0;
int d[MAXN+3][13],q[MAXQ+3][2];
bool inq[MAXN+3][13];
int n,m,S,T,k;
void addedge(int u,int v,int w){
	++tot;
	es[tot].v=v;es[tot].w=w;es[tot].nxt=head[u];head[u]=tot;
}
int h,t;
void push(int u,int tk){
	q[t][0]=u;q[t][1]=tk;
	inq[u][tk]=1;t++;
	if(t==MAXQ+1)t=0;
}
int spfa(int S,int T){
	memset(d,INF,sizeof(d));
	h=0;t=0;d[S][0]=0;push(S,0);
	while(h!=t){
		int u=q[h][0],tk=q[h][1];h++;if(h==MAXQ+1)h=0;inq[u][tk]=0;
		for(int i=head[u];i;i=es[i].nxt){
			int v=es[i].v,w=es[i].w;
			if(d[v][tk]>d[u][tk]+w){
				d[v][tk]=d[u][tk]+w;
				if(!inq[v][tk])push(v,tk);
			}
			if(d[v][tk+1]>d[u][tk] && tk+1<=k){
				d[v][tk+1]=d[u][tk];
				if(!inq[v][tk+1])push(v,tk+1);
			}
		}
	}
	//for(int i=0;i<=k;i++)cout<<d[T][i]<<" ";
	return *min_element(d[T],d[T]+k+1);
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&S,&T);
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);addedge(b,a,c);
	}
	printf("%d\n",spfa(S,T)); 
	return 0;
}

