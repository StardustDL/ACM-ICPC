/*
Monthly Expense
题意：一列数，分成M份，MIN{MAX{每份中数的和}} 
分析：二分答案，但是二分写错了。。。学到了一个新的二分法 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,m,a[MAXN+3];
bool check(int v){
	int cur=1,s=0;
	for(int i=1;i<=n;i++){
		if(s+a[i]<=v)s+=a[i];
		else{
			s=a[i];cur++;
		}
	}
	return cur<=m;
}
int ef(int l,int r){
	int mid=(l+r)>>1;
	while(l<r){
		if(!check(mid)){
			l=mid+1;//此处有没有可能丢掉mid这个解 
		}
		else r=mid-1;
		mid=(l+r)>>1;//后计算中间值 
	}
	return mid;
}
int main(){
	scanf("%d%d",&n,&m);
	int low=0,high=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		low=max(low,a[i]);
		high+=a[i];
	}
	printf("%d",ef(low,high));
	return 0;
}

