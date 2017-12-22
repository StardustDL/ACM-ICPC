/*
Truck History
题意：用一个7位的string代表一个编号，两个编号之间的distance代表这两个编号之间不同字母的个数。一个编号只能由另一个编号“衍生”出来，代价是这两个编号之间相应的distance，现在要找出一个“衍生”方案，使得总代价最小，也就是distance之和最小。 
分析：问题可以转化为最小代价生成树的问题。因为每两个结点之间都有路径，所以是完全图。关键是将问题转化为最小生成树的问题。每一个编号为图的一个顶点，顶点与顶点间的编号差即为这条边的权值，题目所要的就是我们求出最小生成树来。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
	edge(){}
	bool operator < (const edge &e)const {
		return w<e.w; 
	}
}es[MAXN*MAXN+3];
int n,ans=0,tot=0,pa[MAXN+3];
char str[MAXN+3][13];
int calcw(int i,int j){
	int ans=0;
	for(int l=0;l<7;l++){
		if(str[i][l]!=str[j][l])ans++;
	}
	return ans;
}
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int main(){
	while(scanf("%d",&n),n){
		ans=tot=0;memset(pa,0,sizeof(pa));
		for(int i=1;i<=n;i++)getchar(),scanf("%s",str[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				es[++tot]=edge(i,j,calcw(i,j));
			}
		}
		
		sort(es+1,es+tot+1);//cout<<"!!!"<<endl; 
		for(int i=1,cnt=0,a,b;i<=tot&&cnt<n-1;i++){
			a=find(es[i].u),b=find(es[i].v);
			if(a!=b)pa[a]=b,cnt++,ans+=es[i].w; 
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}

