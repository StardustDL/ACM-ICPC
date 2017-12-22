/*
[SCOI2009]粉刷匠
分析：先对每一行做一个f[i][j]的dp，求出这一行的前i个涂了j次的最优值，
	  然后行与行之间分组背包。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,T,f[55][55],g[55][2500+5],sum[55];
char str[55];
int main(){
	scanf("%d%d%d",&n,&m,&T); 
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)sum[j]=sum[j-1]+str[j]-'0';
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				int &t=f[j][k];t=0;
				for(int l=0;l<j;l++)
					t=max(t,f[l][k-1]+max((sum[j]-sum[l]),(j-l-(sum[j]-sum[l]))));
			}
		}
		for(int j=1;j<=T;j++){
			for(int k=0,&t=g[i][j];k<=min(m,j);k++){
				t=max(t,g[i-1][j-k]+f[m][k]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=T;i++)ans=max(ans,g[n][i]);
	printf("%d\n",ans);
	return 0;
}

