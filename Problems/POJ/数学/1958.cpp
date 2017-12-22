/*
题意：4柱子hanoi，给出n<=12，求最少步数。
分析：3柱子的hanoi，步数＝2^n-1。题中给出四个的解题思路，用dp求解，题中说先把n分成两部分，A部分用4柱子方法挪到2柱子，B部分用3柱子法挪到4柱子，然后用4柱子法把A挪到4柱子。假设B部分有k个，则g[i] = g[i - j] * 2 + f[j];
	  g[i]表示4柱子法，f[i]是3柱子法，挪动i个盘子的步数。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int g[15]={0},f[15];
int main(){
	f[0]=g[0]=0;
	for(int i=1;i<=12;i++)f[i]=(1<<i)-1;
	for(int i=1;i<=12;i++){
		g[i]=INF;
		for(int j=0;j<=i;j++)g[i]=min(g[i],(g[i-j]<<1)+f[j]);
		printf("%d\n",g[i]);
	}
	return 0;
}

