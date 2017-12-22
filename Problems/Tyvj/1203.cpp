#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,m,a[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
}
int solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=j;k++){
				opt[i][j]=max(opt[i][j],opt[i-1][j-k]+a[i][k]);
			}
		}
	}
	return opt[n][m];
}
int main(){
	ios::sync_with_stdio(false);
	read();
	cout<<solve();
	return 0;
}

