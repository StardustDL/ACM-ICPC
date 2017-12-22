/*
[HAOI2009]逆序对数列
分析：f[i][j]表示只由前1~i个自然数组成的序列中，逆序对个数为j的方案数。
		考虑如何从f[i-1]转移到f[i]，f[i-1]表示一个只包含1~i-1的数列，现在我们加入一个新数i，显然原数列中所有数都比i小，所以i插入的位置就决定了它增加的逆序对个数。
		f[i][j]=sigma{f[i-1][k]|k=[0..min(i-1,j)]}，前缀和优化 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=10000;
int f[MAXN+3],g[MAXN+3],n,K;
int main(){
	scanf("%d%d",&n,&K);
	g[0]=1;for(int j=1;j<=K;j++)g[j]=g[j-1]+f[j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=K;j++)
			f[j]=((g[j]-g[j-min(i-1,j)-1])%MOD+MOD)%MOD;
		for(int j=1;j<=K;j++)g[j]=(g[j-1]+f[j])%MOD;
	}
	printf("%d\n",f[K]);
	return 0;
}

