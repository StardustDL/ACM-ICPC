/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;

namespace LIS{//严格最长上升子序列 
	int dp[MAXN+3];
	int nsqr(int *a,int n){//solve a[1..n]
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			dp[i]=1;//pay attention to this line
			for(int j=1;j<i;j++){
				if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
			}
		}
		return *max_element(dp+1,dp+n+1);
	}
	int nlogn(int *a,int n){
		memset(dp,0,sizeof(dp));int tp=0;//并不用赋值为-INF 
		for(int i=1;i<=n;i++){
			int t=lower_bound(dp+1,dp+tp+1,a[i])-dp;
			if(t==tp+1)tp++;
			dp[t]=a[i];
		}
		return tp;
	}
}
namespace LCS{
	int dp[MAXN+3][MAXN+3];
	int nsqr(int *a,int na,int *b,int nb){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=na;i++){
			for(int j=1;j<=nb;j++){
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				if(a[i]==b[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
		return dp[na][nb];
	}
}
int main(){
	int n,a[1000],b[MAXN+3];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cout<<(LCS::nsqr(a,n,b,n));
	return 0;
}

