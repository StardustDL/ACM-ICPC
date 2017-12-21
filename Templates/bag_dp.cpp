/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int dp[MAXN+3][MAXN+3];
int ZeroOne_Bag(int *v,int *w,int n,int V){//01背包，不一定装满 
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=V;j>=v[i];j--)dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
	}
	/*
	//01背包，一定装满 
	memset(dp,-INF,sizeof(dp));memset(dp[0],0,sizeof(dp[0]));
	for(int i=1;i<=n;i++){
		for(int j=V;j>=v[i];j--)dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
	}
	*/
	return dp[n][V]; 
}
int Complete_Bag(int *v,int *w,int n,int V){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=V;j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j-v[i]]+w[i],dp[i][j-v[i]]+w[i]));
		}
	}
	//for(int i=1;i<=n;i++)for(int j=v[i];j<=V;j++)dp[j]=max(dp[j],d[j-v[i]]);
	return dp[n][V];
}
int Multi_Bag(int *v,int *w,int *c,int n,int V){
	static int opt[MAXN+3],que[MAXN+3],g[MAXN+3];
	memset(opt,0,sizeof(opt));//如果不用滚动数组，记着dp[i]=dp[i-1] 复制一下 
	for(int i=1;i<=n;i++){
		if(c[i]==-1)c[i]=V/v[i];
		for(int j=0;j<v[i];j++){
			int l=1,r=0;
			for(int k=j;k<=V;k+=v[i]){
				while(l<=r&&g[r]<opt[k]-k/v[i]*w[i])r--;
				que[++r]=k;
				g[r]=opt[k]-k/v[i]*w[i];
				while(que[l]<k-v[i]*c[i])l++;
				opt[k]=g[l]+k/v[i]*w[i];
			}
		}
	}
	//for(int i=1;i<=n;i++)for(int j=v[i];j<=V;j++)dp[j]=max(dp[j],d[j-v[i]]);
	return opt[V];
}
int v[MAXN+3],w[MAXN+3],c[MAXN+3],n,V;
int main(){
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&v[i],&w[i],&c[i]);
	printf("%d",Multi_Bag(v,w,c,n,V));
	return 0;
	return 0;
}

