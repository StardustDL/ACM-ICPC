/*
[Usaco2008 Feb]Eating Together麻烦的聚餐
分析：最长不下降子序列 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=30000,INF=0x3f3f3f3f;
int n,d[MAXN+3],opt[MAXN+3],g[4],ans=INF; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	memset(g,0,sizeof(g));memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[i];j++)opt[i]=max(opt[i],g[j]+1);
		g[d[i]]=max(g[d[i]],opt[i]);
	}
	ans=min(ans,n-*max_element(g+1,g+3+1));
	memset(g,0,sizeof(g));memset(opt,0,sizeof(opt));
	for(int i=n;i>=1;i--){
		for(int j=1;j<=d[i];j++)opt[i]=max(opt[i],g[j]+1);
		g[d[i]]=max(g[d[i]],opt[i]);
	}
	ans=min(ans,n-*max_element(g+1,g+3+1));
	printf("%d\n",ans);
	return 0;
}

