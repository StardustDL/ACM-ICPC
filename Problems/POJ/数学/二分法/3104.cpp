/*
Drying
题意：有一些衣服，每件衣服有一定水量，有一个烘干机，每次可以烘一件衣服，每分钟可以烘掉k滴水。每件衣服没分钟可以自动蒸发掉一滴水，用烘干机烘衣服时不蒸发。问最少需要多少时间能烘干所有的衣服。
分析：二分答案，对于每一件衣服，若小于枚举的答案则跳过，若大于，则要先烘干，烘干的同时其余的衣服也在蒸发，所以烘干时间是(a[i]-val)/(k-1)上取整 
	  因为要去掉原本蒸发的量，注意k=1的情况 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int a[MAXN+3],k,n,mx=0;
bool check(int val){
	int sum=0;
	for(int i=1;i<=n&&sum<=val;i++){
		if(a[i]<=val)continue;
		sum+=ceil((a[i]-val)*1.0/(k-1));
	}
	return sum<=val;
}
int ef(int l,int r){
	int mid,ans=l;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	return l;
}
int solve(){
	if(k==1)return mx;
	else{
		return ef(1,mx);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	scanf("%d",&k);
	printf("%d\n",solve());
	return 0;
}

