/*
最大和
分析：如果不是圈，则直接dp[i]=max(dp[i-1]+a[i],0) 
	  由于是圈，那么维护一个当前求和递增序列的长度cnt，
	  cnt>=n时，要将指针指向新区间起点n-i+1，并且那个位置要赋值为0 
	  注意如果直接枚举起点，那么会超时：
	  for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));
		for(int j=0;j<n;j++){
			dp[i+j]=max(dp[i+j-1]+a[i+j],dp[i+j]);
			ans=max(dp[i+j],ans);
		}
	} 因为一部分起点是达不到最优解的 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000;
int n,a[2*MAXN+3];
long dp[2*MAXN+3],ans=-100000000,cnt=0;
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)dp[i]=-100000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		if(a[i]>dp[i-1]+a[i]){
			cnt=1;
			dp[i]=a[i];
			ans=max(dp[i],ans);
		}
		else{
			dp[i]=dp[i-1]+a[i];
			ans=max(dp[i],ans);
			if(++cnt>=n)dp[i=i-n+1]=cnt=0;
		}
	}
	cout<<ans;
	return 0;
}
