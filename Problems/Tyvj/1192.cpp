#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,dp[MAXN+3][MAXN+3],map[MAXN+3][MAXN+3],ans=0;
int main(){
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*(n-i+1)-1;j++){
			cin>>c;
			if(c=='-')map[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*(n-i+1)-1;j++){
			if(!map[i][j])continue;
			if(!map[i-1][j+1]){
				dp[i][j]=1;continue;
			}
			dp[i][j]=min(dp[i-1][j],dp[i-1][j+2])+1;
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans*ans;
	return 0;
}
