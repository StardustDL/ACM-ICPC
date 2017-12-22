/*
失恋28天-缝补礼物
分析：正解应是多重背包，但由于范围较小，直接当成01背包即可
	  注意如果这么做，时间和价值是不要乘个数的，那样就又成了多重背包了。 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100,MAXM=10000;
int n,m,p[MAXN+3],w[MAXN+3],h[MAXN+3],opt[MAXM+3];
int dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=h[i];j++){
			for(int k=m;k>=p[i];k--)
				opt[k]=max(opt[k],opt[k-p[i]]+w[i]);
		}
	}
	return opt[m];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>p[i]>>w[i]>>h[i];
	cout<<dp();
	return 0;
}
