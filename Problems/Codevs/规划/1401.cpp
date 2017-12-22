/*
逆序统计
分析：xi表示前i个数中，比第i个数大的数的个数，
	  那么逆序对数=x1+x2+x3+x4+...xn
	  题目要求变为 x1+x2+x3+x4+...xn=k，求x可能的取值方案数
	  通过si=xi+1，这样去掉xi=0的可能，转成数的划分（可重复）
	  求解s1+s2+s3+s4+...+sn=k+n
	  opt[i][j]表示 s1+s2+s3+...+si=j的方案数 
*/
#include<iostream>
using namespace std;
const int MAXN=100,MAXK=(MAXN*MAXN)>>1,MOD=10000;
int opt[MAXN+3][MAXK+MAXN+3],n,k;
int dp(){
	opt[0][0]=1;
	//for(int i=0;i<=n+k;i++)opt[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k+n;j++){
			for(int l=1;l<=i;l++){
				opt[i][j]=(opt[i][j]+opt[i-1][j-l])%MOD;
			}
		}
	}
	return opt[n][n+k];
}
int main(){
	cin>>n>>k;
	cout<<dp();
	return 0;
}
