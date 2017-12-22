/*
Cat
题意：把一堆浮点数分成两部分，要使得两部分的差值尽量小，小于总大小的2%
分析：由于有2%的限制，将浮点数转成百分比，再同时扩大10000倍，就转成背包问题：判定分成两部分，其中有一部分大小=i的方案是否存在
	  最后枚举i，另一部分一定约等于i，这样找到min{sumw-2*i|opt[i]}的i，注意DP时记录方案 
	  输出时沿着方案走即可 
	  注意：此题用bitset实现会超时，要采用bool数组 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXM=30000,MAXN=200;
const double POW=10000.0;
int last[MAXM+3],n,w[MAXN+3],mw;
//bitset<MAXM+3> opt;
bool opt[MAXM+3];
double sum,a[MAXN+3];
bool input(){
	scanf("%d",&n);
	if(n==0)return false;
	sum=0;mw=0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		w[i]=int(a[i]*POW/sum);
		mw+=w[i];
	}
	return true;
}
int dp(){
	memset(last,0,sizeof(last));
	//opt=0;opt[0]=1;
	memset(opt,0,sizeof(opt));opt[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=mw;j>=w[i];j--){
			if(!opt[j]&&opt[j-w[i]]){
				opt[j]=1;last[j]=i;
			}
		}
	}
	int ans=INF,rel=0;
	for(int i=1;i<=mw;i++){
		if(opt[i]&&abs(mw-(i<<1))<ans){
			ans=abs(mw-(i<<1));
			rel=i;
		}
	}
	return rel;
}
void output(int x){
	if(!x)return;
	output(x-w[last[x]]);
	printf("%d ",last[x]);
}
int main(){
	while(input()){
		output(dp());
		puts("");
	}
	return 0;
}

