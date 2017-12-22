/*
[SCOI2005]最大子矩阵
分析：注意m<=2，按一维二维分类
	  一维枚举最后一段即可
	  二维有三种：第一列的最后一段，第二列的最后一段，如果当前状态两列在同一行，那么枚举之前的一行，最后一段是一个矩阵  
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
int n,m,K;
int a[MAXN+3][3],sum[MAXN+3][3],f[MAXN+3][13],g[MAXN+3][MAXN+3][13]; 
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)sum[j][i]=a[j][i]+sum[j-1][i];
	if(m==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=K;j++){
				f[i][j]=f[i-1][j];
				for(int t=0;t<i;t++)f[i][j]=max(f[i][j],f[t][j-1]+sum[i][m]-sum[t][m]);
			}
		}
		printf("%d\n",f[n][K]);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=K;k++){
					int &x=g[i][j][k];
					x=max(x,max(g[i-1][j][k],g[i][j-1][k]));
					for(int t=0;t<i;t++)x=max(x,max(g[t][j][k-1]+sum[i][1]-sum[t][1],g[i][t][k-1]+sum[j][2]-sum[t][2]));
					if(i==j){
						for(int t=0;t<i;t++)x=max(x,g[t][t][k-1]+sum[i][1]-sum[t][1]+sum[j][2]-sum[t][2]);
					}
				}
			}
		}
		printf("%d\n",g[n][n][K]);
	}
	return 0;
}

