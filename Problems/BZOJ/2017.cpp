/*
[Usaco2009 Nov]硬币游戏
分析：一个思路就是从游戏结束开始向前dp，dp到最初状态时自然就知道最大能得到多少钱了，但是从后向前dp有一个问题就是需要直到前一步对方拿了多少硬币，才能知道当前能拿多少，因此用一维标记一下前一步对方拿了多少即可，于是就用f[i][j]表示还剩i枚硬币时前一步对手拿了j枚硬币的情况下，自己最多能得到多少钱。
		状态转移方程为f[i][j]=max{sum[i]-f[i-k][k]}(1<=k<=min{2*j,i})，其中sum[i]表示剩下的i枚硬币的价值和。
		优化转移：
			DP[c][p] = max{SUM[1][c] - DP[c-i][i]}   1 <=i<=min(2*p, c)
    		DP[c][p+1] = max{SUM[1][c] - DP[c-i][i]} 1 <=i<=min(2*(p+1), c)
               = max{DP[c][p], SUM[1][c] - DP[c-(2*p+1)][2*p+1],SUM[1][c] - DP[c-(2*p+2)][2*p+2]}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
int n,a[MAXN+3],sum[MAXN+3],f[MAXN+3][MAXN+3]; 
int main(){
	scanf("%d",&n);
	for(int i=n;i>=1;i--)scanf("%d",&a[i]);
	sum[0]=0;for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	memset(f[0],0,sizeof(f[0]));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i][j-1];
			if(i>=2*j)f[i][j]=max(f[i][j],sum[i]-f[i-2*j][2*j]);
			if(i>=2*j-1)f[i][j]=max(f[i][j],sum[i]-f[i-(2*j-1)][2*j-1]);
		}
	}
	printf("%d\n",f[n][1]);
	return 0;
}

