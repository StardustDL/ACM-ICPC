/*
The Triangle
分析：数字三角形 
*/
#include<iostream>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3][MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)cin>>a[i][j];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	cout<<a[1][1];
	return 0;
} 
