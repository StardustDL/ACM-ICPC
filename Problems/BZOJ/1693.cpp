/*
[Usaco2007 Demo] Asteroids
分析：行列坐标建二分图，最小点覆盖。 
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=500;
struct edge{
	int to,nx;
}e[MAXN*MAXN+3];
int head[MAXN*MAXN+3],match[MAXN*MAXN+3],used[MAXN*MAXN+3];
int mat,cnt,sum,n,k;
bool b[MAXN+3];
void addedge(int u,int v){
	e[++cnt].to=v;e[cnt].nx=head[u];
	head[u]=cnt;
}
bool find(int s,int now){
	for(int i=head[s];i;i=e[i].nx){
		int v=e[i].to;
		if (used[v]!=now){
			used[v]=now;
			if (!match[v] || find(match[v],now)){
				match[v]=s;
				return true;
			}
		}
	}
	return false;
}
void hungary(){
	memset(match,false,sizeof(match));
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;i++) if (b[i])
		if (find(i,i))mat++;
}
int main(){
	memset(head,0,sizeof(head));
	memset(b,false,sizeof(b));
	mat=cnt=0;
	scanf("%d%d",&n,&k);
	for (int i=1,x,y;i<=k;i++) scanf("%d%d",&x,&y),addedge(x,y+n),b[x]=true;
	hungary();
	printf("%d\n",mat);
	return 0;
}

