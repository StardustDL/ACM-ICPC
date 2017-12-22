/*
数字三角形WW
分析：必经一点，可以直接将这个点设为非常大 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25,INF=1<<28;
int opt[MAXN+3][MAXN+3],n;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>opt[i][j];
	opt[n/2][n/2]+=INF;
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			opt[i][j]+=max(opt[i+1][j],opt[i+1][j+1]);
	cout<<opt[1][1]-INF;
	return 0;
}
