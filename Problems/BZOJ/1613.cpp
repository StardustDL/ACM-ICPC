/*
[Usaco2007 Jan]Running贝茜的晨练计划
分析：DP dp[i , j]表示第i秒疲劳度为j的最大距离。
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000,MAXM=500;
int n,m,d[MAXN+3],opt[MAXN+3][MAXM+3];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>d[i];
	memset(opt,0,sizeof(opt));
}
int dp(){
	for(int i=1;i<=n;i++){
		opt[i][0]=max(opt[i][0],opt[i-1][0]);
		for(int j=1;j<=m;j++){
			opt[i][j]=max(opt[i][j],opt[i-1][j-1]+d[i]);
			if(i>=j)opt[i][0]=max(opt[i][0],opt[i-j][j]);
		}
	}
	return opt[n][0];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<dp();
	return 0;
} 
