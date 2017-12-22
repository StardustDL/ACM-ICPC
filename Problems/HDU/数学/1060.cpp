/*
Leftmost Digit
题意：输入N，求N^N的最高位数字。1<=N<=1,000,000,000
分析：令N^N=a*10^x,x=[lg(N^N)],取log
	  lg(N^N)=lg(a*10^x)
	  =>N*lg(N)=lg(a)+x
	  =>a=10^(N*lg(N)-x)
	  =>a=10^(N*lg(N)-[lg(N^N)])
	  ans=[a]
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int main(){
	int T,n;scanf("%d",&T);
	double k;
	while(T--){
		scanf("%d",&n);
		k=n*log10(n);
		k-=floor(k);
		printf("%d\n",(int)(pow(10,k)));
	}
	return 0;
}

