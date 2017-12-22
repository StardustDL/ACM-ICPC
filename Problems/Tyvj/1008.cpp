#include<iostream>
#include<cstring>
using namespace std;
int n,m,f[31][31];
int main(){
	cin>>n>>m;
	f[0][1]=1;
	for(int i=1;i<=m;i++){
		f[i][1]=f[i-1][n]+f[i-1][2];
		f[i][n]=f[i-1][n-1]+f[i-1][1];
		for(int j=2;j<n;j++){
			f[i][j]=f[i-1][j-1]+f[i-1][j+1];
		}
	}
	cout<<f[m][1];
	return 0;
}
