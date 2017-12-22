/*
∑Ω∏Ò”Œœ∑
*/
#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=103;
int n,mp[MAXN][MAXN],opt[MAXN*2+3][MAXN][MAXN];
int dp(){
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				opt[i][j][k]=
					max(opt[i-1][j-1][k],opt[i-1][j][k-1])
					+abs(mp[j][i-j+1]-mp[k][i-k+1]);
			}
		}
	}
	return opt[2*n-1][n][n];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>mp[i][j];
	cout<<dp()<<endl;
	/*for(int i=1;i<=n;i++)
		{for(int j=1;j<=n;j++)cout<<opt[2*n-1][i][j]<<" ";
		cout<<endl;}*/
	return 0;
}
