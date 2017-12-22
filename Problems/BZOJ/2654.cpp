/*
分析：给白色边都加上一个值，做mst会使得选取的白边数量减少，所以可以二分加的这个值，使得白色边能满足条件的前提下最小化权值和 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int n,m,cnt,tot,ned,ans;
int u[MAXN+3],v[MAXN+3],w[MAXN+3],c[MAXN+3],fa[(MAXN>>1)+3];
struct edge{
	int u,v,w,c;
}e[MAXN+3];
bool operator<(edge a,edge b){
	return a.w==b.w?a.c<b.c:a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool check(int x){
	tot=cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		e[i].u=u[i],e[i].v=v[i],e[i].w=w[i];e[i].c=c[i];
		if(!c[i])e[i].w+=x;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if(p!=q){
			fa[p]=q;
			tot+=e[i].w;
			cnt+=(!e[i].c);
		}
	}
	return cnt>=ned;
}
int main(){
	scanf("%d%d%d",&n,&m,&ned);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u[i],&v[i],&w[i],&c[i]);
		u[i]++;v[i]++;
	}
	int l=-105,r=105;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=tot-ned*mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
