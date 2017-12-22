/*
乌龟棋
分析：简单的背包DP不好表示状态，要改用dp[i][j][k][l]表示每种卡片用几张的最优解
	  此题很好，利于拓展思路 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int card[5],s[352],dp[41][41][41][41],n,m,x;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=m;i++){
		cin>>x;
		card[x]++;
	}
	dp[0][0][0][0]=s[1];
	for(int i=0;i<=card[1];i++){
		for(int j=0;j<=card[2];j++){
			for(int k=0;k<=card[3];k++){
				for(int l=0;l<=card[4];l++){
					if(i+j+k+l==0)continue;
					int maxs=0;
					if(i-1>=0)
						maxs=max(maxs,dp[i-1][j][k][l]);
					if(j-1>=0)
						maxs=max(maxs,dp[i][j-1][k][l]);
					if(k-1>=0)
						maxs=max(maxs,dp[i][j][k-1][l]);
					if(l-1>=0)
						maxs=max(maxs,dp[i][j][k][l-1]);
					dp[i][j][k][l]=s[1*i+2*j+3*k+4*l+1]+maxs;
				}
			}
		}
	}
	cout<<dp[card[1]][card[2]][card[3]][card[4]];
	return 0;
}
