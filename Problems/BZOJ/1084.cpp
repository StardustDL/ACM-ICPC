/*
[SCOI2005]����Ӿ���
������ע��m<=2����һά��ά����
	  һάö�����һ�μ���
	  ��ά�����֣���һ�е����һ�Σ��ڶ��е����һ�Σ������ǰ״̬������ͬһ�У���ôö��֮ǰ��һ�У����һ����һ������  
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

