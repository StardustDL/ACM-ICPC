#include<iostream>
using namespace std;
int a[51][51],dp[51][51][51][51],n,m;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i1=1;i1<=m;i1++){
		for(int j1=1;j1<=n;j1++){
			for(int i2=1;i2<=m;i2++){
				for(int j2=1;j2<=n;j2++){
					int maxV = max(max(dp[i1-1][j1][i2-1][j2], dp[i1-1][j1][i2][j2-1]), max(dp[i1][j1-1][i2-1][j2], dp[i1][j1-1][i2][j2-1]));
                    if(i1==i2 && j1==j2)
                        dp[i1][j1][i2][j2] = a[i1][j1] + maxV;
                    else
                        dp[i1][j1][i2][j2] = a[i1][j1] + a[i2][j2] + maxV;
				}
			}
		}
	}
	cout<<dp[m][n][m][n];
	return 0;
}
