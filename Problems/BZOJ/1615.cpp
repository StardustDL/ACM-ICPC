/*
[Usaco2008 Mar]The Loathesome Hay Baler麻烦的干草打包机
分析：bfs，但是注意齿轮带动判的是相切 
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1050; 
#define sqr(x) ((x)*(x))
#define tangent(i,j) (sqr(r[i]+r[j])==sqr(x[i]-x[j])+sqr(y[i]-y[j]))
int n,ex,ey,first,last;
double ans,v[MAXN+3];
int fa[MAXN+3],x[MAXN+3],y[MAXN+3],r[MAXN+3];
bool vis[MAXN+3];
queue<int> q;
void bfs(){
	q.push(first);v[first]=10000;vis[first]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=n;i++){
			if(vis[i] || !tangent(u,i))continue;
			vis[i]=1;fa[i]=u;q.push(i);
			v[i]=v[u]*r[u]/r[i];
			if(i==last)return;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&ex,&ey);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		if(!x[i]&&!y[i])first=i;
		if(x[i]==ex&&y[i]==ey)last=i;
	}
	bfs();
	for(int i=last;i;i=fa[i])ans+=v[i];
	printf("%d\n",(int)ans);
	return 0;
}
