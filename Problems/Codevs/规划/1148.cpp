/*
������Ϸ
������Dp[i][j]  ��ʾ����i����j������
	  ��j��������εõ�����һ������j+1��j-1�ڴ�����
	  	Dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
	  ��j=1����������Ϊn��2
	  	Dp[i][j]=dp[i-1][n]+dp[i-1][2]
	  ��j=n����������Ϊn-1��1
		Dp[i][j]= dp[i-1][n-1]+dp[i-1][1]
	  ��ֵ��
		Dp[0][1]=1; 
*/
#include<iostream>
using namespace std;
int n,m,ans=0;
int f[33][33];
int main(){
	cin>>n>>m;
	f[1][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j==1)f[j][i]=f[n][i-1]+f[2][i-1];
			else if(j==n)f[j][i]=f[n-1][i-1]+f[1][i-1];
			else f[j][i]=f[j-1][i-1]+f[j+1][i-1];
		}
	}
	cout<<f[1][m];
	return 0;
}
