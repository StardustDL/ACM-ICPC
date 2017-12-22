/*
Largest Submatrix of All 1’s
题意：最大子矩阵
分析：模板题
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int l[MAXN+3],r[MAXN+3],d[MAXN+3],n,m;
int work(bool K){
	int k,t,ans=0;
	memset(d,0,sizeof(d)); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l[j]=r[j]=j;
			if(mp[i][j]==K)d[j]++;
			else d[j]=0;
		}
		for(int j=1;j<=m;j++)if(d[j])while(d[l[j]-1]>=d[j])l[j]=l[l[j]-1];
		for(int j=m;j>=1;j--)if(d[j])while(d[r[j]+1]>=d[j])r[j]=r[r[j]+1];
		for(int j=1;j<=m;j++){
			k=r[j]-l[j]+1;
			ans=max(ans,k*d[j]);
		}
	}
	return ans;
}
int main(){
	int T,t;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&mp[i][j]);
		printf("%d\n",work(1));
	}
	return 0;
}

