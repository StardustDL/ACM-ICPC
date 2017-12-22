/*
数字三角形WWW
分析：必经一点，可以直接将这个点设为非常大，
	  或者从上搜到此点，再从此点搜到最底层，两条路径之和即为答案 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25,INF=1<<28;
int opt[MAXN+3][MAXN+3],n,x,y;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>opt[i][j];
	cin>>x>>y;
	opt[x][y]+=INF;
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			opt[i][j]+=max(opt[i+1][j],opt[i+1][j+1]);
	cout<<opt[1][1]-INF;
	return 0;
}
