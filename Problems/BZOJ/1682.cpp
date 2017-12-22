/*
[Usaco2005 Mar]Out of Hay ¸É²ÝÎ£»ú
·ÖÎö£ºKruskal 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,MAXM=10000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}es[MAXM+3];
int n,m,pa[MAXN+3],cnt;
int find(int x){
	return pa[x]?pa[x]=find(pa[x]):x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
	sort(es+1,es+m+1);
	cnt=n;int pos;
	for(pos=1;pos<=m;pos++){
		if(find(es[pos].u)==find(es[pos].v))continue;
		else pa[find(es[pos].u)]=find(es[pos].v),cnt--;
		if(cnt==1)break;
	}
	printf("%d\n",es[pos].w);
	return 0;
}

