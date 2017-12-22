/*
World Cup Noise
题意：求出长度为n的01串中，不出现连续1的串的个数
分析：答案=最后一位为0的数字个数加上最后一位为1的数字个数，
	  而当前一位要产生1，前一位最后只能是0，当前一位要产生0，前一位最后可以为 1，也可以为0。
	  设O[i]、Z[i]分别表示i位数的最后一位为0的数和最后一位为1的数，f[i]表示i位数的总数，则f[i] = O[i] + Z[i]。又由以上分析，O[k] = Z[k-1] = O[k-2] + Z[k-2] = f[k-2], Z[k] = O[k-1] + Z[k-1] = f[k-1], So f[k] = O[k] + Z[k] = f[k-1] + f[k-2]。
	  这不就是斐波拉契数列吗？f[1] = 2, f[2] = 3, f[k] = f[k-1] + f[k-2]。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=45;
int fib[MAXN+3],n,T;
int main(){
	fib[0]=1;fib[1]=2;
	for(int i=2;i<=MAXN;i++)fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&T);
	for(int i=1;i<=T;i++){scanf("%d",&n);printf("Scenario #%d:\n%d\n\n",i,fib[n]);}
	return 0;
}

