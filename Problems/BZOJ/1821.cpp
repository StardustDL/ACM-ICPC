/*
[JSOI2010]Group 部落划分
分析：最小生成树 ，尽量将近的并到一起 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define sqr(x) ((x)*(x))
const int MAXN=1000,INF=0x3f3f3f3f;
struct edge{
	int u,v;double w;
	bool operator <(const edge&e)const{
		return w<e.w;
	};
}es[MAXN*MAXN+3];
int pa[MAXN+3],N,K,x[MAXN+3],y[MAXN+3],tot=0;
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
inline double dist(int i,int j){
	return sqr(x[j]-x[i])+sqr(y[j]-y[i]);
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			es[++tot].u=i;es[tot].v=j;es[tot].w=dist(i,j);
		}
	}
	sort(es+1,es+tot+1);double ans=-1;
	for(int i=1;i<=tot;i++){
		int a=find(es[i].u),b=find(es[i].v);
		if(a==b)continue;
		if(N>K){
			pa[a]=b;
			N--;
		}
		else{
			ans=es[i].w;
			break;
		}
	}
	printf("%.2lf\n",sqrt(ans));
	return 0;
}

