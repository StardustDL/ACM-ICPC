/*
摆花
分析：类似多重背包，即有限制物品数量的背包
	  opt[i][j]表示前i个物品，放入j个花盆的方案数
	  则有opt[i][j]=sum{opt[i-1][j-k]|0<=k<=min(j,i物品件数)} 
	  注意边界opt[i][0]=1，j从1开始枚举 
	  还有一种：opt[0][0]=1，j从0开始枚举（否则opt[i][0]一直为0） 
*/
#include<iostream>
using namespace std;
const int MOD=1000007,MAXN=100;
int n,m,a[MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)opt[i][0]=1; 
	for(int i=1;i<=n;i++){//枚举物品 
		for(int j=1;j<=m;j++){//枚举容量 
			for(int k=0;k<=min(j,a[i]);k++){//枚举装入个数，从0开始 
				opt[i][j]=(opt[i][j]+opt[i-1][j-k])%MOD;
			}
		}
	}
	cout<<opt[n][m];
	return 0;
}
