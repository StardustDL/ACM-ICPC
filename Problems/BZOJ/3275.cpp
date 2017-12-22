/*
Number
��������С���a [i] Ϊ���������Դ��һ������Ϊa [i] �ߵ�i��
		��a [i] Ϊż�������i��һ������Ϊa [i] �ıߵ��㣻
		��a [i] ,a [j] ���⣬�����������һ������Ϊ�����ıߵ�ż���㣬
		Ȼ�����������a [i] �ĺͼ�ȥ��������Ǵ𰸡� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN=3000+10,INF=0x3f3f3f3f;
struct edge{
	int v,nxt,c;
}es[5000005];
int head[MAXN+3],tot=1;
void _addedge(int u,int v,int c){
	tot++;
	es[tot].v=v;es[tot].c=c;es[tot].nxt=head[u];
	head[u]=tot;
}
void addedge(int u,int v,int c){
	_addedge(u,v,c);
	_addedge(v,u,0);
}
int d[MAXN+3],S,T,cur[MAXN+3];
queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	memset(d,-1,sizeof(d));d[S]=0;
	q.push(S);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=es[i].nxt){
			if(d[es[i].v]==-1 && es[i].c){
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
	for(int &i=cur[u];i;i=es[i].nxt){
		edge &e=es[i];
		if(d[e.v]==d[u]+1){
			int f=dfs(es[i].v,min(a,es[i].c));
			if(f==0)continue;
			flow+=f;a-=f;es[i].c-=f;es[i^1].c+=f;
			if(a==0)break; 
		}
	}
	if(flow==0)d[u]=-1;
	return flow;
}
int maxflow(){
	int ans=0;
	while(bfs()){
		for(int i=1;i<=T;i++)cur[i]=head[i];
		ans+=dfs(S,INF);
	}
	return ans;
}
int n,a[MAXN+3];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
#define sqr(x) ((x)*(x))
bool check(int x,int y){
	int t=x*x+y*y,p=(int)sqrt(t);
	return gcd(x,y)==1 && (p*p==t);
}
int main(){
	scanf("%d",&n);S=n+2,T=S+1;int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);ans+=a[i];
		if(a[i]&1)addedge(S,i,a[i]);
		else addedge(i,T,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(a[i],a[j])){
				if(a[i]&1)addedge(i,j,INF);
				else addedge(j,i,INF);
			}
		}
	}
	printf("%d\n",ans-maxflow());
	return 0;
}

