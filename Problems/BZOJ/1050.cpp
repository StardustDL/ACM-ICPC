/*
[HAOI2006]旅行comf
分析：注意边数较小，将边排序，然后枚举最小边，再从小到大添加边，直到st联通，联通信息用并查集维护 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500,MAXM=5000,INF=0x3f3f3f3f;
int n,m,s,t,pa[MAXN+3];
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}es[MAXM+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)pa[a]=b;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int ans1=30001,ans2=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
	scanf("%d%d",&s,&t);
	sort(es+1,es+m+1);
	for(int i=1,j;i<=m;i++){
		memset(pa,0,sizeof(pa));
		for(j=i;j<=m;j++){
			unite(es[j].u,es[j].v);
			if(find(s)==find(t))break;
		}
		if(j<=m&&ans1*es[i].w>ans2*es[j].w)ans1=es[j].w,ans2=es[i].w;
	}
	if(ans1==30001)puts("IMPOSSIBLE");
	else{
		int g=gcd(ans1,ans2);
		ans1/=g,ans2/=g;
		if(ans2!=1)printf("%d/%d",ans1,ans2);
		else printf("%d",ans1);
	}
	return 0;
}

