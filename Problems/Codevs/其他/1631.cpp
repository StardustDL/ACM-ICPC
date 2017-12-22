/*
组合数
分析：C(n,k)=C(n,k-1)*(n-k+1)/k ，或用杨辉三角形 
*/
#include<iostream>
using namespace std;
const int MOD=100003;
/*int n,k,ans=1;//这份代码为什么错，可能是除法不支持取模 
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		ans=(ans*(n-i+1)/i)%MOD;
	}
	cout<<ans;
	return 0;
}*/
int n,k,a[1003][1003];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i][0]=a[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			a[i][j]=(a[i-1][j]+a[i-1][j-1])%MOD;
		}
	}
	cout<<a[n][k];
	return 0;
}
