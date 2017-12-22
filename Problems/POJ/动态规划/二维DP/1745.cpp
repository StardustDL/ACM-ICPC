/*
Divisibility
题目：给你n个整数，和一个k值（2<=k<=100)，问在这n个数之间的n-1的位置任意放加减号，问有没有一种情况使结果整除k。 
分析：典型dp。
    	dp[i][j]=dp[i-1][j-a[i]]||dp[i-1][j+a[i]];
	  当然要考虑余数为负数的情况。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#define convert(v,x) tmp=x;while(tmp<0)tmp+=k;v=tmp%k;
#define read(v) scanf("%d",&tmp);while(tmp<0)tmp+=k;v=tmp%k;
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
const char OUT[2][20]={"Not divisible","Divisible"};
bitset<MAXN+3> can[2];
int n,k,x,tmp,cur=0,s,t;
int main(){
	scanf("%d%d",&n,&k);
	read(x);
	can[cur][x]=1;
	for(int i=2;i<=n;i++,cur^=1){
		can[cur^1]=0;
		read(x);
		for(int j=0;j<k;j++){
			convert(s,j-x);
			convert(t,j+x);
			can[cur^1][j]=can[cur][s]||can[cur][t];
		}
	}
	puts(OUT[can[cur][0]]);
	return 0;
}

