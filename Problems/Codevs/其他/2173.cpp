/*
忠诚
分析：区间最小值，RMQ问题 
*/ 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100000,MAXP=16+1;//16=ln(100000)/ln(2)
int f[MAXN+3][MAXP],a[MAXN+3],n,m,x,y;
void rmq(int *arr,int n){
	for(int i=1;i<=n;i++)f[i][0]=arr[i];
	for(int j=1;(1<<j)<=n;j++){//注意先枚举区间长 
		for(int i=1;i+(1<<j)-1<=n;i++){//枚举区间起点 
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
int minquery(int l,int r){
	int k=log(r-l+1)/log(2);//计算区间长度是2的几次幂 
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	rmq(a,m);
	while(n-->0){
		cin>>x>>y;
		cout<<minquery(x,y)<<" ";
	}
	return 0;
} 
